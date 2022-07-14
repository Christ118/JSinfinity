#include "jltk.h"

Fl_Button *Jltk::getbutton(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();
    return static_cast<Fl_Button *>(ptr);
}

// this function make a javascript binding for fl_button class
v8::Local<v8::ObjectTemplate> Jltk::makebuttonobjt(v8::Isolate *iso)
{
    buttonobjt = v8::ObjectTemplate::New(iso);
    buttonobjt->SetInternalFieldCount(1);
    return buttonobjt;
}