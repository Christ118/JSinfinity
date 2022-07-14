#include "jltk.h"
// get the box object
Fl_Box *Jltk::getbox(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Box *>(ptr);
}

// this function make a javascript binding for fl_box class
v8::Local<v8::ObjectTemplate> Jltk::makeboxobjt(v8::Isolate *iso)
{
    boxobjt = v8::ObjectTemplate::New(iso);
    boxobjt->SetInternalFieldCount(1);
    return boxobjt;
}