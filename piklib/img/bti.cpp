#include "bti.hpp"
#include <iostream>

namespace piklib {
void BTI::read(util::fstream_reader& reader)
{
    m_format = reader.readS8();
    m_alphaEnabled = reader.readS8();
    m_dimensions.first = reader.readU16();
    m_dimensions.second = reader.readU16();
    m_wrapS = reader.readS8();
    m_wrapT = reader.readS8();
    m_unknown = reader.readS8();
    m_paletteFormat = reader.readS8();
    m_paletteEntryCount = reader.readU16();
    m_paletteOffset = reader.readU32();
    m_borderColor = reader.readU32();
    m_minFilter = reader.readS8();
    m_magFilter = reader.readS8();
    m_unknown2 = reader.readS16();
    m_mipCount = reader.readS8();
    m_unknown3 = reader.readS8();
    m_lodBias = reader.readS16();
    m_dataOffset = reader.readU32();

    reader.setPosition(m_dataOffset);
    const u32 fileSz = static_cast<u32>(reader.getFilesize());
    const u32 imgSz = (!m_paletteOffset) ? fileSz - m_dataOffset : m_paletteOffset - m_dataOffset;

    m_imageData.resize(imgSz);
    reader.read_buffer(reinterpret_cast<s8*>(m_imageData.data()), imgSz);

    if (m_paletteOffset) {
        reader.setPosition(m_paletteOffset);
        m_paletteData.resize(m_paletteEntryCount * 2);
        reader.read_buffer(reinterpret_cast<s8*>(m_paletteData.data()), m_paletteData.size());
    }
}
}