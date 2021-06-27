#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <initializer_list>

#include <cstdio>

namespace la
{

// TODO only support integer in current.
class vector
{
    friend std::ostream& operator<<(std::ostream& os, const vector& vec);
    friend vector operator*(int64_t n, const vector& other);
    friend vector operator*(const vector& other, int64_t n);
public:
    vector() = default;
    vector(size_t n) :vec_(std::vector<int64_t>(n)) {};
    vector(std::initializer_list<int64_t> l) {
        vec_ = std::vector<int64_t>(l);
    }

    // copy constructor
    vector(vector& other) {
        std::cout << "copy" << std::endl;
        vec_ = other.vec_; // copy vector
    }

    // copy move constructor
    vector(vector&& other) {
        std::cout << "move" << std::endl;
        using std::swap;
        swap(other.vec_, vec_);
    }

    ~vector() = default;

    vector operator+(const vector& lhs) {
        if (lhs.vec_.size() != vec_.size()) {
            throw std::runtime_error("Error in adding, Length of vectors must be same");
        }
        vector result(vec_.size());
        for (size_t i = 0; i < vec_.size(); i++) {
            result.vec_[i] = vec_[i] + lhs.vec_[i];
        }
        return result;
    }

    vector operator-(const vector& lhs) {
        if (lhs.vec_.size() != vec_.size()) {
            throw std::runtime_error("Error in adding, Length of vectors must be same");
        }
        vector result(vec_.size());
        for (size_t i = 0; i < vec_.size(); i++) {
            result.vec_[i] = vec_[i] - lhs.vec_[i];
        }
        return result;
    }


private:
    std::vector<int64_t> vec_;
};

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

};

#endif /* LINEAR_ALGEBRA_H */