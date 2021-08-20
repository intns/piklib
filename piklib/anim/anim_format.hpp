#ifndef _PIKLIB_ANIM_FORMAT_HPP
#define _PIKLIB_ANIM_FORMAT_HPP

#include <piklib/pik_format.hpp>
#include <vector>

namespace piklib {
struct anim_joint {
    anim_joint() = default;
    ~anim_joint() = default;

    u32 m_index = 0;
    s32 m_parent = 0;
};

struct anim_format : public piklib::pik_format {
    anim_format() = default;
    virtual ~anim_format() = default;

    u32 m_frameCount = 0;
    std::vector<f32> m_scaling;
    std::vector<f32> m_rotation;
    std::vector<f32> m_translation;
};
}

#endif