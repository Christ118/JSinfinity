#ifndef JSSYSTEM
#define JSSYSTEM
#include "defs.h"



class System
{
public:
static void systemcmd(const v8::FunctionCallbackInfo<v8::Value> & args);
static void version(const v8::FunctionCallbackInfo<v8::Value> & args);

};

#endif