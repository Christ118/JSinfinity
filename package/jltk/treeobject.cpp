#include "jltk.h"

Fl_Tree *Jltk::gettree(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Tree *>(ptr);
}
v8::Local<v8::ObjectTemplate> Jltk::maketreeobjt(v8::Isolate *iso)
{
    treeobjt = v8::ObjectTemplate::New(iso);
    treeobjt->SetInternalFieldCount(1);
    return treeobjt;
}