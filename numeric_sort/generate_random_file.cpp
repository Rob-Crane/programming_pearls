#include <cassert>
#include <cstdlib>
#include <fstream>
#include <random>

#define SEED 2011

int randint(int b, int e) {
}

int main(int argc, char *argv[]) {

    assert (argc == 2);

    int n = atoi(argv[1]);

    // Populate values.
    std::vector<int> values;
    values.reserve(n);
    for (int v = 0; v < n; ++v) {
        values.push_back(v);
    }

    // Shuffle values.
    std::mt19937 gen(SEED);
    std::uniform_real_distribution<> dis;
    for (int i = 0; i < values.size(); ++i) {
        std::swap(values[i], values[static_cast<int>(dis(gen) * (values.size() - i)) + i]);
    }

    std::ofstream ofs("numbers.txt");
    for (int v  : values) {
        ofs << v << '\n';
    }



    return 0;
}
