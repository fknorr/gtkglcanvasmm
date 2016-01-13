/**
 *  Copyright (c) 2016 Fabian Knorr <fbknorr@gmail.com>
 *
 * This file is part of gtkglcanvasmm.
 *
 * gtkglcanvasmm is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * gtkglcanvasmm is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtkglmm/canvas.h>
#include <gtkglmm/private/canvas_p.h>

#include <gtkmm/private/widget_p.h>
#include <gtkgl/canvas.h>

using namespace GtkGL;


Glib::RefPtr<Canvas>
Glib::wrap(GtkGLCanvas* object, bool take_copy) {
    return Glib::RefPtr<Canvas>(
        dynamic_cast<Canvas*> (Glib::wrap_auto((GObject*)(object), take_copy)));
}


const Glib::Class &
Canvas_Class::init() {
    if(!gtype_) {
        // create the GType if necessary
        // Glib::Class has to know the class init function to clone custom types.
        class_init_func_ = &Canvas_Class::class_init_function;

        // Create the wrapper type, with the same class/instance size as the base type.
        register_derived_type(gtk_gl_canvas_get_type());
    }
    return *this;
}


void
Canvas_Class::class_init_function(void* g_class, void* class_data) {
    const auto klass = static_cast<BaseClassType*>(g_class);
    CppClassParent::class_init_function(klass, class_data);
}


Glib::ObjectBase *
Canvas_Class::wrap_new(GObject* object) {
    return new Canvas((GtkGLCanvas*)object);
}


GtkGLCanvas *
Canvas::gobj_copy() {
    reference();
    return gobj();
}


Canvas::Canvas(const Glib::ConstructParams& construct_params)
    : Gtk::Widget(construct_params) {
}


Canvas::Canvas(GtkGLCanvas* castitem)
    : Gtk::Widget((GtkWidget*)(castitem)){
}


Canvas::Canvas(Canvas&& src) noexcept
    : Gtk::Widget(std::move(src)) {
}

Canvas& Canvas::operator=(Canvas&& src) noexcept {
    Gtk::Widget::operator=(std::move(src));
    return *this;
}

Canvas::~Canvas() noexcept {
}


Canvas::CppClassType Canvas::canvas_class_; // initialize static member


GType Canvas::get_type() {
    return canvas_class_.init().get_type();
}


GType Canvas::get_base_type() {
    return gtk_gl_canvas_get_type();
}


Canvas::Canvas()
    // Mark this class as non-derived to allow C++ vfuncs to be skipped.
    : Glib::ObjectBase(0),
    Gtk::Widget(Glib::ConstructParams(canvas_class_.init())) {
}
