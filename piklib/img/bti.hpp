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

            
    s8 m_format;
    s8 m_alphaEnabled;
    s8 m_wrapS;
    s8 m_wrapT;
    s8 m_unknown;
    s8 m_paletteFormat;
    u16 m_paletteEntryCount;
    u32 m_paletteOffset;
    u32 m_borderColor;
    s8 m_minFilter;
    s8 m_magFilter;
    s16 m_unknown2;
    s8 m_mipCount;
    s8 m_unknown3;
    s16 m_lodBias;
    u32 m_dataOffset = 32;
    std::vector<u8> m_paletteData;
};
}

#endif