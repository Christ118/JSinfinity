
#include"../include/system.h"

int File::nbr=0;

void print(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    for(int i=0 ;i<args.Length();i++)
    {
        v8::String::Utf8Value str (args.GetIsolate(),args[i]);
        printf("%s \n",*str);
    }
}



void input(const v8::FunctionCallbackInfo<v8::Value> & args)
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

void systemcmd(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    std::string a;
    for(int i=0;i<args.Length();i++)
    {
        v8::String::Utf8Value str(args.GetIsolate(),args[0]);
        a+="";
        a+=*str;
    }
system(a.c_str());

}



File * getfile(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<File*>(ptr);
}


void File::Getid(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{ 
 File *p=getfile(info.Holder());
info.GetReturnValue().Set(v8::Int32::New(info.GetIsolate(),p->id));

}

File::File(std::string path,std::string mod)
{
    f=fopen(path.c_str(),mod.c_str());
    id=++nbr;
    
}

void File::Open(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    File *p=getfile(args.Holder());
    v8::String::Utf8Value path(args.GetIsolate(),args[0]);
    v8::String::Utf8Value mode(args.GetIsolate(),args[1]);
    p->f=fopen(*path,*mode);
    args.GetReturnValue().Set(args.Holder());
}
void File::Read(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    
    File *p=getfile(args.Holder());
    v8::String::Utf8Value path(args.GetIsolate(),args[0]);
    FILE *file=p->f;
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

void File::Run(const v8::FunctionCallbackInfo<v8::Value> & args)
{
     File *p=getfile(args.Holder());
   executejs(args.GetIsolate(),readfile(p->f,args.GetIsolate()),v8::String::NewFromUtf8(args.GetIsolate(),"ki").ToLocalChecked());
   fclose(p->f);
}