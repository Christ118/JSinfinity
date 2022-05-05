
#include"../include/system.h"

v8::Local<v8::ObjectTemplate> System::sysobjt;
v8::Local<v8::ObjectTemplate> System::dirobjT;


DIR * getdir(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<DIR*>(ptr);
}


void System::opendirec(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  v8::String::Utf8Value path(args.GetIsolate(),args[0]);
   DIR* dir=opendir(*path);
      v8::Local<v8::Object> o= dirobjT->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

    o->SetInternalField(0,v8::External::New(args.GetIsolate(),dir));
    args.GetReturnValue().Set(o);

}

void System::getdirname(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info)
{
  DIR *p=getdir(info.Holder());
std::string title=p->dd_name;

info.GetReturnValue().Set(v8::String::NewFromUtf8(info.GetIsolate(),title.c_str()).ToLocalChecked());
}

void System::getnextdir(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info)
{
  DIR *p=getdir(info.Holder());
 
  dirent * next ;
  while ((next=readdir(p))!=NULL)
  {

  if(strchr(next->d_name,'.')==NULL)
  {
    DIR* dir=opendir(next->d_name);
    v8::Local<v8::Object> o= dirobjT->NewInstance(info.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    o->SetInternalField(0,v8::External::New(info.GetIsolate(),dir));
    info.GetReturnValue().Set(o);
    return;
  } 
  }
    info.GetReturnValue().Set(v8::Boolean::New(info.GetIsolate(),false));

}


void System::getdircontains(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info)
{
  DIR *p=getdir(info.Holder());
  v8::Isolate * iso=info.GetIsolate();
  dirent * next ;
  v8::Local<v8::Array> list=v8::Array::New(iso);
  int i=0;
  while ((next=readdir(p))!=NULL)
  {

  if(strchr(next->d_name,'.')==NULL)
  {
    DIR* dir=opendir(next->d_name);
    v8::Local<v8::Object> o= dirobjT->NewInstance(iso->GetCurrentContext()).ToLocalChecked();
    o->SetInternalField(0,v8::External::New(iso,dir));
    auto r=list->Set(iso->GetCurrentContext(),i++,o);
  } 
  }
    info.GetReturnValue().Set(list);

}




void System::createfolder(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  v8::String::Utf8Value path (args.GetIsolate(),args[0]);
 mkdir(*path);
  opendirec(args);
}



void System::systemcmd(const v8::FunctionCallbackInfo<v8::Value> & args)
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

void System::version(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  std::cout<<VERSION<<std::endl;
}



void System::shutdownsystem(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  InitiateShutdownA(NULL,NULL,0,SHUTDOWN_NOREBOOT,0);
}

void System::rebootsystem(const v8::FunctionCallbackInfo<v8::Value> &args)
{
 InitiateShutdownA(NULL,NULL,0,SHUTDOWN_RESTART,0);
 }

void System::getsysteminf(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  v8::Isolate *iso=args.GetIsolate();
 v8::Local<v8::Map> info=v8::Map::New(args.GetIsolate());
 SYSTEM_INFO inf;
 GetSystemInfo(&inf);
 
 
 info->Set(iso->GetCurrentContext(),v8::String::NewFromUtf8(iso,"ProcessorNumber").ToLocalChecked(), v8::Integer::New(iso,inf.dwNumberOfProcessors)).ToLocalChecked();
 args.GetReturnValue().Set(info);
 }
void System::quit(const v8::FunctionCallbackInfo<v8::Value> &args)
{
exit(0);
}


v8::Local<v8::ObjectTemplate> System::makedirobjt(v8::Isolate *iso)
{
    dirobjT= v8::ObjectTemplate::New(iso);
    dirobjT->SetAccessor(v8::String::NewFromUtf8Literal(iso,"name"),getdirname);
    dirobjT->SetAccessor(v8::String::NewFromUtf8Literal(iso,"nextdir"),getnextdir);
    dirobjT->SetAccessor(v8::String::NewFromUtf8Literal(iso,"contains"),getdircontains);

    dirobjT->Set(iso,"create",v8::FunctionTemplate::New(iso,createfolder));


    dirobjT->SetInternalFieldCount(1);
    
    return dirobjT;
}
v8::Local<v8::ObjectTemplate> System::makesystemobjt(v8::Isolate *iso)
{
    sysobjt = v8::ObjectTemplate::New(iso);
    sysobjt->Set(iso,"version",v8::FunctionTemplate::New(iso,version));
    sysobjt->Set(iso,"reboot",v8::FunctionTemplate::New(iso,rebootsystem));
    sysobjt->Set(iso,"shutdown",v8::FunctionTemplate::New(iso,shutdownsystem));
    sysobjt->Set(iso,"dir",v8::FunctionTemplate::New(iso,opendirec));

    sysobjt->Set(iso,"Dir",makedirobjt(iso));
    sysobjt->Set(iso,"cmd",v8::FunctionTemplate::New(iso,systemcmd));

  
 
    return sysobjt;
}


