/*
js infinity  made by  elodream   
*/

#include"../include/system.h"
#include"../include/io.h"
#include"../include/package.h"


HANDLE stdconsole=GetStdHandle(STD_OUTPUT_HANDLE);

struct
{
bool __result=true;
bool __color=true;//this  option color  the console 
bool __packages=true;//this option allow package use 
bool __console=true;
bool __working_dir_file=false;
}options;



void print_advice(std::string  str,short code)
{

  std::string codestr;
  switch (code)
  {
  case ERR_PRINT:
  SetConsoleTextAttribute(stdconsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
  codestr="ERROR:";
  break;
  case WARN_PRINT:
  SetConsoleTextAttribute(stdconsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
  codestr="WARNING:";
  break;
  case SUCESS_PRINT:
  SetConsoleTextAttribute(stdconsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
  
  }
  str=codestr.append(str)+"\n";
  FILE * f=fopen(JI_PATH"/logs.txt","w+") ;
  fputs(str.c_str(),stdout);
  fputs(str.c_str(),f);
  fclose(f);


}
/* 
this function  create the context of  js 
------------------@elodream---------------------
*/
v8::Local<v8::Context> fulljscontext(v8::Isolate *iso)
{
  v8::Local<v8::ObjectTemplate>  global = v8::ObjectTemplate::New(iso);
  global->Set(iso,"Sys",System::makesystemobjt(iso));
  global->Set(iso,"File",Io::makefileobjt(iso));
  global->Set(iso,"open",v8::FunctionTemplate::New(iso,Io::Open));
  
  global->Set(iso,"print",v8::FunctionTemplate::New(iso,Io::print));
  global->Set(iso,"input",v8::FunctionTemplate::New(iso,Io::input));
 global->Set(iso,"package",v8::FunctionTemplate::New(iso,PackageManager::package));
  
  return v8::Context::New(iso,NULL,global);
}

/* 
this  function report error in  your javascript  programs
------------------@elodream---------------------
*/
void ReportException(v8::Isolate* isolate, v8::TryCatch* try_catch) {
  SetConsoleTextAttribute(stdconsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
  v8::HandleScope handle_scope(isolate);
  v8::String::Utf8Value exception(isolate, try_catch->Exception());
  const char* exception_string = *exception;
  v8::Local<v8::Message> message = try_catch->Message();
  if (message.IsEmpty()) 
  {
    fwprintf(stderr, L"%s\n", exception_string);
  } 
  else 
  {
    v8::String::Utf8Value source(isolate, message->GetScriptOrigin().ResourceName());
    v8::Local<v8::Context> context(isolate->GetCurrentContext());
    int linenum = message->GetLineNumber(context).FromJust();
    fwprintf(stderr, L"error in %s  column:%d ", *source,message->GetEndColumn());

    fwprintf(stderr,L"%s\n",exception_string);
    // Print line of source code.
    v8::String::Utf8Value sourceline(isolate, message->GetSourceLine(context).ToLocalChecked());
    const char* sourceline_string = *sourceline;

    fwprintf(stderr, L"%s\n", sourceline_string);
   
    int start = message->GetStartColumn(context).FromJust();
    for (int i = 0; i < start; i++) 
    {
      fprintf(stderr, " ");
    }
    int end = message->GetEndColumn(context).FromJust();
    for (int i = start; i < end; i++) 
    {
      fprintf(stderr, "^");
    }
    fprintf(stderr, "\n");
    if(std::string(*source)!=std::string("(shell)"))
    {
      v8::Local<v8::Value> stack_trace_string;
    if (try_catch->StackTrace(context).ToLocal(&stack_trace_string) &&stack_trace_string->IsString() &&stack_trace_string.As<v8::String>()->Length() > 0) 
    {
      v8::String::Utf8Value stack_trace(isolate, stack_trace_string);
      const char* err = *stack_trace;
      fprintf(stderr, "%s\n", err);
    }
    }
    
  }
}

/* 
this  function  run   a script js
------------------@elodream---------------------
*/
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

      
      SetConsoleTextAttribute(stdconsole,FOREGROUND_GREEN|FOREGROUND_INTENSITY) ;    
      wprintf(L"%s\n",*res);
    }
    else 
    {
      SetConsoleTextAttribute(stdconsole,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY) ;

      wprintf(L"%s\n",*res);
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

std::cout<<"JS shell made by elodream  by  elodream using c++ with (v8 "<< v8::V8::GetVersion()<<") and GTK+ copyright 2022 \nall right reserved please support us"<<std::endl;
v8::Local<v8::String> name( v8::String::NewFromUtf8Literal(context->GetIsolate(), "(shell)"));
  
while(true)
{

char buffer[280];
SetConsoleTextAttribute(stdconsole,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY) ;
printf(">");

char* str = fgets(buffer, 280, stdin);

if (std::string(str) =="\n")continue;

v8::HandleScope handle_scope(context->GetIsolate());
executejs(context->GetIsolate(),v8::String::NewFromUtf8(context->GetIsolate(),str).ToLocalChecked(),name);
while (v8::platform::PumpMessageLoop(platform, context->GetIsolate()))
      continue;
}
printf("\n");
}



void RunMain(v8::Isolate* iso, v8::Platform* platform, int argc,char* argv[]) {

        std::string h=argv[1];
        for(int i=1;i<argc;i++)
        {
          std::string arg(argv[i]);
          if(arg=="--noresult")
            options.__result=true;
          else if(arg=="--noconsole")
            options.__console=false;
          else if(arg=="--colored")
          options.__color=true;
          else if(arg=="--nocolored")
          options.__color=false;
          else if(arg=="--no-use-package")
          options.__packages=false;
        
        }
        SetConsoleTextAttribute(stdconsole,FOREGROUND_INTENSITY) ;
        FILE *f=fopen(argv[1],"rb");
        executejs(iso,readfile(f,iso),v8::String::NewFromUtf8(iso,h.c_str()).ToLocalChecked()); 
        SetConsoleTextAttribute(stdconsole,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY) ;       
  

}



//the main function  
int main (int argc ,char *argv[])
{
  SetConsoleOutputCP(CP_UTF8);
  v8::V8::InitializeICUDefaultLocation(argv[0]);
  v8::V8::InitializeExternalStartupData(argv[0]);
  SetConsoleTitle("JSinfinity");
  

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


