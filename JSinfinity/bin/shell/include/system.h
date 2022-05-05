#ifndef JSSYSTEM
#define JSSYSTEM
#include "defs.h"
#include"stdlib.h"
#include<dirent.h>


class System
{
public:
static void systemcmd(const v8::FunctionCallbackInfo<v8::Value> & args);
static void opendirec(const v8::FunctionCallbackInfo<v8::Value> & args);
static void version(const v8::FunctionCallbackInfo<v8::Value> & args);
static void quit(const v8::FunctionCallbackInfo<v8::Value> &args);
static void shutdownsystem(const v8::FunctionCallbackInfo<v8::Value> &args);
static void rebootsystem(const v8::FunctionCallbackInfo<v8::Value> &args);
static void getsysteminf(const v8::FunctionCallbackInfo<v8::Value> &args);
static void createfolder(const v8::FunctionCallbackInfo<v8::Value> & args);


static v8::Local<v8::ObjectTemplate> sysobjt;
static v8::Local<v8::ObjectTemplate> system_infoobjt;
static v8::Local<v8::ObjectTemplate> dirobjT;

 static v8::Local<v8::ObjectTemplate>  makesystemobjt(v8::Isolate *isolate);
static v8::Local<v8::ObjectTemplate>  makesystem_info(v8::Isolate *isolate);
static v8::Local<v8::ObjectTemplate> makedirobjt(v8::Isolate *iso);

static void getdirname(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);
static void getnextdir(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);
static void getdircontains(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);




};

#endif