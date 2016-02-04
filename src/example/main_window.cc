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

    canvas.signal_motion_notify_event().connect([this](GdkEventMotion *event) {
        mouse_move(event->x, event->y);
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

    Glib::signal_timeout().connect([this] {
        if (running) {
            angle += 2;
            canvas.queue_draw();
        }
        return true;
    }, 1000 / 60);

    update_context_info();
}


MainWindow::MainWindow()
    : MainWindow(*Gtk::Builder::create_from_file("res/example/example.ui").operator->()) {
}


void
MainWindow::create_context() {
    if (canvas.has_context()) {
        message_box(Gtk::MESSAGE_ERROR, "Context exists already");
    } else {
        if (canvas.auto_create_context()) {
            draw();
        } else {
            message_box(Gtk::MESSAGE_ERROR, "Error creating context");
        }
    }

    update_context_info();
}


void
MainWindow::destroy_context() {
    if (!canvas.has_context()) {
        message_box(Gtk::MESSAGE_ERROR, "No context present");
    } else {
        running = false;
        canvas.destroy_context();
    }

    update_context_info();
}


void
MainWindow::start_animation() {
    if (!canvas.has_context()) {
        message_box(Gtk::MESSAGE_ERROR, "No context present");
    } else {
        running = true;
    }
}


void
MainWindow::stop_animation() {
    running = false;
}


void
MainWindow::draw() {
    auto size = canvas.get_allocation();
    float aspect = static_cast<float>(size.get_width()) / size.get_height();

    glClearColor(0.1f, 0.1f, 0.1f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, size.get_width(), size.get_height());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(angle, 0, 0, 1);
    glScalef(0.8, 0.8, 0.8);

    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        glVertex2f(0, 1);
        glColor3f(0, 1, 0);
        glVertex2f(-sinf(M_PI/3), -cosf(M_PI/3));
        glColor3f(0, 0, 1);
        glVertex2f(sinf(M_PI/3), -cosf(M_PI/3));
    glEnd();

    canvas.display_frame();
}


void
MainWindow::mouse_leave() {
    mouse_info_label.set_text("");
}


void
MainWindow::mouse_move(int x, int y) {
    mouse_info_label.set_text("Mouse at (" + std::to_string(x) + ", " + std::to_string(y) + ")");
}


void
MainWindow::message_box(Gtk::MessageType type, const Glib::ustring &text) {
    Gtk::MessageDialog dialog(*this, text, false, type);
    dialog.run();
}


void
MainWindow::update_context_info(void) {
    bool present = canvas.has_context();
    context_info_label.set_text(present
            ? std::string("OpenGL Version ") + reinterpret_cast<const char*>(glGetString(GL_VERSION))
            : "No context present");

    create_button.set_sensitive(!present);
    destroy_button.set_sensitive(present);
    start_button.set_sensitive(present);
    stop_button.set_sensitive(present);
}
