//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>

template <typename V>
V	lerp(const V& u, const V& v, float t) {
	if (t < 0.0 || t > 1.0)
		return V();
	V out = (u + (v - u) * t);
	// Implementing this to use Fused Multiply Accumulate is easy enough for floats
	// But I don't know how to handle it for Vectors or Matrices like:
	// std::fma(Matrix<T> x, Matrix<T> y, Matrix<T> z);
	std::cerr << out << "\n";
	return (out);
}


void test_ex02() {
	assert(lerp(0.0if, 1.0if, 0.0) == 0.0if);
	assert(lerp(0.0if, 1.0if, 1.0) == 1.0if);
	assert(lerp(0.0if, 1.0if, 0.5) == 0.5if);
	assert(lerp(21.0if, 42.0if, 0.3) == 27.3if);

	auto vec1 = ft::Vector<std::complex<float> >({2.0if, 1.0if});
	auto vec2 = ft::Vector<std::complex<float> >({4.0if, 2.0if});
	auto res = lerp(vec1, vec2, 0.3);
	assert(res[0] == 2.6if && res[1] == 1.3if);

	auto matrix1 = ft::Matrix<std::complex<float> >({{2.0if, 1.0if}, {3.0if, 4.0if}});
	auto matrix2 = ft::Matrix<std::complex<float> >({{20.0if, 10.0if}, {30.0if, 40.0if}});
	auto res2 = lerp(matrix1, matrix2, 0.5);
	assert(res2[0][0] == 11.0if && res2[0][1] == 5.5if);
	assert(res2[1][0] == 16.5if && res2[1][1] == 22.0if);

	std::cout << "All done with ex02\n";
}
