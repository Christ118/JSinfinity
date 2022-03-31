#ifndef JSIO
#define JSIO
#include "defs.h"


v8::Local<v8::String> readfile(FILE *file,v8::Isolate *isolate);

class Io
{
public:
static v8::Local<v8::ObjectTemplate> fileobjT;

static  void Open(const v8::FunctionCallbackInfo<v8::Value> & args);
static void Read(const v8::FunctionCallbackInfo<v8::Value> & args);
static void Run(const v8::FunctionCallbackInfo<v8::Value> & args);

static void print(const v8::FunctionCallbackInfo<v8::Value> & args);
static void input(const v8::FunctionCallbackInfo<v8::Value> & args);

static v8::Local<v8::ObjectTemplate> makefileobjt(v8::Isolate *iso);


};

#endif