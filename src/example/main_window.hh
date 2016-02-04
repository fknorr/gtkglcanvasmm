/**
 * Copyright (c) 2016 Fabian Knorr <fbknorr@gmail.com>
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

#include "gtk_includes.hh"
#include <gtkglmm/canvas.h>
#include <GL/glew.h>


namespace GtkGLExample {
    class MainWindow;
}


class GtkGLExample::MainWindow: public Gtk::Window {
public:
    MainWindow();

private:
    MainWindow(Gtk::Builder &builder);

    // Widgets as fetched from the Gtk::Builder
    GtkGL::Canvas &canvas;
    Gtk::Label &context_info_label, &mouse_info_label;
    Gtk::Button &create_button, &destroy_button, &start_button, &stop_button;

    // Whether the animation is running
    bool running;
    // The current object rotation
    float angle;

    // Drawing modes supported by the active context
    // direct_mode: Drawing a triangle with glBegin() / glEnd()
    // shaders: Drawing a rectangle with shaders and VBOs
    // vaos: Drawing a hexagon with shaders, VBOs and Vertex Array Objects
    gboolean has_direct_mode, has_shaders, has_vaos;

    // The shader program used by draw_with_shaders() and draw_with_vaos()
    GLuint program;
    // Buffers for draw_with_shaders()
    GLuint rect_vertex_buffer, rect_index_buffer;
    // Buffers for draw_with_vaos()
    GLuint hex_vertex_buffer, hex_index_buffer, hex_vao;
    // Uniform / attribute locations in "program"
    GLuint projection_loc, modelview_loc, pos_loc, color_loc;

    void create_context();
    void destroy_context();
    void start_animation();
    void stop_animation();
    void draw();
    void mouse_leave();
    void mouse_move(int x, int y);

    void message_box(Gtk::MessageType type, const Glib::ustring &text);
    void update_context_info();
};

