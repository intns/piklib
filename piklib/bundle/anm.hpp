#ifndef _PIKLIB_ANM_BUNDLE_HPP
#define _PIKLIB_ANM_BUNDLE_HPP

#include "bun.hpp"

namespace piklib {
struct ANM : public BUN {
    ANM() = default;
    virtual ~ANM() = default;

    const char* getExtension() override { return ".anm"; }
};
}

#endif