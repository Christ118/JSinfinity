#include "jltk.h"

Fl_Spinner *Jltk::getspinner(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Spinner *>(ptr);
}

v8::Local<v8::ObjectTemplate> Jltk::makespinnerobjt(v8::Isolate *iso)
{
    spinnerobjt = v8::ObjectTemplate::New(iso);
    spinnerobjt->SetInternalFieldCount(1);
    return spinnerobjt;
}