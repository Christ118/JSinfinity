
#include<gtkmm-3.0/gtkmm.h>
#include"../include/system.h"
#include"../include/gui.h"
#include<windows.h>
 auto console=GetStdHandle(STD_OUTPUT_HANDLE);
v8::Local<v8::ObjectTemplate> fileobjT;
void Version(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  std::cout<<VERSION<<std::endl;
}

void file(const v8::FunctionCallbackInfo<v8::Value> & args)
{int id=args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
int c=args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust();
v8::String::Utf8Value path (args.GetIsolate(),args[0]);
File * p = new File(*path);
v8::Local<v8::Object> o= fileobjT->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
 o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);
}

/* 

this function  create the context of  js 
*/
v8::Local<v8::Context> fulljscontext(v8::Isolate *iso)
{
  v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(iso);
  fileobjT = v8::ObjectTemplate::New(iso);
  fileobjT->SetInternalFieldCount(1);
  global->Set(iso,"version",v8::FunctionTemplate::New(iso,Version));
  global->Set(iso,"print",v8::FunctionTemplate::New(iso,print));
  global->Set(iso,"input",v8::FunctionTemplate::New(iso,input));
  global->Set(iso,"file",v8::FunctionTemplate::New(iso,file));
  global->Set(iso,"window",v8::FunctionTemplate::New(iso,Window::newWindow));
  global->Set(iso,"cmd",v8::FunctionTemplate::New(iso,systemcmd));
  global->Set(iso,"File",fileobjT);
  global->Set(iso,"Window",Window::makeWindowobjt(iso));
  fileobjT->SetAccessor(v8::String::NewFromUtf8Literal(iso,"id"),File::Getid);
  fileobjT->Set(iso,"open",v8::FunctionTemplate::New(iso,File::Open));
  fileobjT->Set(iso,"read",v8::FunctionTemplate::New(iso,File::Read));
  fileobjT->Set(iso,"run",v8::FunctionTemplate::New(iso,File::Run));
  return v8::Context::New(iso,NULL,global);
}

void ReportException(v8::Isolate* isolate, v8::TryCatch* try_catch) {
  SetConsoleTextAttribute(console, FOREGROUND_RED|FOREGROUND_INTENSITY);
  v8::HandleScope handle_scope(isolate);
  v8::String::Utf8Value exception(isolate, try_catch->Exception());
  const char* exception_string = *exception;
  v8::Local<v8::Message> message = try_catch->Message();
  if (message.IsEmpty()) {
    // V8 didn't provide any extra information about this error; just
    // print the exception.
    fprintf(stderr, "%s\n", exception_string);
  } else {
    // Print (filename):(line number): (message).
    v8::String::Utf8Value filename(isolate,
                                   message->GetScriptOrigin().ResourceName());
    v8::Local<v8::Context> context(isolate->GetCurrentContext());
    const char* filename_string = *filename;
    int linenum = message->GetLineNumber(context).FromJust();
    fprintf(stderr, "%s:%i: %s\n", filename_string, linenum, exception_string);
    // Print line of source code.
    v8::String::Utf8Value sourceline(
        isolate, message->GetSourceLine(context).ToLocalChecked());
    const char* sourceline_string = *sourceline;
    fprintf(stderr, "%s\n", sourceline_string);
    // Print wavy underline (GetUnderline is deprecated).
    int start = message->GetStartColumn(context).FromJust();
    for (int i = 0; i < start; i++) {
      fprintf(stderr, " ");
    }
    int end = message->GetEndColumn(context).FromJust();
    for (int i = start; i < end; i++) {
      fprintf(stderr, "^");
    }
    fprintf(stderr, "\n");
    v8::Local<v8::Value> stack_trace_string;
    if (try_catch->StackTrace(context).ToLocal(&stack_trace_string) &&
        stack_trace_string->IsString() &&
        stack_trace_string.As<v8::String>()->Length() > 0) {
      v8::String::Utf8Value stack_trace(isolate, stack_trace_string);
      const char* err = *stack_trace;
      fprintf(stderr, "%s\n", err);
    }
  }
}

