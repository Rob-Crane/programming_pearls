#include <cassert>
#include <cstdint>
#include <fstream>
#include <vector>

using FieldType = uint64_t;
const int kBitsPerField = 8 * sizeof(FieldType);
constexpr int kMaxInt = 10000000;

class BitField {
public:
    BitField(int64_t size) : bits_(size / kBitsPerField + 1) {}
    void set(int n) {
       bits_[n / kBitsPerField] |= 1 << n % kBitsPerField;
    }
    bool isSet(int n) const {
        return bits_[n / kBitsPerField] & 1 << n % kBitsPerField;
    }
private:
    std::vector<FieldType> bits_;
};

int main() {

    std::ifstream istrm("numbers.txt");
    int n;
    BitField bit_field(kMaxInt);
    while (istrm >> n) {
        assert (n < kMaxInt);
        bit_field.set(n);
    }

    std::ofstream ofs("sorted.txt");
    for (int i = 0; i < kMaxInt; ++i) {
        if (bit_field.isSet(i)) {
            ofs << i << '\n';
        }
    }

    return 0;
}
