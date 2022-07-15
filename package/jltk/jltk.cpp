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
  jltkobjt->Set(iso, "Window", Jltk::makeWindowobjt(iso));
  jltkobjt->Set(iso, "Button", Jltk::makebuttonobjt(iso));
  jltkobjt->Set(iso, "Tree", Jltk::maketreeobjt(iso));
  jltkobjt->Set(iso, "Progress", Jltk::makeprogressobjt(iso));
  jltkobjt->Set(iso, "Box", Jltk::makeboxobjt(iso));
  jltkobjt->Set(iso, "Image", Jltk::makeimageobjt(iso));
  jltkobjt->Set(iso, "Label", Jltk::makelabelobjt(iso));
  jltkobjt->Set(iso, "Spinner", Jltk::makespinnerobjt(iso));
  jltkobjt->Set(iso, "browser", Jltk::makebrowserobjt(iso));
  jltkobjt->Set(iso, "Filechooser", Jltk::makefilechooserobjt(iso));
  jltkobjt->Set(iso, "Colorchooser", Jltk::makecolorchooserobjt(iso));
  jltkobjt->Set(iso, "Fileinput", Jltk::makefileinputobjt(iso));
  jltkobjt->Set(iso, "Slider", Jltk::makesliderobjt(iso));
  jltkobjt->Set(iso, "Valueslider", Jltk::makevaluesliderobjt(iso));
  jltkobjt->Set(iso, "Menubar", Jltk::makemenubarobjt(iso));
  jltkobjt->Set(iso, "Radobutton", Jltk::makeradiobuttonobjt(iso));
  jltkobjt->Set(iso, "Doublewindow", Jltk::makedoublewindowobjt(iso));
  jltkobjt->Set(iso, "Scroll", Jltk::makescrollobjt(iso));
  jltkobjt->Set(iso, "Scrollbar", Jltk::makescrollbarobjt(iso));
  jltkobjt->Set(iso, "Treeitem", Jltk::maketreeitemobjt(iso));
  jltkobjt->Set(iso, "Texteditor", Jltk::maketexteditorobjt(iso));

  jltkobjt->Set(iso, "window", v8::FunctionTemplate::New(iso, Jltk::newwindow));

  return jltkobjt;
}

/*
this function  is called by jsinfinity
*/
extern "C" v8::Local<v8::ObjectTemplate> init(v8::Isolate *iso, char **argv, int argc)
{
  return Jltk::makejltkobjt(iso);
}
