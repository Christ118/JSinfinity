#include "jltk.h"

Fl_Spinner *Jltk::getspinner(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Spinner *>(ptr);
}
void Jltk::newspinner(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Spinner *p = new Fl_Spinner(0,0,0,0);
    v8::Local<v8::Object> o = spinnerobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));
    args.GetReturnValue().Set(o);
}
v8::Local<v8::ObjectTemplate> Jltk::makespinnerobjt(v8::Isolate *iso)
{
    spinnerobjt = v8::ObjectTemplate::New(iso);
    spinnerobjt->SetInternalFieldCount(1);
    return spinnerobjt;
}