//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


void test_ex03() {
	auto u = ft::Vector<std::complex<float> >({0.0if, 0.0if});
	auto v = ft::Vector<std::complex<float> >({1.0if, 1.0if});
	std::cout << "dot product between {0.0, 0.0} and {1.0, 1.0} gives " << u.dot(v) << "\n";
//	assert(feq(u.dot(v), 0.0if));

	u = {1.0if, 1.0if};
	v = {1.0if, 1.0if};
	std::cout << "dot product between {1.0, 1.0} and {1.0, 1.0} gives " << u.dot(v) << "\n";
//	assert(feq(u.dot(v), 2.0if));

	u = {-1.0, 6.0};
	v = {3.0, 2.0};
	std::cout << "dot product between {-1.0, 6.0} and {3.0, 2.0} gives " << u.dot(v) << "\n";
//	assert(feq(u.dot(v), 9.0if));

	std::cout << "All done with ex03\n";
}
