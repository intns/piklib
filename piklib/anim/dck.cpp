#include <piklib/anim/dck.hpp>

namespace piklib {
void DCK::read(util::fstream_reader& reader)
{
    m_joints.resize(reader.readU32());
    m_frameCount = reader.readU32();

    m_scaling.resize(reader.readU32());
    for (f32& i : m_scaling) {
        i = reader.readF32();
    }

    m_rotation.resize(reader.readU32());
    for (f32& i : m_rotation) {
        i = reader.readF32();
    }

    m_translation.resize(reader.readU32());
    for (f32& i : m_translation) {
        i = reader.readF32();
    }

    for (dck_joint& joint : m_joints) {
        joint.m_index = reader.readU32();
        joint.m_parent = reader.readS32();
        for (u32 i = 0; i < 3; i++) {
            joint.m_sxParam[i] = reader.readU32();
            joint.m_syParam[i] = reader.readU32();
            joint.m_szParam[i] = reader.readU32();
        }
        for (u32 i = 0; i < 3; i++) {
            joint.m_rxParam[i] = reader.readU32();
            joint.m_ryParam[i] = reader.readU32();
            joint.m_rzParam[i] = reader.readU32();
        }
        for (u32 i = 0; i < 3; i++) {
            joint.m_txParam[i] = reader.readU32();
            joint.m_tyParam[i] = reader.readU32();
            joint.m_tzParam[i] = reader.readU32();
        }
    }
}
}