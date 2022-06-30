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
v8::Local<v8::ObjectTemplate> Gui::statusbarobjt;
v8::Local<v8::ObjectTemplate> Gui::toolbuttonobjt;
v8::Local<v8::ObjectTemplate> Gui::comboboxobjt;
v8::Local<v8::ObjectTemplate> Gui::comboboxtextobjt;
v8::Local<v8::ObjectTemplate> Gui::toolpaletteobjt;
v8::Local<v8::ObjectTemplate> Gui::panedobjt;
v8::Local<v8::ObjectTemplate> Gui::colorchooserdialogobjt;
v8::Local<v8::ObjectTemplate> Gui::dialogobjt;
v8::Local<v8::ObjectTemplate> Gui::fontchooserdialogobjt;
v8::Local<v8::ObjectTemplate> Gui::textviewobjt;
v8::Local<v8::ObjectTemplate> Gui::notebookobjt;

v8::Local<v8::ObjectTemplate> Gui::gridobjt;

v8::Local<v8::ObjectTemplate> Gui::toolbarobjt;
v8::Local<v8::ObjectTemplate> Gui::filechooserdialogobjt;
v8::Local<v8::ObjectTemplate> Gui::messagedialogobjt;
v8::Local<v8::ObjectTemplate> Gui::aboutdialogobjt;
v8::Local<v8::ObjectTemplate> Gui::scrolledwindowobjt;



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

Gtk::Dialog * getdialog(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Dialog*>(ptr);
}

Gtk::ComboBox * getcombobox(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::ComboBox*>(ptr);
}

Gtk::ComboBoxText * getcomboboxtext(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::ComboBoxText*>(ptr);
}

Gtk::Paned * getpaned(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Paned*>(ptr);
}

Gtk::ScrolledWindow * getscrolledwindow(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::ScrolledWindow*>(ptr);
}

Gtk::Grid * getgrid(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Grid*>(ptr);
}

Gtk::ToolPalette * gettoolpalette(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::ToolPalette*>(ptr);
}

Gtk::FileChooser * getfilechooser(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::FileChooser*>(ptr);
}

Gtk::FileChooserDialog * getfilechooserdialog(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::FileChooserDialog*>(ptr);
}

Gtk::FontChooserDialog * getfontchooserdialog(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::FontChooserDialog*>(ptr);
}


Gtk::ColorChooserDialog * getcolorchooserdialog(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();
  return static_cast<Gtk::ColorChooserDialog*>(ptr);
}

Gtk::Statusbar * getstatusbar(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();
  return static_cast<Gtk::Statusbar*>(ptr);
}


Gtk::InfoBar * infobar(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();
  return static_cast<Gtk::InfoBar*>(ptr);
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

Gtk::Toolbar  * gettoolbar(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::Toolbar *>(ptr);
}


Gtk::ToolButton * gettoolbutton(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o= obj->GetInternalField(0).As<v8::External>();
  void* ptr = o->Value();

  return static_cast<Gtk::ToolButton*>(ptr);
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


/*
window functions
@elodream
*/

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

void Gui::newwindow(const v8::FunctionCallbackInfo<v8::Value> & args)
{  
Gtk::Window * p = new Gtk::Window;
p->show();
p->set_default_size(200,200);
p->set_title("Gtk");

v8::Local<v8::Object> o= Windowobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));

args.GetReturnValue().Set(o);

}

/*
button functions
@elodream
*/
// create new button 
void Gui::newbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  

Gtk::Button * p =new Gtk::Button;
p->show();
p->set_label("jslight button");

v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
printf("yo");
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
printf("yi");

args.GetReturnValue().Set(o);
printf("ye");


}
/*
progressbar functions
@elodream
*/

