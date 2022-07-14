#ifndef JLTK
#define JLTK

#include <FL/Fl.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Scroll.H>
#include "../defs.h"

class Jltk
{
private:
public:
    // global object of jltk
    static v8::Local<v8::ObjectTemplate> jltkobjt;
    // object of jltkobjt they is bindings of fltk classes
    static v8::Local<v8::ObjectTemplate> windowobjt;
    static v8::Local<v8::ObjectTemplate> buttonobjt;
    static v8::Local<v8::ObjectTemplate> browserobjt;
    static v8::Local<v8::ObjectTemplate> labelobjt;
    static v8::Local<v8::ObjectTemplate> imageobjt;
    static v8::Local<v8::ObjectTemplate> inputobjt;
    static v8::Local<v8::ObjectTemplate> progressobjt;
    static v8::Local<v8::ObjectTemplate> spinnerobjt;
    static v8::Local<v8::ObjectTemplate> tooltipobjt;
    static v8::Local<v8::ObjectTemplate> filechooserobjt;
    static v8::Local<v8::ObjectTemplate> colorchooserobjt;
    static v8::Local<v8::ObjectTemplate> boxobjt;
    static v8::Local<v8::ObjectTemplate> menubarobjt;
    static v8::Local<v8::ObjectTemplate> menubuttonobjt;
    static v8::Local<v8::ObjectTemplate> menuitemobjt;
    static v8::Local<v8::ObjectTemplate> fileinputobjt;
    static v8::Local<v8::ObjectTemplate> sliderobjt;
    static v8::Local<v8::ObjectTemplate> treeobjt;
    static v8::Local<v8::ObjectTemplate> treeitemobjt;
    static v8::Local<v8::ObjectTemplate> texteditorobjt;
    static v8::Local<v8::ObjectTemplate> radiobuttonobjt;
    static v8::Local<v8::ObjectTemplate> valuesliderobjt;
    static v8::Local<v8::ObjectTemplate> scrollobjt;
    static v8::Local<v8::ObjectTemplate> scrollbarobjt;
    // function which make jltk objects
    static v8::Local<v8::ObjectTemplate> makejltkobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makewindowobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makebuttonobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makebrowserobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makelabelobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makeimageobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makeinputobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makeprogressobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makespinnerobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> maketooltipobjt(v8::Isolate *isolate);
    static v8::Local<v8::ObjectTemplate> makefilechooserobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makeWindowobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makeboxobjt(v8::Isolate *iso);
    static v8::Local<v8::ObjectTemplate> makemenubarobjt(v8::Isolate *iso);
    // jltk functions
    static void newwindow(const v8::FunctionCallbackInfo<v8::Value> &args);

    static Fl_Window *getwindow(v8::Local<v8::Object> obj);
    static Fl_Label *getlabel(v8::Local<v8::Object> obj);
    static Fl_Box *getbox(v8::Local<v8::Object> obj);
    static Fl_Button *getbutton(v8::Local<v8::Object> obj);
    static Fl_Image *getimage(v8::Local<v8::Object> obj);
    static Fl_Progress *getprogress(v8::Local<v8::Object> obj);
    static Fl_Double_Window *getdoublewindow(v8::Local<v8::Object> obj);
    static Fl_Tooltip *gettooltip(v8::Local<v8::Object> obj);
    static Fl_File_Chooser *getfilechooser(v8::Local<v8::Object> obj);
    static Fl_Color_Chooser *getcolorchooser(v8::Local<v8::Object> obj);
    static Fl_Spinner *getspinner(v8::Local<v8::Object> obj);
    static Fl_Menu_Bar *getmenubar(v8::Local<v8::Object> obj);
    static Fl_Tree *gettree(v8::Local<v8::Object> obj);
    static Fl_Tree_Item *gettreeitem(v8::Local<v8::Object> obj);
    static Fl_Text_Editor *gettexteditor(v8::Local<v8::Object> obj);
    static Fl_Value_Slider *getvalueslider(v8::Local<v8::Object> obj);
    static Fl_Scroll *getscroll(v8::Local<v8::Object> obj);
    static Fl_Scrollbar *getscrollbar(v8::Local<v8::Object> obj);
    static Fl_Radio_Button *getradiobutton(v8::Local<v8::Object> obj);
    static Fl_File_Input *getfileinput(v8::Local<v8::Object> obj);
};



#endif