
#include"../include/system.h"


#include"../include/system.h"
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
  ExitWindowsEx(EWX_SHUTDOWN,0);
}

void System::rebootsystem(const v8::FunctionCallbackInfo<v8::Value> &args)
{
  ExitWindowsEx(EWX_REBOOT,0);
}

void System::quit(const v8::FunctionCallbackInfo<v8::Value> &args)
{
exit(0);

}