//create new progress bar
void Gui::newprogressbar(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::ProgressBar * p =new Gtk::ProgressBar;
p->show();
v8::Local<v8::Object> o= progressbarobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

//set progress positon 
void Gui::setprogressposition(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info)
{
Gtk::ProgressBar *p=getprogressbar(info.Holder());
if(value->IsNumber())
p->set_fraction(value->NumberValue(info.GetIsolate()->GetCurrentContext()).FromJust());
}

//get progress position  
void Gui::getprogressposition(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info)
{
Gtk::ProgressBar *p=getprogressbar(info.Holder());
float f =p->get_fraction();

info.GetReturnValue().Set(v8::Number::New(info.GetIsolate(),f));
}

/*spin button function 
@elodream
*/
void Gui::newspinbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::SpinButton * p =new Gtk::SpinButton;
p->show();
v8::Local<v8::Object> o= spinbuttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
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

void Gui::newcheckbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::CheckButton * p =new Gtk::CheckButton;
p->show();
v8::Local<v8::Object> o= checkbuttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

/*
Toolbar  function 
@elodream
*/
void Gui::newtoolbar(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Toolbar  * p =new Gtk::Toolbar;
p->show();
v8::Local<v8::Object> o= toolbarobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newdialog(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  /*
Gtk::Dialog  * p =new Gtk::Dialog;
p->show();
v8::Local<v8::Object> o= toolbarobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);*/

}

void Gui::newinfobar(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::InfoBar  * p =new Gtk::InfoBar;
p->show();
v8::Local<v8::Object> o= toolbarobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

void Gui::newtoolbutton(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::ToolButton  * p =new Gtk::ToolButton;
p->show();
v8::Local<v8::Object> o= toolbarobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}
/* 
switch button  function 
@elodream
*/
void Gui::newswitch(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Switch * p =new Gtk::Switch;
p->show();
v8::Local<v8::Object> o= switchobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

/*
filechooserdialog function 
@elodream

*/
void Gui::newfilechooserdialog(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
/*Gtk::FileChooserDialog * p =new Gtk::FileChooserDialog("");
p->show();
v8::Local<v8::Object> o=filechooserdialogobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);
*/
}



/*
grid function 
@elodream

*/
void Gui::newgrid(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Grid * p =new Gtk::Grid;
p->show();
v8::Local<v8::Object> o= gridobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}



/*
notebook function 
@elodream

*/
void Gui::newnotebook(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Notebook * p =new Gtk::Notebook;
p->show();
v8::Local<v8::Object> o= notebookobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}


/*
combotext function 
@elodream

*/
void Gui::newcomboboxtext(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::ComboBoxText * p =new Gtk::ComboBoxText;
p->show();
v8::Local<v8::Object> o= comboboxtextobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}


/*
Combobox function 
@elodream

*/
void Gui::newcombobox(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::ComboBox * p =new Gtk::ComboBox;
p->show();
v8::Local<v8::Object> o= comboboxobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

/*
message dialog function 
@elodream

*/
void Gui::newmessagedialog(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
/*Gtk::MessageDialog * p =new Gtk::MessageDialog("hello");
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);
*/
}
/*
toolpalette functions 
@elodream
*/


void Gui::newtoolpalette(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::ToolPalette * p =new Gtk::ToolPalette;
p->show();
v8::Local<v8::Object> o= toolpaletteobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

/*
paned functions 
@elodream

*/
void Gui::newpaned(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Paned * p =new Gtk::Paned;
p->show();
v8::Local<v8::Object> o= panedobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}
/*
scrolledwindow functions 
@elodream

*/
void Gui::newscrolledwindow(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::ScrolledWindow * p =new Gtk::ScrolledWindow;
p->show();
v8::Local<v8::Object> o= scrolledwindowobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

/*
eventbox functions 
@elodream

*/
void Gui::neweventbox(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::EventBox * p =new Gtk::EventBox;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}
/*
searchbar functions 
@elodream

*/
void Gui::newsearchbar(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::SearchBar * p =new Gtk::SearchBar;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}
/*
searchentry functions 
@elodream

*/
void Gui::newsearchentry(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::SearchEntry * p =new Gtk::SearchEntry;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}


/*
frame functions 
@elodream

*/
void Gui::newframe(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Frame * p =new Gtk::Frame;
p->show();
v8::Local<v8::Object> o= buttonobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}
/*
fontchooser functions 
@elodream

*/
void Gui::newfontchooserdialog(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::FontChooserDialog * p =new Gtk::FontChooserDialog;
p->show();
v8::Local<v8::Object> o= fontchooserdialogobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}
/*
colorchooserdialog function 
@elodream

*/
void Gui::newcolorchooserdialog(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::ColorChooserDialog * p =new Gtk::ColorChooserDialog;
p->show();
v8::Local<v8::Object> o= colorchooserdialogobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);

}

/*
entry functions 
@elodream

*/

void Gui::newentry(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
Gtk::Entry * p =new Gtk::Entry;
p->show();
v8::Local<v8::Object> o= entryobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
 
o->SetInternalField(0,v8::External::New(args.GetIsolate(),p));
args.GetReturnValue().Set(o);


}

/*
box functions 
@elodream

*/

void Gui::newbox(const v8::FunctionCallbackInfo<v8::Value> & args)
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

void Gui::newbuttonbox(const v8::FunctionCallbackInfo<v8::Value> & args)
{
  
/*Gtk::ButtonBox * p ;
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
args.GetReturnValue().Set(o);*/

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
void Gui::mainloop(const v8::FunctionCallbackInfo<v8::Value> & args)
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
    Windowobjt->Set(iso,"loop",v8::FunctionTemplate::New(iso,mainloop));
    
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


v8::Local<v8::ObjectTemplate> Gui::maketoolbarobjt(v8::Isolate *iso)
{
   toolbarobjt = v8::ObjectTemplate::New(iso);
    toolbarobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    toolbarobjt->SetInternalFieldCount(1);
    return toolbarobjt;
}


v8::Local<v8::ObjectTemplate> Gui::maketoolbuttonobjt(v8::Isolate *iso)
{
    toolbuttonobjt = v8::ObjectTemplate::New(iso);
    toolbuttonobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    toolbuttonobjt->SetInternalFieldCount(1);
    return toolbuttonobjt;
}


v8::Local<v8::ObjectTemplate> Gui::makedialogobjt(v8::Isolate *iso)
{
    dialogobjt = v8::ObjectTemplate::New(iso);
    dialogobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    dialogobjt->SetInternalFieldCount(1);
    return dialogobjt;
}


v8::Local<v8::ObjectTemplate> Gui::makestatusbarobjt(v8::Isolate *iso)
{
    progressbarobjt = v8::ObjectTemplate::New(iso);
    progressbarobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    progressbarobjt->SetInternalFieldCount(1);
    return progressbarobjt;
}


v8::Local<v8::ObjectTemplate> Gui::maketextviewobjt(v8::Isolate *iso)
{
    textviewobjt = v8::ObjectTemplate::New(iso);
    textviewobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    textviewobjt->SetInternalFieldCount(1);
    return textviewobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makemessagedialogobjt(v8::Isolate *iso)
{
    messagedialogobjt = v8::ObjectTemplate::New(iso);
    messagedialogobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    messagedialogobjt->SetInternalFieldCount(1);
    return textviewobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makescrolledwindowobjt(v8::Isolate *iso)
{
    scrolledwindowobjt = v8::ObjectTemplate::New(iso);
    scrolledwindowobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    scrolledwindowobjt->SetInternalFieldCount(1);
    return textviewobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makepanedobjt(v8::Isolate *iso)
{
    panedobjt = v8::ObjectTemplate::New(iso);
    panedobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    panedobjt->SetInternalFieldCount(1);
    return textviewobjt;
}

v8::Local<v8::ObjectTemplate> Gui::makeaboutdialogobjt(v8::Isolate *iso)
{
    aboutdialogobjt = v8::ObjectTemplate::New(iso);
    aboutdialogobjt->SetAccessor(v8::String::NewFromUtf8Literal(iso,"position"),getprogressposition,setprogressposition);
    aboutdialogobjt->SetInternalFieldCount(1);
    
    return textviewobjt;
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

  
  guiobjt->Set(iso,"window",v8::FunctionTemplate::New(iso,Gui::newwindow));
  guiobjt->Set(iso,"button",v8::FunctionTemplate::New(iso,Gui::newbutton));
  guiobjt->Set(iso,"spinbutton",v8::FunctionTemplate::New(iso,Gui::newspinbutton));
  guiobjt->Set(iso,"checkbutton",v8::FunctionTemplate::New(iso,Gui::newcheckbutton));
  guiobjt->Set(iso,"progressbar",v8::FunctionTemplate::New(iso,Gui::newprogressbar));
    guiobjt->Set(iso,"Toolbar ",v8::FunctionTemplate::New(iso,Gui::newtoolbar));
      guiobjt->Set(iso,"toolbutton",v8::FunctionTemplate::New(iso,Gui::newtoolbutton));
        guiobjt->Set(iso,"colorchooserdialog",v8::FunctionTemplate::New(iso,Gui::newcolorchooserdialog));
          guiobjt->Set(iso,"filechooserdialog",v8::FunctionTemplate::New(iso,Gui::newfilechooserdialog));
            guiobjt->Set(iso,"dialog",v8::FunctionTemplate::New(iso,Gui::newdialog));
  guiobjt->Set(iso,"infobar",v8::FunctionTemplate::New(iso,Gui::newinfobar));
                                    guiobjt->Set(iso,"buttonbox",v8::FunctionTemplate::New(iso,Gui::newbuttonbox));


  guiobjt->Set(iso,"switchbutton",v8::FunctionTemplate::New(iso,Gui::newswitch));
  guiobjt->Set(iso,"entry",v8::FunctionTemplate::New(iso,Gui::newentry));
  guiobjt->Set(iso,"image",v8::FunctionTemplate::New(iso,Gui::newimage));
  guiobjt->Set(iso,"label",v8::FunctionTemplate::New(iso,Gui::newlabel));
  guiobjt->Set(iso,"box",v8::FunctionTemplate::New(iso,Gui::newbox));
  
    return guiobjt;
}

//init function 


extern "C"  v8::Local<v8::ObjectTemplate> init(v8::Isolate *iso,char **argv,int argc)
{
int argn=1;
  Gui::app=Gtk::Application::create(argn,argv,"elodream.herokuapp.com");

  return Gui::makeguiobjt(iso);
} 




