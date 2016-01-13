#pragma once

#include <glibmm/private/object_p.h>
#include <glibmm/class.h>


namespace GtkGL {
    class Canvas_Class;
}


class GtkGL::Canvas_class : public Glib::Class {
public:
    typedef Canvas CppObjectType;
    typedef GtkGLCanvas BaseObjectType;
    typedef GtkGLCanvasClass BaseClassType;
    typedef Gtk::Widget_Class CppClassParent;
    typedef GtkWidgetClass BaseClassParent;

    friend class Canvas;

    const Glib::Class& init();

    static void class_init_function(void* g_class, void* class_data);

    static Glib::ObjectBase* wrap_new(GObject*);
};
