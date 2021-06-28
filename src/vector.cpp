#include "vector.hpp"

namespace la
{

std::ostream& operator<<(std::ostream& os, const vector& vec) {
        os << "[";
        for(auto cit = vec.vec_.cbegin(); cit != vec.vec_.cend(); cit++) {
            os << *cit;
            if (cit+1 != vec.vec_.cend()) {
                os << ",";
            }
        }
        os << "]";
        return os;
    }

vector operator*(const vector& other, int64_t n) {
        vector result(other.vec_.size());
        for (size_t i = 0; i < other.vec_.size(); i++) {
            result.vec_[i] = other.vec_[i] * n;
        }
        return result;
    }

vector operator*(int64_t n, const vector& other) {
    vector result(other.vec_.size());
    for (size_t i = 0; i < other.vec_.size(); i++) {
        result.vec_[i] = n * other.vec_[i];
    }
    return result;
}

vector zero(size_t dimension)  {
    return vector(dimension, 0);
}


}

