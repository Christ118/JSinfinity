#ifndef JSINFINITY
#define JSINFINITY
#define VERSION 1.0

    #include<v8.h>
#include <libplatform/libplatform.h>



#include <stdlib.h>
#include <assert.h>
#include<iostream>
#include<limits.h>


#include<windows.h>
#include<dirent.h>

#define ERR_PRINT 1
#define WARN_PRINT 2
#define SUCESS_PRINT 3




#define CORP_NAME "ELODREAM.INC"
#define CORP_SLOGAN  "live  your  dream "

#define UTILS_PATH "../utils/"
#define JI_PATH "../"

static std::string package_path="../package/";


#ifdef WIN32
#define WINDOW32
#endif
#ifdef LIN
#define LINUX
#endif
void print_advice(std::string  str,short code=ERR_PRINT);
bool executejs(v8::Isolate *iso,v8::Local<v8::String> source,v8::Local<v8::String>name);

#endif