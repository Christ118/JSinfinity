#include "jltk.h"

Fl_Window *Jltk::gettexteditor(v8::Local<v8::Object> obj)
{
    v8::Local<v8::External> o = obj->GetInternalField(0).As<v8::External>();
    void *ptr = o->Value();

    return static_cast<Fl_Text_Editor *>(ptr);
}

void Jltk::newtexteditor(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    Fl_Text_Editor *p = new Fl_Text_Editor(120, 120, 120, 120, "porn");
    v8::Local<v8::Object> o = windowobjt->NewInstance(args.GetIsolate()->GetCurrentContext()).ToLocalChecked();

    o->SetInternalField(0, v8::External::New(args.GetIsolate(), p));

    args.GetReturnValue().Set(o);
}

// this function make a javascript binding for fl_window class
v8::Local<v8::ObjectTemplate> Jltk::maketexteditorobjt(v8::Isolate *iso)
{
    texteditor = v8::ObjectTemplate::New(iso);
    texteditor->SetInternalFieldCount(1);
    return texteditorobjt;
}