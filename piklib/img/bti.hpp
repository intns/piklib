#ifndef _PIKLIB_BTI_HPP
#define _PIKLIB_BTI_HPP

#include "image_format.hpp"

namespace piklib {
enum class BTI_Formats : u8 {
    I4 = 0x00,
    I8 = 0x01,
    IA4 = 0x02,
    IA8 = 0x03,
    RGB565 = 0x04,
    RGB5A3 = 0x05,
    RGBA32 = 0x06,
    C4 = 0x08,
    C8 = 0x09,
    C14X2 = 0x0A,
    CMPR = 0x0E,
};

struct BTI : public img_format {
    BTI() = default;
    virtual ~BTI() = default;

    void read(util::fstream_reader&) override;
    const char* getExtension() override { return ".bti"; }

    s8 m_format = 0;
    s8 m_alphaEnabled = 0;
    s8 m_wrapS = 0;
    s8 m_wrapT = 0;
    s8 m_unknown = 0;
    s8 m_paletteFormat = 0;
    u16 m_paletteEntryCount = 0;
    u32 m_paletteOffset = 0;
    u32 m_borderColor = 0;
    s8 m_minFilter = 0;
    s8 m_magFilter = 0;
    s16 m_unknown2 = 0;
    s8 m_mipCount = 0;
    s8 m_unknown3 = 0;
    s16 m_lodBias = 0;
    u32 m_dataOffset = 32;
    std::vector<u8> m_paletteData;
};
}

#endif