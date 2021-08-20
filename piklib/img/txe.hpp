#ifndef _PIKLIB_TXE_HPP
#define _PIKLIB_TXE_HPP

#include "image_format.hpp"

namespace piklib {
enum class TXE_Formats : u16 {
    RGB565 = 0x00,
    CMPR = 0x01,
    RGB5A3 = 0x02,
    I4 = 0x03,
    I8 = 0x04,
    IA4 = 0x05,
    IA8 = 0x06,
    RGBA8 = 0x07
};

struct TXE : public img_format {
    TXE() = default;
    virtual ~TXE() = default;

    void read(util::fstream_reader&) override;
    const char* getExtension() override { return ".txe"; }

    u16 m_format = 0;
};
}

#endif