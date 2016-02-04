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

#include "visual.h"

#include <sigc++/sigc++.h>


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wsuggest-override"
#endif

#include <glibmm.h>
#include <gtkmm/widget.h>
#include <glibmm/ustring.h>

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif


// GTK_GL_TYPE_CANVAS is defined in C GtkGLCanvas library header
#ifndef GTK_GL_TYPE_CANVAS
typedef struct _GtkGLCanvas GtkGLCanvas;
typedef struct _GtkGLCanvasClass GtkGLCanvasClass;
#endif


namespace GtkGL {
    class Canvas_Class;
    class Canvas;
    enum Profile: int;

    void wrap_init();
}


enum GtkGL::Profile: int {
    CORE_PROFILE,
    COMPATIBILITY_PROFILE,
    ES_PROFILE
};


class GtkGL::Canvas : public Gtk::Widget {
public:
    typedef Canvas CppObjectType;
    typedef Canvas_Class CppClassType;
    typedef GtkGLCanvas BaseObjectType;
    typedef GtkGLCanvasClass BaseClassType;

    Canvas();
    Canvas(const Canvas&) = delete;
    Canvas& operator=(const Canvas&) = delete;

    Canvas(Canvas&& src) noexcept;
    Canvas& operator=(Canvas&& src) noexcept;

    virtual ~Canvas() noexcept;

    /**
     * Get the GType for this class, for use with the underlying GObject type system.
     */
    static GType get_type() G_GNUC_CONST;

    static GType get_base_type() G_GNUC_CONST;

    /**
     * Provides access to the underlying C GObject.
     */
    GtkGLCanvas *gobj() { return reinterpret_cast<GtkGLCanvas*>(gobject_); }

    /**
     * Provides access to the underlying C GObject.
     */
    const GtkGLCanvas* gobj() const { return reinterpret_cast<GtkGLCanvas*>(gobject_); }

    /**
     * Provides access to the underlying C instance. The caller is responsible for unrefing it.
     * Use when directly setting fields in structs.
     */
    GtkGLCanvas* gobj_copy();

    VisualList enumerate_visuals();

    bool create_context(const Visual &visual);

    bool create_context(const Visual &visual, unsigned ver_major, unsigned ver_minor,
            Profile profile);

    bool auto_create_context(std::vector<Requirement> requirements = {});

    bool auto_create_context(std::vector<Requirement> requirements, unsigned ver_major,
            unsigned ver_minor, Profile profile);

    void destroy_context();

    bool has_context() const;

    void make_current();

    void display_frame();

private:
    friend class Canvas_Class;
    static CppClassType canvas_class_;

protected:
    explicit Canvas(const Glib::ConstructParams& construct_params);
    explicit Canvas(GtkGLCanvas* castitem);
};


namespace Glib {
    /** A Glib::wrap() method for this object.
     *
     * object: The C instance.
     * take_copy: False if the result should take ownership of the C instance. True if it should
     * take a new copy or ref. A C++ instance that wraps this C instance.
     */
    Glib::RefPtr<GtkGL::Canvas> wrap(GtkGLCanvas* object, bool take_copy = false);
}
