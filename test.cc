#include "vector.hpp"


int main() {

    la::vector v1 = {1,2,3,4,5}, v2 = {6, 7, 8, 9, 10};
    try {
        std::cout << v1 + v2 << std::endl;
        std::cout << v1 - v2 << std::endl;
        std::cout << v1*2 << std::endl;
        std::cout << 2*v2 << std::endl;
        std::cout << la::zero(5) + v1 << std::endl;
    }catch(std::exception& e) {
        std::printf("what exception: %s\n", e.what());
    }
    // la::vector v3 = v1 + v2;
    return 0;
}