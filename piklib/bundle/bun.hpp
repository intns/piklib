#ifndef _PIKLIB_BUNDLE_HPP
#define _PIKLIB_BUNDLE_HPP

#include "../pik_format.hpp"
#include <string>

namespace piklib {
enum class BundleContentIndicator : u8 {
    PCR = 0x00, // Particles
    BTI = 0x01, // Binary Texture Image
    DCA = 0x02, // Keyframed Animation
    DCK = 0x03  // Interpolated Keyframe Animation
};

struct bun_entry {
    bun_entry() = default;
    ~bun_entry() = default;

    u8 m_contentIndicator = 0;
    std::vector<u8> m_fileContents;
    std::string m_fileName;
};

struct BUN : public pik_format {
    BUN() = default;
    virtual ~BUN() = default;

    void read(util::fstream_reader&) override;
    const char* getExtension() override { return ".bun"; }

    std::vector<bun_entry> m_entries;
};
}

#endif