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
#include "filter_dialog.hh"

#include <gtkglmm/init.h>


int
main(int argc, char **argv) {
    Glib::init();
    GtkGL::init();

    auto application = Gtk::Application::create(argc, argv,
            "com.github.fknorr.gtkglcanvasmm.example");

    GtkGLExample::MainWindow main_window;
    main_window.signal_delete_event().connect([&](GdkEventAny *) {
        application->quit();
        return false;
    });

    return application->run(main_window);
}