bool executejs(v8::Isolate *iso,v8::Local<v8::String> source,v8::Local<v8::String>name)
{
  v8::HandleScope handle_scope(iso);
  v8::Local<v8::Context> context(iso->GetCurrentContext());
  v8::TryCatch try_catch(iso);
  v8::Local<v8::Script> script;
  v8::ScriptOrigin origin(iso,name);

  if(!v8::Script::Compile(context,source,&origin).ToLocal(&script))
  {
    ReportException(iso, &try_catch);
    return false;
    
  }
  else
  {
    v8::Local<v8::Value> result;

    if (!script->Run(context).ToLocal(&result)) {
      assert(try_catch.HasCaught());
      ReportException(iso, &try_catch);
      return 0;
    }
    else
    {
   
    v8::String::Utf8Value res(iso,result);
    if (!result->IsNullOrUndefined())
    {
      
      SetConsoleTextAttribute(console,FOREGROUND_GREEN|FOREGROUND_INTENSITY) ;

      printf("%s\n",*res);
    }
        
  }
  return true;

    }
    
}

/*
 this function launch the  shell
*/
void jsshell(v8::Local<v8::Context> context , v8::Platform *platform)
{
SetConsoleTextAttribute(console, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
std::cout<<"JS shell made by elodream  by  elodream with(v8 "<< v8::V8::GetVersion()<<") copyright 2022 \nall right reserved pleaze support us"<<std::endl;
v8::Local<v8::String> name( v8::String::NewFromUtf8Literal(context->GetIsolate(), "(shell)"));

   
  
while(true)
{
SetConsoleTextAttribute(console,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY) ;
char buffer[280];

printf(">>>");
char* str = fgets(buffer, 280, stdin);

v8::HandleScope handle_scope(context->GetIsolate());
executejs(context->GetIsolate(),v8::String::NewFromUtf8(context->GetIsolate(),str).ToLocalChecked(),name);

}
printf("\n");
}

void RunMain(v8::Isolate* iso, v8::Platform* platform, int argc,
            char* argv[]) {

              std::string h=argv[1];
               SetConsoleTextAttribute(console,FOREGROUND_INTENSITY) ;
              FILE *f=fopen(argv[1],"rb");
            executejs(iso,readfile(f,iso),v8::String::NewFromUtf8(iso,h.c_str()).ToLocalChecked());
            
          
  
}



//the main function  
int main (int argc ,char *argv[])
{
  int argn=1;
  Window::app = Gtk::Application::create(argn, argv);

  v8::V8::InitializeICUDefaultLocation(argv[0]);
  v8::V8::InitializeExternalStartupData(argv[0]);
  std::unique_ptr<v8::Platform> platform=v8::platform::NewDefaultPlatform();
  v8::V8::InitializePlatform(platform.get());

  #ifdef V8_SANDBOX
  if (!v8::V8::InitializeSandbox()) {
    fprintf(stderr, "Error initializing the V8 sandbox\n");
    return 1;
  }
#endif
v8::V8::Initialize();
v8::V8::SetFlagsFromCommandLine(&argc, argv, true);



  v8::Isolate::CreateParams create_params;
  create_params.array_buffer_allocator =v8::ArrayBuffer::Allocator::NewDefaultAllocator();
  v8::Isolate* isolate = v8::Isolate::New(create_params);
  {
  v8::Isolate::Scope isolate_scope(isolate);
  v8::HandleScope handle_scope(isolate);  
  v8::Local<v8::Context> context = fulljscontext(isolate);
  if (context.IsEmpty()) {
      fprintf(stderr, "Error creating context\n");
      return 1;
      }
  
  v8::Context::Scope context_scope(context);
  //start shell 
  
  if(argc==1)
  jsshell(context,platform.get());
  else
  RunMain(isolate,platform.get(),argc,argv);
  }
   isolate->Dispose();
   v8::V8::Dispose();
 
  return  0;

}