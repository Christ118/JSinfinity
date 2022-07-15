#include "jltk.h"

Fl_Tooltip *Jltk::gettooltip(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Tooltip *>(ptr);
}

void Jltk::newtooltip(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Tooltip *p = new Fl_Tooltip();
    v8::Local<v8::Object> o = tooltipobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));
    args.GetReturnValue().Set(o);
}

v8::Local<v8::ObjectTemplate> Jltk::maketooltipobjt(v8::Isolate *iso)
{
    tooltipobjt = v8::ObjectTemplate::New(iso);
    tooltipobjt->SetInternalFieldCount(1);
    return tooltipobjt;
}