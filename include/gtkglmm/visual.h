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

#include <memory>
#include <vector>
#include <initializer_list>


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wsuggest-override"
#endif

#include <glibmm.h>

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif


struct _GtkGLVisual;
struct _GtkGLVisualList;
struct _GtkGLFramebufferConfig;
struct _GtkGLRequirement;


namespace GtkGL {

    enum ColorType: int;
    enum TransparentType: int;
    enum Caveat: int;
    enum Attribute: int;
    enum RequirementType: int;

    using Visual = _GtkGLVisual;
    class VisualList;

    using BitSet = unsigned;

#ifndef GTKGLCANVASMM_IMPLEMENTATION
    struct FramebufferConfig;
    struct Requirement;
#else
    using FramebufferConfig = _GtkGLFramebufferConfig;
    using Requirement = _GtkGLRequirement;
#endif

}


enum GtkGL::ColorType: int {
    COLOR_RGBA = 1,
    COLOR_INDEXED = 2
};


enum GtkGL::TransparentType: int {
    TRANSPARENT_NONE,
    TRANSPARENT_RGB,
    TRANSPARENT_INDEX
};


enum GtkGL::Caveat: int {
    CAVEAT_NONE,
    CAVEAT_SLOW,
    CAVEAT_NONCONFORMANT
};


enum GtkGL::Attribute: int {
    NONE,
    ACCELERATED,
    COLOR_TYPES,
    COLOR_BPP,
    FB_LEVEL,
    DOUBLE_BUFFERED,
    STEREO_BUFFERED,
    AUX_BUFFERS,
    RED_COLOR_BPP,
    GREEN_COLOR_BPP,
    BLUE_COLOR_BPP,
    ALPHA_COLOR_BPP,
    DEPTH_BPP,
    STENCIL_BPP,
    RED_ACCUM_BPP,
    GREEN_ACCUM_BPP,
    BLUE_ACCUM_BPP,
    ALPHA_ACCUM_BPP,
    TRANSPARENT_TYPE,
    TRANSPARENT_INDEX_VALUE,
    TRANSPARENT_RED,
    TRANSPARENT_GREEN,
    TRANSPARENT_BLUE,
    TRANSPARENT_ALPHA,
    SAMPLE_BUFFERS,
    SAMPLES_PER_PIXEL,
    CAVEAT
};


enum GtkGL::RequirementType: int {
    PREFERABLY,
    EXACTLY,
    AT_MOST,
    AT_LEAST
};


class GtkGL::VisualList {
public:
    class ConstIterator;

    VisualList() noexcept;

    explicit VisualList(_GtkGLVisualList *list) noexcept;

    VisualList(VisualList &&move_from) noexcept;

    VisualList &operator=(VisualList &&move_from) noexcept;

    ~VisualList();

    ConstIterator begin() const noexcept;

    ConstIterator end() const noexcept;

    VisualList choose(std::vector<Requirement> requirements) const;

private:
    struct Destructor {
        void operator()(_GtkGLVisualList *pointer) noexcept;
    };

    std::unique_ptr<_GtkGLVisualList, Destructor> list;
};


class GtkGL::VisualList::ConstIterator {
public:
    explicit ConstIterator(Visual **ptr) noexcept
        : ptr(ptr) {
    }

    const Visual &operator*() const noexcept {
        return **ptr;
    }

    ConstIterator &operator++() noexcept {
        ++ptr;
        return *this;
    }

    ConstIterator operator++(int) noexcept {
        auto old = *this;
        operator++();
        return old;
    }

    bool operator==(const ConstIterator &rhs) const noexcept {
        return ptr == rhs.ptr;
    }

    bool operator!=(const ConstIterator &rhs) const noexcept {
        return ptr != rhs.ptr;
    }

private:
    Visual **ptr;
};


#ifndef GTKGLCANVASMM_IMPLEMENTATION

struct GtkGL::FramebufferConfig {
public:
    gboolean accelerated;
    BitSet color_types;
    guint color_bpp;
    gint fb_level;
    gboolean double_buffered;
    gboolean stereo_buffered;
    guint aux_buffers;
    guint red_color_bpp;
    guint green_color_bpp;
    guint blue_color_bpp;
    guint alpha_color_bpp;
    guint depth_bpp;
    guint stencil_bpp;
    guint red_accum_bpp;
    guint green_accum_bpp;
    guint blue_accum_bpp;
    guint alpha_accum_bpp;
    TransparentType transparent_type;
    guint transparent_index;
    guint transparent_red;
    guint transparent_green;
    guint transparent_blue;
    guint transparent_alpha;
    guint sample_buffers;
    guint samples_per_pixel;
    Caveat caveat;
};


struct GtkGL::Requirement {
    Attribute attr;
    RequirementType req;
    gint value;
};

#endif
