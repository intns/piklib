#include "dir.hpp"

namespace piklib {
void DIR::read(util::fstream_reader& reader)
{
    m_fileSize = reader.readU32();
    m_entries.resize(reader.readU32());

    std::ifstream arcFile(m_baseName + ".arc", std::ios_base::binary);
    if (!arcFile.is_open()) {
        return;
    }

    for (dir_entry& entry : m_entries) {
        entry.m_offset = reader.readU32();
        entry.m_fileContents.resize(reader.readU32());
        entry.m_fileName.resize(reader.readU32());
        for (s8& i : entry.m_fileName) {
            i = reader.readS8();
        }

        arcFile.seekg(entry.m_offset);
        if (!arcFile.read(reinterpret_cast<s8*>(entry.m_fileContents.data()), entry.m_fileContents.size())) {
            return;
        }
    }

    arcFile.close();
}
}