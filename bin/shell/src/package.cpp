/*
its posible  to  extend  js infinity fontionnality  by  creating package and
every devellopper can   create package  with his own  programming language 
------------------@elodream---------------------
*/
#include"../include/package.h"

v8::Local<v8::ObjectTemplate> PackageManager::packagemanagerobjt;

typedef v8::Local<v8::ObjectTemplate>(__stdcall *pFunc)(v8::Isolate*,char**,int);
typedef void(__stdcall *Func)(void);
pFunc initfunc;

void loadpackwithdll(const v8::FunctionCallbackInfo<v8::Value> & args,std::string path)
{ 
v8::Isolate *iso=args.GetIsolate();
HMODULE packdll =LoadLibrary(path.c_str()); 
if(packdll==NULL)
{
  printf("%d",GetLastError());
  if(GetLastError()!=122)
    print_advice("error while reading dll ");
 

}
else
{

initfunc = (pFunc)GetProcAddress(packdll, "_Z16__INIT_PACKAGE__PN2v87IsolateE");
initfunc = (initfunc)?initfunc:(pFunc)GetProcAddress(packdll, "__INIT_PACKAGE__");
initfunc = (initfunc)?initfunc:(pFunc)GetProcAddress(packdll, "__INIT_PACK__");
initfunc = (initfunc)?initfunc:(pFunc)GetProcAddress(packdll, "__INIT__");
initfunc = (initfunc)?initfunc:(pFunc)GetProcAddress(packdll, "__init__");
initfunc = (initfunc)?initfunc:(pFunc)GetProcAddress(packdll, "init");

if(initfunc==NULL)
{
  printf("%d",GetLastError());
  print_advice("init function not found");
}
else
{
 auto r=initfunc(iso,__argv,__argc);
 args.GetReturnValue().Set(r->NewInstance(iso->GetCurrentContext()).ToLocalChecked());
}
}
}

void loadpackwithpy(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    
}
/*
this function load package using  javascript programming 
*/
void loadpackwithjs(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    
}

void loadpackwithruby(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    
}

/*
this function load package using perl programming  language
*/
void loadpackwithperl(const v8::FunctionCallbackInfo<v8::Value> & args)
{
    
}


void PackageManager::package(const v8::FunctionCallbackInfo<v8::Value> & args)
{
v8::Isolate *iso=args.GetIsolate();
v8::String::Utf8Value packagename(iso,args[0]);
std::string path=std::string( PACKAGE_PATH) +*packagename+"/";

SetDllDirectory(std::string(path+"bin").c_str());
print_advice(path);
DIR* dir=opendir(path.c_str());
dirent * next;

int nbrinit=0;
int nbrvalidinit=0;

if(dir)
while(next=readdir(dir))
{
  std::string fpath=path;
FILE * f=fopen(fpath.append(next->d_name).c_str(),"r");

  if(f)
  {
    fclose(f);
    std::string ext=fpath.substr(fpath.find_last_of('.'));
    std::string fname =fpath.substr(fpath.find_last_of('/')+1,fpath.find_last_of('.'));
    fname=fname.substr(0,8);
    
if(fname=="__init__")
{
  nbrinit++;
if(ext==".dll")
{
loadpackwithdll(args,fpath);
}
else if(ext==".py")
{

}
else if(ext==".js")
{

}
else
{
  print_advice("unavailable to use this package initializer ");
}

}

  }

}

if(!nbrinit)
print_advice("there is no package initializer");

}


 v8::Local<v8::ObjectTemplate> PackageManager::makepackagemanagerobjt(v8::Isolate *iso)
 {
  packagemanagerobjt= v8::ObjectTemplate::New(iso);

  packagemanagerobjt->Set(iso,"package",v8::FunctionTemplate::New(iso,package));
   
  return packagemanagerobjt;
 }