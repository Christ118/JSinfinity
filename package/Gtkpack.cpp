#include"Gtkpack.h"
#include<exception>


v8::Local<v8::ObjectTemplate> Gui::guiobjt;
Glib::RefPtr<Gtk::Application> Gui::app;

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




std::string argtostr(v8::Local<v8::Value> arg[],int c,v8::Isolate *iso)
{
  std::string t="";
  for(int i=0;i<c;i++)
  {
    v8::String::Utf8Value str (iso,arg[i]);
    if(i==0)
      t+=*str;
    else
      t=t+','+*str;

  }
  return t;
}

void split(std::string t,char s,v8::Local<v8::Value>  a[],v8::Isolate *iso)
{
    std::string n="";
    int i=0;
    int j=0;
    do
    {
      if(t[i]==s ||t[i]=='\0')
      {
        a[j]=v8::String::NewFromUtf8(iso,n.c_str()).ToLocalChecked();
        j++;
        n="";
      }
      else
      {
        n+=t[i];
      }
      i++;

    }while(i<=t.size());
}
void allsign(std::string funcname,v8::Isolate *  iso,std::string argst,int cn )
{
  v8::Local<v8::Value> argv[cn];
  split(argst,',',argv,iso);
  v8::Local<v8::Context> context=iso->GetCurrentContext();
  v8::Local<v8::Object>  global=context->Global();
 v8::Local<v8::Function> func= global->Get(context ,v8::String::NewFromUtf8(context->GetIsolate(),funcname.c_str()).ToLocalChecked()).ToLocalChecked().As<v8::Function>();
  auto c=func->Call(context,global,cn,argv);


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


Gtk::SpinButton * getspinbutton(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::SpinButton*>(ptr);
}
Gtk::ProgressBar * getprogressbar(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::ProgressBar*>(ptr);
}
Gtk::Image * getimage(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Image*>(ptr);
}

Gtk::Label * getlabel(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Label*>(ptr);
}

Gtk::CheckButton * getcheckbutton(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::CheckButton*>(ptr);
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

//set window to fullscreen
void Gui::fullscreen(const v8::FunctionCallbackInfo<v8::Value> & args)
{
Gtk::Window *p=getWindow(args.Holder());
p->fullscreen();
}

//disable fullscreen
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

//move window
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
p->set_title("Gtk");

v8::Local<v8::Object> o= Windowobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));

args.GetReturnValue().Set(o);

}

// create new button 
void Gui::newButton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Button * p =new Gtk::Button;
p->show();
p->set_label("jslight button");
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}
/*progressbar function 
@elodream
*/

//create new progress bar
void Gui::newprogressbar(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::ProgressBar * p =new Gtk::ProgressBar;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

//set window title
void Gui::setprogressposition(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info)
{
Gtk::ProgressBar *p=getprogressbar(info.Holder());
if(value->IsNumber())
p->set_fraction(value->NumberValue(info.GetIsolate()->GetCurrentContext()).FromJust());
}

//get window title
void Gui::getprogressposition(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info)
{
Gtk::ProgressBar *p=getprogressbar(info.Holder());
float f =p->get_fraction();

info.GetReturnValue().Set(v8::Number::New(info.GetIsolate(),f));
}

/*spin button function 
@elodream
*/
void Gui::newSpinbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::SpinButton * p =new Gtk::SpinButton;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::getspinbuttonvalue(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  Gtk::SpinButton *p=getspinbutton(args.Holder());
float v=p->get_value();
args.GetReturnValue().Set(v8::Number::New(args.GetIsolate(),v));

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
v8::String::Utf8Value path (args.GetIsolate(),args[0]) ;  
Gtk::Image * p =new Gtk::Image(*path);
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
 v8::Local<v8::Function> func=args[0].As<v8::Function>();
v8::String::Utf8Value str (args.GetIsolate(),func->GetName());
  Gtk::Button *p=getbutton(args.Holder());
  int ac=args.Length()-1;

  v8::Local<v8::Value> argv[ac] ;
  for(int i=0;i<ac;i++)
  argv[i]=args[i+1];
  
  p->signal_clicked().connect(sigc::bind<std::string , v8::Isolate * ,std::string,int>(sigc::ptr_fun(&allsign),*str,args.GetIsolate(),argtostr(argv,ac,args.GetIsolate()),ac));

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


v8::Local<v8::ObjectTemplate> Gui::makeprogressbarobjt(v8::Isolate *iso)
{
    progressbarobjt = v8::ObjectTemplate::New(iso);
    progressbarobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    progressbarobjt->SetInternalFieldCount(1);
    return progressbarobjt;
}

/*make gtk object */
v8::Local<v8::ObjectTemplate> Gui::makeguiobjt(v8::Isolate *iso)
{
    guiobjt = v8::ObjectTemplate::New(iso);

 guiobjt->Set(iso,"Button",Gui::makebuttonobjt(iso));
  guiobjt->Set(iso,"Window",Gui::makeWindowobjt(iso));
  guiobjt->Set(iso,"Spinbutton",Gui::makespinbuttonobjt(iso));
  guiobjt->Set(iso,"Checkbutton",Gui::makecheckbuttonobjt(iso));
  guiobjt->Set(iso,"Switch",Gui::makeswitchobjt(iso));
  guiobjt->Set(iso,"Entry",Gui::makeentryobjt(iso));
  guiobjt->Set(iso,"Image",Gui::makeimageobjt(iso));
  guiobjt->Set(iso,"Label",Gui::makelabelobjt(iso));
  guiobjt->Set(iso,"Box",Gui::makeboxobjt(iso));
  
  guiobjt->Set(iso,"window",v8::FunctionTemplate::New(iso,Gui::newWindow));
  guiobjt->Set(iso,"button",v8::FunctionTemplate::New(iso,Gui::newButton));
  guiobjt->Set(iso,"spinbutton",v8::FunctionTemplate::New(iso,Gui::newSpinbutton));
  guiobjt->Set(iso,"checkbutton",v8::FunctionTemplate::New(iso,Gui::newCheckbutton));
  guiobjt->Set(iso,"progress",v8::FunctionTemplate::New(iso,Gui::newprogressbar));

  guiobjt->Set(iso,"switchbutton",v8::FunctionTemplate::New(iso,Gui::newSwitch));
  guiobjt->Set(iso,"entry",v8::FunctionTemplate::New(iso,Gui::newentry));
  guiobjt->Set(iso,"image",v8::FunctionTemplate::New(iso,Gui::newimage));
  guiobjt->Set(iso,"label",v8::FunctionTemplate::New(iso,Gui::newlabel));
  guiobjt->Set(iso,"box",v8::FunctionTemplate::New(iso,Gui::newBox));

    return guiobjt;
}


extern "C"  v8::Local<v8::ObjectTemplate> init(v8::Isolate *iso,char **argv,int argc)
{
  Gui::app=Gtk::Application::create(argc,argv);

  return Gui::makeguiobjt(iso);
} 




