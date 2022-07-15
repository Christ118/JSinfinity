#include "jltk.h"

Fl_Image *Jltk::getimage(v8::Local<v8::Object> obj)
{
  v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
  void *ptr = o->Value();

  return static_cast<Fl_Image *>(ptr);
}
void Jltk::newimage(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Image *p = new Fl_Image();
    v8::Local<v8::Object> o = imageobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();
    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));
    args.GetReturnValue().Set(o);
}

// this function make a javascript binding for fl_label class
v8::Local<v8::ObjectTemplate> Jltk::makeimageobjt(v8::Isolate *iso)
{
    labelobjt = v8::ObjectTemplate::New(iso);
    labelobjt->SetInternalFieldCount(1);
    return labelobjt;
}