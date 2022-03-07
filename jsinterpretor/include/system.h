#ifndef jssystem
#define jssystem
#include "defs.h"
void print(const v8::FunctionCallbackInfo<v8::Value> & args);
void input(const v8::FunctionCallbackInfo<v8::Value> & args);
void systemcmd(const v8::FunctionCallbackInfo<v8::Value> & args);
v8::Local<v8::String> readfile(FILE *file,v8::Isolate *isolate);

class File
{
public:
static void Getid(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info);
static  void Open(const v8::FunctionCallbackInfo<v8::Value> & args);
static void Read(const v8::FunctionCallbackInfo<v8::Value> & args);
static void Run(const v8::FunctionCallbackInfo<v8::Value> & args);

static int nbr;
int id; 
int c;
FILE *f;

File(std::string path,std::string mode="r");
};

#endif