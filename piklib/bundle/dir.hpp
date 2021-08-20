#ifndef _PIKLIB_ARCHIVED_BUNDLE_HPP
#define _PIKLIB_ARCHIVED_BUNDLE_HPP

#include "../pik_format.hpp"
#include <filesystem>
#include <string>

namespace piklib {
struct dir_entry {
    dir_entry() = default;
    ~dir_entry() = default;

    u32 m_offset = 0;
    std::vector<u8> m_fileContents;
    std::string m_fileName;
};

struct DIR : public pik_format {
    DIR() = default;
    virtual ~DIR() = default;

    // Needs be called before reading
    inline void setFilename(const std::string& name)
    {
        namespace fs = std::filesystem;

        fs::path path(name);
        m_baseName = path.replace_extension().string();
    }

    void read(util::fstream_reader&) override;
    const char* getExtension() override { return ".dir"; }

    u32 m_fileSize = 0;
    std::vector<dir_entry> m_entries;

    // DIR files are split into .dir and .arc
    std::string m_baseName;
};
}

#endif