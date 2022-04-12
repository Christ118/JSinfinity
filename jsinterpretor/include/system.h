#ifndef JSSYSTEM
#define JSSYSTEM
#include "defs.h"
#include"stdlib.h"



class System
{
public:
static void systemcmd(const v8::FunctionCallbackInfo<v8::Value> & args);
static void version(const v8::FunctionCallbackInfo<v8::Value> & args);
static void quit(const v8::FunctionCallbackInfo<v8::Value> &args);
static void shutdownsystem(const v8::FunctionCallbackInfo<v8::Value> &args);
static void rebootsystem(const v8::FunctionCallbackInfo<v8::Value> &args);

static v8::Local<v8::ObjectTemplate> systemobjt;
static v8::Local<v8::ObjectTemplate> system_infoobjt;

 static v8::Local<v8::ObjectTemplate>  makesystemobjt(v8::Isolate *isolate);
static v8::Local<v8::ObjectTemplate>  makesystem_info(v8::Isolate *isolate);


};

#endif