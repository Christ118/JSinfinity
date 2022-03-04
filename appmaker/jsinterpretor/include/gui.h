#ifndef jsgui
#define jsgui
#include "defs.h"
#include<gtkmm-3.0/gtkmm.h>
class Window
{
    public:
    Gtk::Window w;
    static v8::Local<v8::ObjectTemplate> Windowobjt;
    static void newWindow(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void  Setdefaultsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Settitle(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info);
     static void Gettitle(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);
    static void Setsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Seticon(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Show(const v8::FunctionCallbackInfo<v8::Value> & args);
   static void Mainloop(const v8::FunctionCallbackInfo<v8::Value> & args);
    static v8::Local<v8::ObjectTemplate>  makeWindowobjt(v8::Isolate *isolate);

    static Glib::RefPtr<Gtk::Application> app;
};


#endif