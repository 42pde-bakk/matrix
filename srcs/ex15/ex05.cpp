//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


void test_ex05() {
	auto u = ft::Vector<std::complex<float> >({1.0if, 0.0if});
	auto v = ft::Vector<std::complex<float> >({1.0if, 0.0if});
	auto res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, 1.0if));

	u = {1.0if, 0.0if};
	v = {0.0if, 1.0if};
	res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, 0.0if));

	u = {-1.0if, 1.0if};
	v = {1.0if, -1.0if};
	res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, -1.0if));

	u = {2.0if, 1.0if};
	v = {4.0if, 2.0if};
	res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, 1.0if));

	u = {1.0if, 2.0if, 3.0if};
	v = {4.0if, 5.0if, 6.0if};
	res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, 0.974631846if));

	std::cout << "All done with ex05\n";
}
