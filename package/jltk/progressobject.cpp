#include "jltk.h"

Fl_Progress *Jltk::getprogress(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Progress *>(ptr);
}

v8::Local<v8::ObjectTemplate> Jltk::makeprogressobjt(v8::Isolate *iso)
{
    progressobjt = v8::ObjectTemplate::New(iso);
    progressobjt->SetInternalFieldCount(1);
    return progressobjt;
}
