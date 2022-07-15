#include "jltk.h"

Fl_Menu_Bar *Jltk::getmenubar(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Menu_Bar *>(ptr);
}

void Jltk::newmenubar(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Menu_Bar *p = new Fl_Menu_Bar(120, 120, 120, 120, "porn");
    p->show(__argc, __argv);
    v8::Local<v8::Object> o = menubarobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));

    args.GetReturnValue().Set(o);
}

// this function make a javascript binding for fl_window class
v8::Local<v8::ObjectTemplate> Jltk::makemenubarobjt(v8::Isolate *iso)
{
    windowobjt = v8::ObjectTemplate::New(iso);
    windowobjt->SetInternalFieldCount(1);
    return windowobjt;
}