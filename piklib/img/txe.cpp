#include "txe.hpp"

namespace piklib {
void TXE::read(util::fstream_reader& reader)
{
    m_dimensions.first = reader.readU16();
    m_dimensions.second = reader.readU16();
    m_format = reader.readU16();
    reader.readU16();

    m_imageData.resize(reader.readU32());
    for (u32 i = 0; i < 0x20 - (reader.getPosition() % 0x20); i++) {
        reader.readU8();
    }

    reader.read_buffer(reinterpret_cast<s8*>(m_imageData.data()), m_imageData.size());
}
}