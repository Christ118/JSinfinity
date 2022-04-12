#include"../include/gui.h"
#include<exception>

v8::Local<v8::ObjectTemplate> Gui::Windowobjt;
v8::Local<v8::ObjectTemplate> Gui::buttonobjt;
v8::Local<v8::ObjectTemplate> Gui::spinbuttonobjt;
v8::Local<v8::ObjectTemplate> Gui::checkbuttonobjt;
v8::Local<v8::ObjectTemplate> Gui::switchobjt;
v8::Local<v8::ObjectTemplate> Gui::boxobjt;
v8::Local<v8::ObjectTemplate> Gui::entryobjt;
v8::Local<v8::ObjectTemplate> Gui::progressbarobjt;
v8::Local<v8::ObjectTemplate> Gui::imageobjt;
v8::Local<v8::ObjectTemplate> Gui::labelobjt;


Glib::RefPtr<Gtk::Application> Gui::app;
void allsign(v8::FunctionCallbackInfo<v8::Value> args)
{
  v8::Local<v8::Function> func=args[0].As<v8::Function>();
    v8::Local<v8::Context> context=args.GetIsolate()->GetCurrentContext();
  const int argc = 1;
  printf("hhh");
  v8::Local<v8::Value> argv[argc] = {v8::Int32::New(context->GetIsolate(),2000)};
    auto r=func->Call(context,context->Global(),argc,argv);
  


}

Gtk::Window * getWindow(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Window*>(ptr);
}

Gtk::Widget * getWidget(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Widget*>(ptr);
}

Gtk::Button * getbutton(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Button*>(ptr);
}

Gtk::Box * getbox(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Box*>(ptr);
}


//show or  hide  window
void Gui::Show(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
p->show();

}

//set window title
void Gui::Settitle(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info)
{
Gtk::Window *p=getWindow(info.Holder());
v8::String::Utf8Value str(info.GetIsolate(),value);

p->set_title(*str);
}

//get window title
void Gui::Gettitle(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info)
{
Gtk::Window *p=getWindow(info.Holder());
std::string title=p->get_title();

info.GetReturnValue().Set(v8::String::NewFromUtf8(info.GetIsolate(),title.c_str()).ToLocalChecked());
}

