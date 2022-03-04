#include"../include/gui.h"
#include<thread>
v8::Local<v8::ObjectTemplate> Window::Windowobjt;
Glib::RefPtr<Gtk::Application> Window::app;
Window * getWindow(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Window*>(ptr);
}

//show or  hide  window
void Window::Show(const v8::FunctionCallbackInfo<v8::Value> & args)
{


}
//set window title
void Window::Settitle(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info)
{
Window *p=getWindow(info.Holder());
v8::String::Utf8Value str(info.GetIsolate(),value);

p->w.set_title(*str);

}
//get window title
void Window::Gettitle(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info)
{
Window *p=getWindow(info.Holder());
std::string title=p->w.get_title();

info.GetReturnValue().Set(v8::String::NewFromUtf8(info.GetIsolate(),title.c_str()).ToLocalChecked());

}

//set window size
void Window::Setdefaultsize(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Window *p=getWindow(args.Holder());
v8::String::Utf8Value str(args.GetIsolate(),args[0]);
p->w.set_size_request(args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
}

//set window icon

void Window::Seticon(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Window *p=getWindow(args.Holder());
v8::String::Utf8Value str(args.GetIsolate(),args[0]);
p->w.set_icon_from_file(*str);

}

//create a new js window

void Window::newWindow(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Window * p = new Window;
p->w.show();
p->w.set_default_size(200,200);
p->w.set_title("js");

 v8::Local<v8::Object> o= Window::Windowobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
  o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

//start event
void Window::Mainloop(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  Window *p=getWindow(args.Holder());
app->run(p->w);

}

v8::Local<v8::ObjectTemplate> Window::makeWindowobjt(v8::Isolate *iso)
{
    Windowobjt = v8::ObjectTemplate::New(iso);
    Windowobjt->SetInternalFieldCount(1);
    Windowobjt->Set(iso,"setsize",v8::FunctionTemplate::New(iso,Setdefaultsize));
    Windowobjt->Set(iso,"seticon",v8::FunctionTemplate::New(iso,Seticon));
    Windowobjt->Set(iso,"loop",v8::FunctionTemplate::New(iso,Mainloop));
    Windowobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"title"),Gettitle,Settitle);
    return Windowobjt;
}