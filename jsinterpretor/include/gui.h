#ifndef jsgui
#define jsgui
#include "defs.h"
#include<gtkmm-3.0/gtkmm.h>
class Gui
{
    public:
    Gtk::Window w;
    static v8::Local<v8::ObjectTemplate> Windowobjt;
    static v8::Local<v8::ObjectTemplate> buttonobjt;
    static v8::Local<v8::ObjectTemplate> spinbuttonobjt;
    static v8::Local<v8::ObjectTemplate> checkbuttonobjt;
    static v8::Local<v8::ObjectTemplate> switchobjt;
    static v8::Local<v8::ObjectTemplate> boxobjt;

    static void newBox(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newWindow(const v8::FunctionCallbackInfo<v8::Value> & args);
    /* Gui function*/
    static void Setdefaultsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Settitle(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info);
    static void Gettitle(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);
    static void Setsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Seticon(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Show(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Add(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Pack(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Mainloop(const v8::FunctionCallbackInfo<v8::Value> & args);
    /*object template */
    
    static v8::Local<v8::ObjectTemplate>  makeWindowobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makebuttonobjt(v8::Isolate *isolate);
     static v8::Local<v8::ObjectTemplate>  makeswitchobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makespinbuttonobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makecheckbuttonobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makeboxobjt(v8::Isolate *iso);
    static void newButton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newSpinbutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newCheckbutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newSwitch(const v8::FunctionCallbackInfo<v8::Value> & args);


    static Glib::RefPtr<Gtk::Application> app;
};


#endif