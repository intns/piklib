#ifndef _PIKLIB_PIK_FORMAT_HPP
#define _PIKLIB_PIK_FORMAT_HPP

#include <util/fstream_reader.hpp>

namespace piklib {
struct pik_format {
    pik_format() = default;
    virtual ~pik_format() = default;

    // Must include the last 4 letters of the extension, e.g. .dir, .arc, .bun.
    // etc.
    virtual const char* getExtension() = 0;

    virtual void read(util::fstream_reader& reader) = 0;
};
}

#endif