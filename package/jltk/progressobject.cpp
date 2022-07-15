#include "jltk.h"

Fl_Progress *Jltk::getprogress(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Progress *>(ptr);
}
void Jltk::newprogress(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Progress *p = new Fl_Progress(0, 0, 100, 20);
    v8::Local<v8::Object> o = progressobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));
    args.GetReturnValue().Set(o);
}
v8::Local<v8::ObjectTemplate> Jltk::makeprogressobjt(v8::Isolate *iso)
{
    progressobjt = v8::ObjectTemplate::New(iso);
    progressobjt->SetInternalFieldCount(1);
    return progressobjt;
}
