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

constexpr double EPSILON = 0.00001;

bool	floats_equal(double a, double b) {
	return (fabs(a - b) < EPSILON);
}

int main() {
	auto u = ft::Vector<float>({0.0, 0.0, 1.0});
	auto v = ft::Vector<float>({1.0, 0.0, 0.0});
	auto res = ft::cross_product(u, v);
	std::cout << res << "\n";
	assert(floats_equal(res[0], 0.0) && floats_equal(res[1], 1.0) && floats_equal(res[2], 0.0));

	u = {1.0, 2.0, 3.0};
	v = {4.0, 5.0, 6.0};
	res = ft::cross_product(u, v);
	res = ft::cross_product(u, v);
	std::cout << res << "\n";
	assert(floats_equal(res[0], -3.0) && floats_equal(res[1], 6.0) && floats_equal(res[2], -3.0));

	u = {4.0, 2.0, -3.0};
	v = {-2.0, -5.0, 16.0};
	res = ft::cross_product(u, v);
	std::cout << res << "\n";
	assert(floats_equal(res[0], 17.0) && floats_equal(res[1], -58.0) && floats_equal(res[2], -16.0));

	std::cout << "All done with ex06\n";
	return (0);
}
