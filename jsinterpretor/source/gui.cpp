#include"../include/gui.h"


v8::Local<v8::ObjectTemplate> Window::Windowobjt;
v8::Local<v8::ObjectTemplate> Window::buttonobjt;
v8::Local<v8::ObjectTemplate> Window::spinbuttonobjt;
v8::Local<v8::ObjectTemplate> Window::checkbuttonobjt;
v8::Local<v8::ObjectTemplate> Window::switchobjt;
v8::Local<v8::ObjectTemplate> Window::boxobjt;
Glib::RefPtr<Gtk::Application> Window::app;


Window * getWindow(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Window*>(ptr);
}

Gtk::Widget * getWidget(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Widget*>(ptr);
}

Gtk::Box * getbox(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Box*>(ptr);
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

void Window::newButton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Button * p =new Gtk::Button;
p->show();
p->set_label("jslight button");
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Window::newSpinbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::SpinButton * p =new Gtk::SpinButton;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Window::newCheckbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::CheckButton * p =new Gtk::CheckButton;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Window::newSwitch(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Switch * p =new Gtk::Switch;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}


void Window::newBox(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Box * p ;
v8::String::Utf8Value dir(args.GetIsolate(),args[0]);

std::string a=*dir;
if(a=="vertical")
{
  std::cout<<*dir<<"44";
p=new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
}
else
p=new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);

p->show();
 v8::Local<v8::Object> o= boxobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Window::Add(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  Window *p=getWindow(args.Holder());
v8::Local<v8::Object> o(args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked());

Gtk::Widget* widget =getWidget(o);
p->w.add(*widget);
args.GetReturnValue().Set(o);

}

void Window::Pack(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  Gtk::Box *p=getbox(args.Holder());
v8::Local<v8::Object> o(args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked());
Gtk::Widget* widget =getWidget(o);
p->pack_start(*widget,true,true,0);
args.GetReturnValue().Set(o);

}


//start event
void Window::Mainloop(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Window *p=getWindow(args.Holder());
app->run(p->w);

}

v8::Local<v8::ObjectTemplate> Window::makeboxobjt(v8::Isolate *iso)
{
    boxobjt = v8::ObjectTemplate::New(iso);
    boxobjt->SetInternalFieldCount(1);
    boxobjt->Set(iso,"pack",v8::FunctionTemplate::New(iso,Pack));
   
    return Windowobjt;
}

v8::Local<v8::ObjectTemplate> Window::makeWindowobjt(v8::Isolate *iso)
{
    Windowobjt = v8::ObjectTemplate::New(iso);
    Windowobjt->SetInternalFieldCount(1);
    Windowobjt->Set(iso,"setsize",v8::FunctionTemplate::New(iso,Setdefaultsize));
    Windowobjt->Set(iso,"seticon",v8::FunctionTemplate::New(iso,Seticon));
    Windowobjt->Set(iso,"add",v8::FunctionTemplate::New(iso,Add));
    Windowobjt->Set(iso,"loop",v8::FunctionTemplate::New(iso,Mainloop));
    Windowobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"title"),Gettitle,Settitle);
    return Windowobjt;
}

v8::Local<v8::ObjectTemplate> Window::makebuttonobjt(v8::Isolate *iso)
{
    buttonobjt = v8::ObjectTemplate::New(iso);
    buttonobjt->SetInternalFieldCount(1);
    return Windowobjt;
}

v8::Local<v8::ObjectTemplate> Window::makespinbuttonobjt(v8::Isolate *iso)
{
    spinbuttonobjt = v8::ObjectTemplate::New(iso);
    spinbuttonobjt->SetInternalFieldCount(1);
    return Windowobjt;
}



v8::Local<v8::ObjectTemplate> Window::makecheckbuttonobjt(v8::Isolate *iso)
{
    checkbuttonobjt = v8::ObjectTemplate::New(iso);
    checkbuttonobjt->SetInternalFieldCount(1);
    return Windowobjt;
}

v8::Local<v8::ObjectTemplate> Window::makeswitchobjt(v8::Isolate *iso)
{
    switchobjt = v8::ObjectTemplate::New(iso);
    switchobjt->SetInternalFieldCount(1);
    return Windowobjt;
}
