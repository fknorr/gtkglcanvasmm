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

#include <gtkglmm/init.h>
#include <gtkglmm/canvas.h>
#include <gtkglmm/private/canvas_p.h>

#include <gtkgl/canvas.h>


void
GtkGL::init() {
    // Map gtypes to gtkmm wrapper-creation functions:
    Glib::wrap_register(gtk_gl_canvas_get_type(), &Canvas_Class::wrap_new);

    // Register the gtkmm gtypes:
    Canvas::get_type();
}
