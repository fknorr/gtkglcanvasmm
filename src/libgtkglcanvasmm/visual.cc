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


#define GTKGLCANVASMM_IMPLEMENTATION
#include <gtkglmm/visual.h>


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wsuggest-override"
#endif

#include <gtkgl/canvas.h>
#include <gtkgl/visual.h>

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif


using namespace GtkGL;


void VisualList::Destructor::operator()(_GtkGLVisualList *pointer) noexcept {
    gtk_gl_visual_list_free(pointer);
};


VisualList::VisualList() noexcept = default;


VisualList::VisualList(_GtkGLVisualList *list) noexcept
    : list(list) {
}


VisualList::VisualList(VisualList &&move_from) noexcept = default;

VisualList &VisualList::operator=(VisualList &&move_from) noexcept = default;

VisualList::~VisualList() = default;


VisualList::ConstIterator
VisualList::begin() const noexcept {
    return ConstIterator(list ? list->entries : nullptr);
}


VisualList::ConstIterator
VisualList::end() const noexcept {
    return ConstIterator(list ? list->entries + list->count : nullptr);
}


VisualList
VisualList::choose(std::vector<GtkGL::Requirement> requirements) const {
    requirements.push_back({ GtkGL::NONE, GtkGL::EXACTLY, 0 });
    return VisualList(gtk_gl_choose_visuals(list.get(), reinterpret_cast<GtkGLRequirement*>(
            requirements.data())));
}
