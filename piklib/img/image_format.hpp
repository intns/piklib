#ifndef _PIKLIB_IMG_FORMAT_HPP
#define _PIKLIB_IMG_FORMAT_HPP

#include "../pik_format.hpp"
#include <utility>
#include <vector>

namespace piklib {
struct img_format : public piklib::pik_format {
    img_format() = default;
    virtual ~img_format() = default;

    // X, Y (width, height) respectively
    std::pair<u32, u32> m_dimensions;
    std::vector<u8> m_imageData;
};
}

#endif