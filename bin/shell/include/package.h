#ifndef JSPACKAGE
#define JSPACKAGE
#include "defs.h"



v8::Local<v8::String> readfile(FILE *file,v8::Isolate *isolate);

class PackageManager
{
public:
static v8::Local<v8::ObjectTemplate> packagemanagerobjt;


static  void package(const v8::FunctionCallbackInfo<v8::Value> & args);
static void find(const v8::FunctionCallbackInfo<v8::Value> & args);


static v8::Local<v8::ObjectTemplate> makepackagemanagerobjt(v8::Isolate *iso);


};

#endif