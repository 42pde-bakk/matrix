//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


void test_ex06() {
	auto u = ft::Vector<std::complex<float> >({0.0if, 0.0if, 1.0if});
	auto v = ft::Vector<std::complex<float> >({1.0if, 0.0if, 0.0if});
	auto res = ft::cross_product(u, v);
	std::cout << res << "\n";
//	assert(feq(res[0], 0.0if) && feq(res[1], 1.0if) && feq(res[2], 0.0if));

	u = {1.0if, 2.0if, 3.0if};
	v = {4.0if, 5.0if, 6.0if};
	res = ft::cross_product(u, v);
	res = ft::cross_product(u, v);
	std::cout << res << "\n";
//	assert(feq(res[0], -3.0if) && feq(res[1], 6.0if) && feq(res[2], -3.0if));

	u = {4.0if, 2.0if, -3.0if};
	v = {-2.0if, -5.0if, 16.0if};
	res = ft::cross_product(u, v);
	std::cout << res << "\n";
//	assert(feq(res[0], 17.0if) && feq(res[1], -58.0if) && feq(res[2], -16.0if));

	std::cout << "All done with ex06\n";
}
