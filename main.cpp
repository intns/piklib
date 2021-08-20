#include <piklib/anim/dca.hpp>

int main(int argc, char** argv)
{
    std::ifstream dca_file("unit-test/wait.dca", std::ios_base::binary);
    util::fstream_reader dca_reader(dca_file, 0, util::fstream_reader::Endianness::Big);
    piklib::DCA dca;
    dca.read(dca_reader);

    return 0;
}