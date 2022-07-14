#include "jltk.h"

Fl_Label *Jltk::getlabel(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Label *>(ptr);
}

// this function make a javascript binding for fl_label class
v8::Local<v8::ObjectTemplate> Jltk::makelabelobjt(v8::Isolate *iso)
{
    labelobjt = v8::ObjectTemplate::New(iso);
    labelobjt->SetInternalFieldCount(1);
    return labelobjt;
}