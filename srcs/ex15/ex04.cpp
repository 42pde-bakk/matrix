//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>
#include <iomanip>


int test_04() {
	auto u = ft::Vector<std::complex<float> >({0.0if, 0.0if, 0.0if});
	std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm(), 0.0if));
	assert(feq(u.norm_1(), 0.0if));
	assert(feq(u.norm_inf(), 0.0if));

	u = {1.0if, 2.0if, 3.0if};
	std::cout << std::setprecision(8) << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm_1(), 6.0if));
	assert(feq(u.norm(), 3.7416575if));
	assert(feq(u.norm_inf(), 3.0if));

	u = {-1.0if, -2.0if};
	std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm_1(), 3.0if));
	assert(feq(u.norm(), 2.23607if));
	assert(feq(u.norm_inf(), 2.0if));

	return (0);
}
