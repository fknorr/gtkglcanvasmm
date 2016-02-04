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


#include "main_window.hh"


using namespace GtkGLExample;


template<typename Widget>
static Widget &
get_widget(Gtk::Builder &builder, const Glib::ustring &name) {
    Widget *widget{};
    builder.get_widget(name, widget);
    if (!widget) {
        throw std::runtime_error("Widget " + name + "not found in Glade file");
    }
    return *widget;
}


MainWindow::MainWindow(Gtk::Builder &builder)
    : Gtk::Window(std::move(get_widget<Gtk::Window>(builder, "window"))),

      canvas(get_widget<GtkGL::Canvas>(builder, "canvas")),
      create_button(get_widget<Gtk::Button>(builder, "create-button")),
      destroy_button(get_widget<Gtk::Button>(builder, "destroy-button")),
      start_button(get_widget<Gtk::Button>(builder, "start-anim-button")),
      stop_button(get_widget<Gtk::Button>(builder, "stop-anim-button")),
      context_info_label(get_widget<Gtk::Label>(builder, "context-info-label")),
      mouse_info_label(get_widget<Gtk::Label>(builder, "mouse-info-label")) {

    canvas.signal_draw().connect([this](const Cairo::RefPtr<Cairo::Context> &) {
        draw();
        return true;
    });

    canvas.signal_leave_notify_event().connect([this](GdkEventCrossing *) {
        mouse_leave();
        return false;
    });

    canvas.signal_motion_notify_event().connect([this](GdkEventMotion *) {
        mouse_move();
        return false;
    });

    create_button.signal_clicked().connect([this] {
        create_context();
    });

    destroy_button.signal_clicked().connect([this] { 
        destroy_context();
    });

    start_button.signal_clicked().connect([this] { 
        start_animation();
    });

    stop_button.signal_clicked().connect([this] {
        stop_animation();
    });
}


MainWindow::MainWindow()
    : MainWindow(*Gtk::Builder::create_from_file("res/example/example.ui").operator->()) {
}


void
MainWindow::create_context() {

}


void
MainWindow::destroy_context() {

}


void
MainWindow::start_animation() {

}


void
MainWindow::stop_animation() {

}


void
MainWindow::draw() {

}


void
MainWindow::mouse_leave() {

}


void
MainWindow::mouse_move() {

}

