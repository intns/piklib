#include "bun.hpp"

namespace piklib {
void BUN::read(util::fstream_reader& reader)
{
    m_entries.resize(reader.readU32());
    for (bun_entry& entry : m_entries) {
        // Downsized cast because unused 3 bytes (micro-optimisation, don't run unused read functions)
        entry.m_contentIndicator = static_cast<u8>(reader.readU32());
        entry.m_fileContents.resize(reader.readU32());
        entry.m_fileName.resize(reader.readU32());
        for (s8& i : entry.m_fileName) {
            i = reader.readS8();
        }

        reader.read_buffer(reinterpret_cast<s8*>(entry.m_fileContents.data()), entry.m_fileContents.size());
    }
}
}