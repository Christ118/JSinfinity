#include "jltk.h"

Fl_Window *Jltk::getwindow(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Color_Chooser *>(ptr);
}

void Jltk::newcolorchooser(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Color_Chooser *p = new Fl_Color_Chooser(120, 120, 120, 120, "porn");
    v8::Local<v8::Object> o = windowobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));

    args.GetReturnValue().Set(o);
}

// this function make a javascript binding for fl_window class
v8::Local<v8::ObjectTemplate> Jltk::makeWindowobjt(v8::Isolate *iso)
{
    colorchooserobjt = v8::ObjectTemplate::New(iso);
    colorchooseobjt->SetInternalFieldCount(1);
    return colorchooserobjt;
}