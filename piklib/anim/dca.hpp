#ifndef _PIKLIB_DCA_HPP
#define _PIKLIB_DCA_HPP

#include <array>
#include <piklib/anim/anim_format.hpp>

namespace piklib {
struct dca_joint : public piklib::anim_joint {
    dca_joint() = default;
    ~dca_joint() = default;

    std::array<u32, 3> m_sxParam = { 0, 0, 0 }, m_syParam = { 0, 0, 0 };
    std::array<u32, 3> m_rxParam = { 0, 0, 0 }, m_ryParam = { 0, 0, 0 };
    std::array<u32, 3> m_txParam = { 0, 0, 0 }, m_tyParam = { 0, 0, 0 };
};

struct DCA : public piklib::anim_format {
    DCA() = default;
    virtual ~DCA() = default;

    const char* getExtension() override { return ".dca"; }
    void read(util::fstream_reader& reader) override;

    std::vector<dca_joint> m_joints;
};
}

#endif