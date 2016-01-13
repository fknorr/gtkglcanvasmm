# Copyright (c) 2016, Fabian Knorr
#
# This file is part of gtkglcanvas.
#
# gtkglcanvasmm is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# gtkglcanvasmm is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with gtkglcanvasmm.  If not, see <http://www.gnu.org/licenses/>.


lib_LTLIBRARIES =  \
	$(top_builddir)/libgtkglcanvasmm.la

__top_builddir__libgtkglcanvasmm_la_SOURCES = \
	visual.cc \
	canvas.cc \
    init.cc

gtkglmmdir = $(includedir)/gtkglmm
gtkglmm_HEADERS = \
    $(top_srcdir)/include/gtkglmm/canvas.h \
    $(top_srcdir)/include/gtkglmm/visual.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gtkglcanvasmm.pc

__top_builddir__libgtkglcanvasmm_la_CPPFLAGS = \
    -I$(top_srcdir)/include \
	$(GLIBMM_CFLAGS) \
	$(GTKMM3_CFLAGS) \
    $(GtkGLCanvas_CFLAGS)

__top_builddir__libgtkglcanvasmm_la_LIBADD = \
    $(GLIBMM_LIBS) \
    $(GTKMM3_LIBSS) \
    $(GtkGLCanvas_LIBS)
