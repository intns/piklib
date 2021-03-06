#include <piklib/piklib.hpp>

int main(int argc, char** argv)
{
    std::ifstream dca_file("unit-test/wait.dca", std::ios_base::binary);
    util::fstream_reader dca_reader(dca_file, 0, util::fstream_reader::Endianness::Big);
    piklib::DCA dca;
    dca.read(dca_reader);
    dca_file.close();

    std::ifstream dck_file("unit-test/pellet1.dck", std::ios_base::binary);
    util::fstream_reader dck_reader(dck_file, 0, util::fstream_reader::Endianness::Big);
    piklib::DCK dck;
    dck.read(dck_reader);
    dck_file.close();

    std::ifstream bti_file("unit-test/z_btn.bti", std::ios_base::binary);
    util::fstream_reader bti_reader(bti_file, 0, util::fstream_reader::Endianness::Big);
    piklib::BTI bti;
    bti.read(bti_reader);
    bti_file.close();

    std::ifstream txe_file("unit-test/rootRing.txe", std::ios_base::binary);
    util::fstream_reader txe_reader(txe_file, 0, util::fstream_reader::Endianness::Big);
    piklib::TXE txe;
    txe.read(txe_reader);
    txe_file.close();

    std::ifstream bun_file("unit-test/screen.bun", std::ios_base::binary);
    util::fstream_reader bun_reader(bun_file, 0, util::fstream_reader::Endianness::Big);
    piklib::BUN bun;
    bun.read(bun_reader);
    bun_file.close();

    std::ifstream anm_file("unit-test/kabekuiA.anm", std::ios_base::binary);
    util::fstream_reader anm_reader(anm_file, 0, util::fstream_reader::Endianness::Big);
    piklib::ANM anm;
    anm.read(anm_reader);
    anm_file.close();

    std::ifstream dir_file("unit-test/tekis.dir", std::ios_base::binary);
    util::fstream_reader dir_reader(dir_file, 0, util::fstream_reader::Endianness::Big);
    piklib::DIR dir;
    dir.setFilename("unit-test/tekis.dir");
    dir.read(dir_reader);
    dir_file.close();

    return 0;
}