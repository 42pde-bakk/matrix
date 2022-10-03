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
#include <iomanip>

constexpr double EPSILON = 0.0001;

bool	floats_equal(double a, double b) {
//	std::cerr << "a = " << a << ", b = " << b << ", diff = " << fabs(a - b) << "\n";
	return (fabs(a - b) < EPSILON);
}

int main() {
	auto u = ft::Vector<float>({0.0, 0.0, 0.0});
	std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(floats_equal(u.norm(), 0.0));
	assert(floats_equal(u.norm_1(), 0.0));
	assert(floats_equal(u.norm_inf(), 0.0));

	u = {1.0, 2.0, 3.0};
	std::cout << std::setprecision(8) << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(floats_equal(u.norm_1(), 6.0));
	assert(floats_equal(u.norm(), 3.7416575));
	assert(floats_equal(u.norm_inf(), 3.0));

	u = {-1.0, -2.0};
	std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(floats_equal(u.norm_1(), 3.0));
	assert(floats_equal(u.norm(), 2.23607));
	assert(floats_equal(u.norm_inf(), 2.0));

	return (0);
}
