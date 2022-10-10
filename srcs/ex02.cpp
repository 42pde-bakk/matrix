//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <vector>
#include <stdexcept>
#include <cstdio>
#include <stdexcept>
#include <cassert>
#include <limits>
#include <cmath>

template <typename V>
V	lerp(const V& u, const V& v, float t) {
	if (t < 0.0 || t > 1.0)
		return V();
	V out = (u + (v - u) * t);
	std::cerr << out << "\n";
	return (out);
}


int main() {
	assert(lerp(0.0, 1.0, 0.0) == 0.0);
	assert(lerp(0.0, 1.0, 1.0) == 1.0);
	assert(lerp(0.0, 1.0, 0.5) == 0.5);
	assert(feq(lerp(21.0, 42.0, 0.3), 27.3));

	auto vec1 = ft::Vector<float>({2.0, 1.0});
	auto vec2 = ft::Vector<float>({4.0, 2.0});
	auto res = lerp(vec1, vec2, 0.3);
	assert(feq(res[0], 2.6) && feq(res[1], 1.3));

	auto matrix1 = ft::Matrix<float>({{2.0, 1.0}, {3.0, 4.0}});
	auto matrix2 = ft::Matrix<float>({{20.0, 10.0}, {30.0, 40.0}});
	auto res2 = lerp(matrix1, matrix2, 0.5);
	assert(res2[0][0] == 11.0 && res2[0][1] == 5.5);
	assert(res2[1][0] == 16.5 && res2[1][1] == 22.0);
}
