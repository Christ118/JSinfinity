#ifndef jsgui
#define jsgui
#include "defs.h"
#include<gtkmm-3.0/gtkmm.h>
class Gui
{
    public:
    static v8::Local<v8::ObjectTemplate> guiobjt;

    static v8::Local<v8::ObjectTemplate> Windowobjt;
    static v8::Local<v8::ObjectTemplate> buttonobjt;
    static v8::Local<v8::ObjectTemplate> spinbuttonobjt;
    static v8::Local<v8::ObjectTemplate> checkbuttonobjt;
    static v8::Local<v8::ObjectTemplate> switchobjt;
    static v8::Local<v8::ObjectTemplate> entryobjt;
    static v8::Local<v8::ObjectTemplate> progressbarobjt;
    static v8::Local<v8::ObjectTemplate> labelobjt;
    static v8::Local<v8::ObjectTemplate> imageobjt;
     static v8::Local<v8::ObjectTemplate> menubarobjt;
    static v8::Local<v8::ObjectTemplate> menuobjt;
      static v8::Local<v8::ObjectTemplate> boxobjt;
    static v8::Local<v8::ObjectTemplate> menuitemobjt;
    static v8::Local<v8::ObjectTemplate> toolbarobjt;
    static v8::Local<v8::ObjectTemplate>  statutbarobjt;


    static void newBox(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newWindow(const v8::FunctionCallbackInfo<v8::Value> & args);
    
    /* Gui function*/
    static void Setdefaultsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Settitle(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info);
    static void Gettitle(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);
    static void Setsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Seticon(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Show(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void fullscreen(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void unfullscreen(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void setsize(const v8::FunctionCallbackInfo<v8::Value> & args);

    static void setprogressposition(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info);
    static void getprogressposition(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);

    static void getspinbuttonvalue(const v8::FunctionCallbackInfo<v8::Value> & args);

    static void Add(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void move(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Pack(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void connect(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Mainloop(const v8::FunctionCallbackInfo<v8::Value> & args);
    /*object template */
    static v8::Local<v8::ObjectTemplate> makeguiobjt(v8::Isolate *iso);

    static v8::Local<v8::ObjectTemplate>  makeWindowobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makebuttonobjt(v8::Isolate *isolate);
     static v8::Local<v8::ObjectTemplate>  makeswitchobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makespinbuttonobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makeentryobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makecheckbuttonobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makeimageobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makelabelobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makeprogressbarobjt(v8::Isolate *isolate);


    static v8::Local<v8::ObjectTemplate> makeboxobjt(v8::Isolate *iso);
    static void newButton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newSpinbutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newCheckbutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newSwitch(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newentry(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newlabel(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newimage(const v8::FunctionCallbackInfo<v8::Value> & args);
     static void newprogressbar(const v8::FunctionCallbackInfo<v8::Value> & args);
    //static void newimage(const v8::FunctionCallbackInfo<v8::Value> & args);

   


    static Glib::RefPtr<Gtk::Application> app;
};


#endif