//set window size
void Gui::Setdefaultsize(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
v8::String::Utf8Value str(args.GetIsolate(),args[0]);
p->set_size_request(args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
}

//set window icon
void Gui::Seticon(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
v8::String::Utf8Value str(args.GetIsolate(),args[0]);
p->set_icon_from_file(*str);
}


void Gui::fullscreen(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
p->fullscreen();
}


void Gui::unfullscreen(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
p->unfullscreen();
}


//set window size
void Gui::setsize(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
p->resize(args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
}

//set window size
void Gui::move(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
p->move(args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
}



//create a new js window

void Gui::newWindow(const v8::FunctionCallbackInfo<v8::Value> & args)
{  
Gtk::Window * p = new Gtk::Window;
p->show();
p->set_default_size(200,200);
p->set_title("elodream Window");

v8::Local<v8::Object> o= Gui::Windowobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newButton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Button * p =new Gtk::Button;
p->show();
p->set_label("jslight button");
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newSpinbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::SpinButton * p =new Gtk::SpinButton;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newlabel(const v8::FunctionCallbackInfo<v8::Value> & args)
{

  
Gtk::Label * p =new Gtk::Label("text");
p->show();
v8::Local<v8::Object> o= labelobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newimage(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Image * p =new Gtk::Image;
p->show();
v8::Local<v8::Object> o= imageobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newCheckbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::CheckButton * p =new Gtk::CheckButton;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newSwitch(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Switch * p =new Gtk::Switch;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newentry(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Entry * p =new Gtk::Entry;
p->show();
v8::Local<v8::Object> o= entryobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}


void Gui::newBox(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Box * p ;
v8::String::Utf8Value dir(args.GetIsolate(),args[0]);

std::string a=*dir;
Gtk::Orientation  d;
if(a=="vertical")
p=new Gtk::VBox(args[1]->BooleanValue(args.GetIsolate()),args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
else
p=new Gtk::HBox(args[1]->BooleanValue(args.GetIsolate()),args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());


p->show();
v8::Local<v8::Object> o= boxobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::Add(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  Gtk::Window *p=getWindow(args.Holder());
v8::Local<v8::Object> o(args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked());

Gtk::Widget* widget =getWidget(o);
p->add(*widget);
args.GetReturnValue().Set(o);

}

void Gui::Pack(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  Gtk::Box *p=getbox(args.Holder());
v8::Local<v8::Object> o(args[0]->ToObject(args.GetIsolate()->GetCurrentContext()).ToLocalChecked());
Gtk::Widget* widget =getWidget(o);

p->pack_start(*widget,Gtk::PACK_SHRINK,args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
args.GetReturnValue().Set(o);

}


//start event
void Gui::Mainloop(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
app->run(*p);

}

void Gui::connect(const v8::FunctionCallbackInfo<v8::Value> & args)
{
 

 auto context=args.GetIsolate()->GetCurrentContext();

  Gtk::Button *p=getbutton(args.Holder());

  p->signal_clicked().connect(sigc::bind<v8::FunctionCallbackInfo<v8::Value>>(sigc::ptr_fun(&allsign),args));

}

v8::Local<v8::ObjectTemplate> Gui::makeboxobjt(v8::Isolate *iso)
{
    boxobjt = v8::ObjectTemplate::New(iso);
    boxobjt->SetInternalFieldCount(1);
    boxobjt->Set(iso,"pack",v8::FunctionTemplate::New(iso,Pack));
   
    return boxobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makeWindowobjt(v8::Isolate *iso)
{
    Windowobjt = v8::ObjectTemplate::New(iso);
    Windowobjt->SetInternalFieldCount(1);
    Windowobjt->Set(iso,"setdefaultsize",v8::FunctionTemplate::New(iso,Setdefaultsize));
    Windowobjt->Set(iso,"seticon",v8::FunctionTemplate::New(iso,Seticon));
    Windowobjt->Set(iso,"unfullscreen",v8::FunctionTemplate::New(iso,unfullscreen));
    Windowobjt->Set(iso,"fullscreen",v8::FunctionTemplate::New(iso,fullscreen));
    Windowobjt->Set(iso,"setsize",v8::FunctionTemplate::New(iso,setsize));
    Windowobjt->Set(iso,"move",v8::FunctionTemplate::New(iso,move));
    Windowobjt->Set(iso,"add",v8::FunctionTemplate::New(iso,Add));
    Windowobjt->Set(iso,"loop",v8::FunctionTemplate::New(iso,Mainloop));
    Windowobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"title"),Gettitle,Settitle);
    return Windowobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makebuttonobjt(v8::Isolate *iso)
{
    buttonobjt = v8::ObjectTemplate::New(iso);
    buttonobjt->Set(iso,"connect",v8::FunctionTemplate::New(iso,connect));
    buttonobjt->SetInternalFieldCount(1);
    return buttonobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makespinbuttonobjt(v8::Isolate *iso)
{
    spinbuttonobjt = v8::ObjectTemplate::New(iso);
    spinbuttonobjt->SetInternalFieldCount(1);
    return spinbuttonobjt;
}



v8::Local<v8::ObjectTemplate> Gui::makecheckbuttonobjt(v8::Isolate *iso)
{
    checkbuttonobjt = v8::ObjectTemplate::New(iso);
    checkbuttonobjt->SetInternalFieldCount(1);
    return checkbuttonobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makeswitchobjt(v8::Isolate *iso)
{
    switchobjt = v8::ObjectTemplate::New(iso);
    switchobjt->SetInternalFieldCount(1);
    return switchobjt;
}
v8::Local<v8::ObjectTemplate> Gui::makeentryobjt(v8::Isolate *iso)
{
    entryobjt = v8::ObjectTemplate::New(iso);
    entryobjt->SetInternalFieldCount(1);
    return entryobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makelabelobjt(v8::Isolate *iso)
{
  labelobjt = v8::ObjectTemplate::New(iso);
    labelobjt->SetInternalFieldCount(1);
    return labelobjt;
}


v8::Local<v8::ObjectTemplate> Gui::makeimageobjt(v8::Isolate *iso)
{
    imageobjt = v8::ObjectTemplate::New(iso);
    imageobjt->SetInternalFieldCount(1);
    return imageobjt;
}


