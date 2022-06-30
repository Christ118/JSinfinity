#include"../include/io.h"
v8::Local<v8::ObjectTemplate> Io::fileobjT;
void Io::print(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    for(int i=0 ;i<args.Length();i++)
    {
        v8::String::Utf8Value str (args.GetIsolate(),args[i]);
        wprintf(L"%s",*str);
        
    }
   printf("\n");
}



void Io::input(const v8::FunctionCallbackInfo<v8::Value> & args)
{
      for(int i=0 ;i<args.Length();i++)
    {
        v8::String::Utf8Value str (args.GetIsolate(),args[i]);
        printf("%s",*str);
    }
    char buffer[250];
    char* str = fgets(buffer, 250, stdin);
    std::string v=str;
    v.pop_back();
    v8::Local<v8::String> a= v8::String::NewFromUtf8(args.GetIsolate(),v.c_str()).ToLocalChecked();
    args.GetReturnValue().Set(a);

}


FILE * getfile(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<FILE*>(ptr);
}


void Io::Open(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    v8::String::Utf8Value path(args.GetIsolate(),args[0]);
    v8::String::Utf8Value mode(args.GetIsolate(),args[1]);
    FILE *p=fopen(*path,*mode);
    v8::Local<v8::Object> o= Io::fileobjT->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

    o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
    args.GetReturnValue().Set(o);

}
void Io::Read(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    
    FILE *file=getfile(args.Holder());
     fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    std::string str;
    char c;
    do
    {
        c=getc(file);
        if(c!=EOF)
        str+=c;
    } while (c!=EOF);
    
    args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(),str.c_str()).ToLocalChecked());
}

v8::Local<v8::String> readfile(FILE *file,v8::Isolate *isolate)
{
   std::string str;
    char c;
    do
    {
        c=getc(file);
        if(c!=EOF)
        str+=c;
    } while (c!=EOF);
    return v8::String::NewFromUtf8(isolate,str.c_str()).ToLocalChecked();
 
}

void Io::Run(const v8::FunctionCallbackInfo<v8::Value> & args)
{
     FILE *p=getfile(args.Holder());
   executejs(args.GetIsolate(),readfile(p,args.GetIsolate()),v8::String::NewFromUtf8(args.GetIsolate(),"ki").ToLocalChecked());
   fclose(p);
}

v8::Local<v8::ObjectTemplate> Io::makefileobjt(v8::Isolate *iso)
{
    fileobjT= v8::ObjectTemplate::New(iso);
    fileobjT->SetInternalFieldCount(1);
    fileobjT->Set(iso,"read",v8::FunctionTemplate::New(iso,Io::Read));
    fileobjT->Set(iso,"run",v8::FunctionTemplate::New(iso,Io::Run));
    return fileobjT;
}