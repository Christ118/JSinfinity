#ifndef jsgui
#define jsgui
#include "defs.h"
#include<gtkmm-3.0/gtkmm.h>
class Gui
{
    public:
    static v8::Local<v8::ObjectTemplate> guiobjt;

    static v8::Local<v8::ObjectTemplate> Windowobjt;
    static v8::Local<v8::ObjectTemplate> buttonobjt;
    static v8::Local<v8::ObjectTemplate> spinbuttonobjt;
    static v8::Local<v8::ObjectTemplate> checkbuttonobjt;
    static v8::Local<v8::ObjectTemplate> switchobjt;
    static v8::Local<v8::ObjectTemplate> entryobjt;
    static v8::Local<v8::ObjectTemplate> progressbarobjt;
    static v8::Local<v8::ObjectTemplate> labelobjt;
    static v8::Local<v8::ObjectTemplate> imageobjt;
    static v8::Local<v8::ObjectTemplate> menubarobjt;
    static v8::Local<v8::ObjectTemplate> menuobjt;
    static v8::Local<v8::ObjectTemplate> boxobjt;
    static v8::Local<v8::ObjectTemplate> menuitemobjt;
    static v8::Local<v8::ObjectTemplate> toolbarobjt;
    static v8::Local<v8::ObjectTemplate> statusbarobjt;
    static v8::Local<v8::ObjectTemplate> toolbuttonobjt;
    static v8::Local<v8::ObjectTemplate>  filechooserobjt;
    static v8::Local<v8::ObjectTemplate>  filechooserdialogobjt;
        static v8::Local<v8::ObjectTemplate>  colorchooserdialogobjt;
    static v8::Local<v8::ObjectTemplate>  fontchooserdialogobjt;
        static v8::Local<v8::ObjectTemplate>  togglebuttonobjt;
            static v8::Local<v8::ObjectTemplate>  dialogobjt;
                static v8::Local<v8::ObjectTemplate>  buttonboxobjt;
                    static v8::Local<v8::ObjectTemplate>  textviewobjt;
                     static v8::Local<v8::ObjectTemplate>  panedobjt;
                        static v8::Local<v8::ObjectTemplate>  scrolledwindowobjt;
                         static v8::Local<v8::ObjectTemplate>  comboboxtextobjt;
                          static v8::Local<v8::ObjectTemplate>  comboboxobjt;
                            static v8::Local<v8::ObjectTemplate>  widgetobjt;
                              static v8::Local<v8::ObjectTemplate>  aboutdialogobjt;
                              static v8::Local<v8::ObjectTemplate>  messagedialogobjt;
                              static v8::Local<v8::ObjectTemplate>  gridobjt;
                              static v8::Local<v8::ObjectTemplate>  toolpaletteobjt;
                                static v8::Local<v8::ObjectTemplate>  notebookobjt;










    
    /* GTK function*/
    static void Setdefaultsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Settitle(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info);
    static void Gettitle(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);
    static void Setsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Seticon(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Show(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void fullscreen(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void unfullscreen(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void setsize(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void setprogressposition(v8::Local<v8::String> property, v8::Local<v8::Value> value,const v8::PropertyCallbackInfo<void> & info);
    static void getprogressposition(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> & info);
    static void getspinbuttonvalue(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Add(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void move(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void Pack(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void connect(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void mainloop(const v8::FunctionCallbackInfo<v8::Value> & args);


    /*object template */
    static v8::Local<v8::ObjectTemplate> makeguiobjt(v8::Isolate *iso);

    static v8::Local<v8::ObjectTemplate>  makeWindowobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makebuttonobjt(v8::Isolate *isolate);
     static v8::Local<v8::ObjectTemplate>  makeswitchobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makespinbuttonobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makeentryobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makecheckbuttonobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makeimageobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makelabelobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate>  makeprogressbarobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makeboxobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makedialogobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makeaboutdialogobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makefilechooserobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makefilechooserdialogobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makecolorchooserdialogobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makefontchooserdialogobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makestatusbarobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makemessagedialogobjt(v8::Isolate *iso);






        static v8::Local<v8::ObjectTemplate> makegridobjt(v8::Isolate *iso);
            static v8::Local<v8::ObjectTemplate> makeeventboxobjt(v8::Isolate *iso);
                static v8::Local<v8::ObjectTemplate> maketoolpaletteobjt(v8::Isolate *iso);
                    static v8::Local<v8::ObjectTemplate> makecomboboxobjt(v8::Isolate *iso);
                        static v8::Local<v8::ObjectTemplate> makecomboboxtextobjt(v8::Isolate *iso);
                            static v8::Local<v8::ObjectTemplate> makescrolledwindowobjt(v8::Isolate *iso);
                                static v8::Local<v8::ObjectTemplate> makepanedobjt(v8::Isolate *iso);
                                    static v8::Local<v8::ObjectTemplate> makeframeobjt(v8::Isolate *iso);
                                    static v8::Local<v8::ObjectTemplate> maketoolbarobjt(v8::Isolate *iso);
                                    static v8::Local<v8::ObjectTemplate> maketoolbuttonobjt(v8::Isolate *iso);
                                    static v8::Local<v8::ObjectTemplate> maketextviewobjt(v8::Isolate *iso);


    //constructor
    static void newbutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newspinbutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newcheckbutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newswitch(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newentry(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newlabel(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newimage(const v8::FunctionCallbackInfo<v8::Value> & args);
     static void newprogressbar(const v8::FunctionCallbackInfo<v8::Value> & args);

      static void newtoolpalette(const v8::FunctionCallbackInfo<v8::Value> & args);
       static void newmessagedialog(const v8::FunctionCallbackInfo<v8::Value> & args);
        static void newpnotebook(const v8::FunctionCallbackInfo<v8::Value> & args);
         static void newpaboutdialog(const v8::FunctionCallbackInfo<v8::Value> & args);

    static void newbox(const v8::FunctionCallbackInfo<v8::Value> & args);
     static void newbuttonbox(const v8::FunctionCallbackInfo<v8::Value> & args);
      static void newgrid(const v8::FunctionCallbackInfo<v8::Value> & args);
       static void neweventbox(const v8::FunctionCallbackInfo<v8::Value> & args);

    static void newfilechooser(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newfilechooserdialog(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newfontchooserdialog(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newcolorchooserdialog(const v8::FunctionCallbackInfo<v8::Value> & args);
        static void newdialog(const v8::FunctionCallbackInfo<v8::Value> & args);
        static void newcombobox(const v8::FunctionCallbackInfo<v8::Value> & args);
        static void newcomboboxtext(const v8::FunctionCallbackInfo<v8::Value> & args);
         static void newsearchentry(const v8::FunctionCallbackInfo<v8::Value> & args);
          static void newsearchbar(const v8::FunctionCallbackInfo<v8::Value> & args);
          static void newframe(const v8::FunctionCallbackInfo<v8::Value> & args);
          static void newpaned(const v8::FunctionCallbackInfo<v8::Value> & args);
           static void newnotebook(const v8::FunctionCallbackInfo<v8::Value> & args);
           static void newscrolledwindow(const v8::FunctionCallbackInfo<v8::Value> & args);

           



    static void newtoolbar(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newtoolbutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newradiobutton(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newstatusbar(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newinfobar(const v8::FunctionCallbackInfo<v8::Value> & args);
    static void newwindow(const v8::FunctionCallbackInfo<v8::Value> & args);



    //aplication  main 
    static Glib::RefPtr<Gtk::Application> app;
};


#endif