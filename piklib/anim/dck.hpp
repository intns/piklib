#ifndef _PIKLIB_DCK_HPP
#define _PIKLIB_DCK_HPP

#include <array>
#include <piklib/anim/anim_format.hpp>

namespace piklib {
struct dck_joint : public piklib::anim_joint {
    dck_joint() = default;
    ~dck_joint() = default;

    std::array<u32, 3> m_sxParam = { 0, 0, 0 }, m_syParam = { 0, 0, 0 }, m_szParam = { 0, 0, 0 };
    std::array<u32, 3> m_rxParam = { 0, 0, 0 }, m_ryParam = { 0, 0, 0 }, m_rzParam = { 0, 0, 0 };
    std::array<u32, 3> m_txParam = { 0, 0, 0 }, m_tyParam = { 0, 0, 0 }, m_tzParam = { 0, 0, 0 };
};

struct DCK : public piklib::anim_format {
    DCK() = default;
    virtual ~DCK() = default;

    const char* getExtension() override { return ".dck"; }
    void read(util::fstream_reader& reader) override;

    std::vector<dck_joint> m_joints;
};
}

#endif