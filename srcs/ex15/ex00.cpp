//
// Created by peer on 2-9-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Vector.hpp"
#include "Matrix.hpp"
#include <cassert>

void test_vector() {
	auto u = ft::Vector<std::complex<float>>({2.if, 3.if});
	auto v = ft::Vector<std::complex<float>>({5.if, 7.if});
	u.add(v);
	assert(u[0] == 7.0if);
	assert(u[1] == 10.0if);

	u = ft::Vector<std::complex<float>>({2.if, 3.if});
	v = ft::Vector<std::complex<float>>({5.if, 7.if});
	u.sub(v);
	assert(u[0] == -3.0if);
	assert(u[1] == -4.0if);

	u = ft::Vector<std::complex<float>>({2.if, 3.if});
	u.scl(2.);
	assert(u[0] == 4.0if);
	assert(u[1] == 6.0if);
}

void	test_matrix() {
	auto u = ft::Matrix<std::complex<float>>({{1.0if, 2.0if}, {3.0if, 4.0if}});
	auto v = ft::Matrix<std::complex<float>>({{7.0if, 4.0if}, {-2.0if, 2.0if}});
	u.add(v);
	std::cout << u << "\n";
	assert(u[0][0] == 8.0if && u[0][1] == 6.0if);
	assert(u[1][0] == 1.0if && u[1][1] == 6.0if);

	u = ft::Matrix<std::complex<float>>({{1.0if, 2.0if}, {3.0if, 4.0if}});
	v = ft::Matrix<std::complex<float>>({{7.0if, 4.0if}, {-2.0if, 2.0if}});
	u.sub(v);
	std::cout << u << "\n";
	assert(u[0][0] == -6.0if && u[0][1] == -2.0if);
	assert(u[1][0] == 5.0if && u[1][1] == 2.0if);

	u = ft::Matrix<std::complex<float>>({{1.0if, 2.0if}, {3.0if, 4.0if}});
	u.scl(2.0);
	std::cout << u << "\n";
	assert(u[0][0] == 2.0if && u[0][1] == 4.0if);
	assert(u[1][0] == 6.0if && u[1][1] == 8.0if);

}

int main() {
	test_vector();
	test_matrix();
}
