#include "jltk.h"

Fl_Tooltip *Jltk::gettooltip(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Tooltip *>(ptr);
}

v8::Local<v8::ObjectTemplate> Jltk::maketooltipobjt(v8::Isolate *iso)
{
    tooltipobjt = v8::ObjectTemplate::New(iso);
    tooltipobjt->SetInternalFieldCount(1);
    return tooltipobjt;
}