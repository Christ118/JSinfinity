#ifndef jsdrive
#define jsdrive
#define VERSION 1.0
#include <stdlib.h>
#include <assert.h>
#include<iostream>
#include<v8.h>
#include <libplatform/libplatform.h>
#include<windows.h>
bool executejs(v8::Isolate *iso,v8::Local<v8::String> source,v8::Local<v8::String>name);

#endif