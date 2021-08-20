#include <piklib/piklib.hpp>

int main(int argc, char** argv)
{
    std::ifstream dca_file("unit-test/wait.dca", std::ios_base::binary);
    util::fstream_reader dca_reader(dca_file, 0, util::fstream_reader::Endianness::Big);
    piklib::DCA dca;
    dca.read(dca_reader);

    std::ifstream dck_file("unit-test/pellet1.dck", std::ios_base::binary);
    util::fstream_reader dck_reader(dca_file, 0, util::fstream_reader::Endianness::Big);
    piklib::DCK dck;
    dck.read(dck_reader);

    return 0;
}