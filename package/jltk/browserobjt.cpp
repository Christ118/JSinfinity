#include "jltk.h"

Fl_Tree *Jltk::gettree(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Tree *>(ptr);
}
void Jltk::newtree(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Tree *p = new Fl_Tree(0,0,0,0);
    v8::Local<v8::Object> o = treeobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));

    args.GetReturnValue().Set(o);
}

v8::Local<v8::ObjectTemplate> Jltk::maketreeobjt(v8::Isolate *iso)
{
    treeobjt = v8::ObjectTemplate::New(iso);
    treeobjt->SetInternalFieldCount(1);
    return treeobjt;
}