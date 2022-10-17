//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>
#include <iomanip>


int main() {
	auto u = ft::Vector<float>({0.0, 0.0, 0.0});
	std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm(), 0.0));
	assert(feq(u.norm_1(), 0.0));
	assert(feq(u.norm_inf(), 0.0));

	u = {1.0, 2.0, 3.0};
	std::cout << std::setprecision(8) << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm_1(), 6.0));
	assert(feq(u.norm(), 3.7416575));
	assert(feq(u.norm_inf(), 3.0));

	u = {-1.0, -2.0};
	std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm_1(), 3.0));
	assert(feq(u.norm(), 2.23607));
	assert(feq(u.norm_inf(), 2.0));

	return (0);
}
