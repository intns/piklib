#ifndef _FSTREAM_READER_HPP
#define _FSTREAM_READER_HPP

#include <fstream>
#include <type_traits>
#include <types.hpp>
#include <vector>

namespace util {

class fstream_reader {
public:
    enum class Endianness : u8 {
        Little = 0,
        Big
    };

    fstream_reader(std::ifstream& file, std::size_t position = 0, Endianness endianness = Endianness::Little);
    ~fstream_reader() = default;
    fstream_reader(const fstream_reader&) = delete;
    fstream_reader& operator=(const fstream_reader&) = delete;

    inline const std::ifstream& getStream() const { return m_filestream; }
    inline const std::streampos getRemaining() const { return m_filesize - m_filestream.tellg(); }
    inline const std::streampos getFilesize() const { return m_filesize; }

    inline Endianness& endianness() { return m_endianness; }
    inline const Endianness& endianness() const { return m_endianness; }

    inline void setPosition(std::size_t position)
    {
        if (position <= m_filesize) {
            m_filestream.seekg(position);
        }
    }
    inline const std::streampos getPosition() const { return m_filestream.tellg(); }

    inline void read_buffer(s8* buffer, std::streampos size)
    {
        m_filestream.read(buffer, size);
    }

    inline u8 readU8()
    {
        u8 byte = 0;
        m_filestream.read(reinterpret_cast<s8*>(&byte), 1);
        return byte;
    }
    inline u16 readU16()
    {
        u8 byte0 = readU8();
        u8 byte1 = readU8();

        return (m_endianness == Endianness::Little)
            ? (byte0 | (byte1 << 8))
            : (byte1 | (byte0 << 8));
    }
    inline u32 readU32()
    {
        u8 byte0 = readU8();
        u8 byte1 = readU8();
        u8 byte2 = readU8();
        u8 byte3 = readU8();

        return (m_endianness == Endianness::Little)
            ? (byte0 | (byte1 << 8) | (byte2 << 16) | (byte3 << 24))
            : (byte3 | (byte2 << 8) | (byte1 << 16) | (byte0 << 24));
    }
    inline u64 readU64()
    {
        u32 word0 = readU32();
        u32 word1 = readU32();

        return (m_endianness == Endianness::Little)
            ? (((u64)word0) | ((u64)word1 << 32))
            : (((u64)word1) | ((u64)word0 << 32));
    }

    inline s8 readS8()
    {
        s8 byte = 0;
        m_filestream.read(&byte, 1);
        return byte;
    }
    inline s16 readS16()
    {
        s8 byte0 = readS8();
        s8 byte1 = readS8();

        return (m_endianness == Endianness::Little)
            ? (byte0 | (byte1 << 8))
            : (byte1 | (byte0 << 8));
    }
    inline s32 readS32()
    {
        s8 byte0 = readS8();
        s8 byte1 = readS8();
        s8 byte2 = readS8();
        s8 byte3 = readS8();

        return (m_endianness == Endianness::Little)
            ? (byte0 | (byte1 << 8) | (byte2 << 16) | (byte3 << 24))
            : (byte3 | (byte2 << 8) | (byte1 << 16) | (byte0 << 24));
    }
    inline s64 readS64()
    {
        s32 word0 = readS32();
        s32 word1 = readS32();

        return (m_endianness == Endianness::Little)
            ? (((s64)word0 << 32) | (word1))
            : (((s64)word1 << 32) | (word0));
    }

    std::ifstream& m_filestream;

private:
    std::streampos m_filesize;
    Endianness m_endianness;
};

}

#endif