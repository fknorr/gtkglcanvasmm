# Copyright (c) 2016, Fabian Knorr
#
# This file is part of gtkglcanvasmm.
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


check_PROGRAMS = $(top_builddir)/example

__top_builddir__example_SOURCES = \
	main.cc \
    main_window.cc \
    filter_dialog.cc

__top_builddir__example_LDADD = \
	$(top_builddir)/libgtkglcanvasmm.la \
	$(GLIBMM_LIBS) \
	$(GTKMM3_LIBS) \
    $(Epoxy_LIBS)

__top_builddir__example_CPPFLAGS = \
	-I$(top_srcdir)/include \
    $(GLIBMM_CFLAGS) \
    $(GTKMM3_CFLAGS) \
    $(Epoxy_CFLAGS)
