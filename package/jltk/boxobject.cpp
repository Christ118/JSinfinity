#include "jltk.h"
// get the box object
Fl_Box *Jltk::getbox(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Box *>(ptr);
}
// box constructor
void Jltk::newbox(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Box *p = new Fl_Box(0,0,0,0);
    v8::Local<v8::Object> o = boxobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));
    args.GetReturnValue().Set(o);
}
// this function make a javascript binding for fl_box class
v8::Local<v8::ObjectTemplate> Jltk::makeboxobjt(v8::Isolate *iso)
{
    boxobjt = v8::ObjectTemplate::New(iso);
    boxobjt->SetInternalFieldCount(1);
    return boxobjt;
}