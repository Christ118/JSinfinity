#include "Jltk.h"
v8::Local<v8::ObjectTemplate> Jltk::treeobjt;
v8::Local<v8::ObjectTemplate> Jltk::jltkobjt;
v8::Local<v8::ObjectTemplate> Jltk::windowobjt;
v8::Local<v8::ObjectTemplate> Jltk::buttonobjt;
v8::Local<v8::ObjectTemplate> Jltk::browserobjt;
v8::Local<v8::ObjectTemplate> Jltk::labelobjt;
v8::Local<v8::ObjectTemplate> Jltk::imageobjt;
v8::Local<v8::ObjectTemplate> Jltk::inputobjt;
v8::Local<v8::ObjectTemplate> Jltk::progressobjt;
v8::Local<v8::ObjectTemplate> Jltk::spinnerobjt;
v8::Local<v8::ObjectTemplate> Jltk::tooltipobjt;
v8::Local<v8::ObjectTemplate> Jltk::filechooserobjt;
v8::Local<v8::ObjectTemplate> Jltk::boxobjt;
v8::Local<v8::ObjectTemplate> Jltk::menubarobjt;

Fl_Image *Jltk::getimage(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Image *>(ptr);
}

Fl_Double_Window *Jltk::getdoublewindow(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Double_Window *>(ptr);
}

Fl_File_Chooser *Jltk::getfilechooser(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_File_Chooser *>(ptr);
}
Fl_Color_Chooser *Jltk::getcolorchooser(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Color_Chooser *>(ptr);
}

Fl_Menu_Bar *Jltk::getmenubar(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Menu_Bar *>(ptr);
}
Fl_Tree_Item *Jltk::gettreeitem(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Tree_Item *>(ptr);
}
Fl_Text_Editor *Jltk::gettexteditor(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Text_Editor *>(ptr);
}
Fl_Value_Slider *Jltk::getvalueslider(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Value_Slider *>(ptr);
}
Fl_Scroll *Jltk::getscroll(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Scroll *>(ptr);
}
Fl_Scrollbar *Jltk::getscrollbar(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Scrollbar *>(ptr);
}
Fl_Radio_Button *Jltk::getradiobutton(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Radio_Button *>(ptr);
}
Fl_File_Input *Jltk::getfileinput(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_File_Input *>(ptr);
}

/*make jltk object */
v8::Local<v8::ObjectTemplate> Jltk::makejltkobjt(v8::Isolate *iso)
{

  jltkobjt = v8::ObjectTemplate::New(iso);

  /*jltkobjt->Set(iso,"Window",Jltk::makeWindowobjt(iso));


  jltkobjt->Set(iso,"w",v8::FunctionTemplate::New(iso,Jltk::newwindow));
*/

  return jltkobjt;
}

/*
this function  is called by jsinfinity
*/
extern "C" v8::Local<v8::ObjectTemplate> init(v8::Isolate *iso, char **argv, int argc)
{
  return Jltk::makejltkobjt(iso);
}
