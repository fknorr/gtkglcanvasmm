/* Copyright (c) 2016 Fabian Knorr <fbknorr@gmail.com>
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

#pragma once

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wsuggest-override"
#endif

#include <glibmm/private/object_p.h>
#include <glibmm/class.h>

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif



namespace GtkGL {
    class Canvas_Class;
}


class GtkGL::Canvas_Class : public Glib::Class {
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
