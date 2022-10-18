//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


void	test_mul_vec() {
	ft::Matrix<std::complex<float> > u = ft::Matrix<std::complex<float> >({{1.0if, 0.0if}, {0.0if, 1.0if}});
	ft::Vector<std::complex<float> > v = ft::Vector<std::complex<float> >({4.0if, 2.0if});
	auto res = u.mul_vec(v);
	std::cout << res << "\n";
	assert(feq(res[0], 4.0if) && feq(res[1], 2.0if));

	u = {{2.0if, 0.0if}, {0.0if, 2.0if}};
	v = {4.0if, 2.0if};
	res = u.mul_vec(v);
	std::cout << res << "\n";
	assert(feq(res[0], 8.0if) && feq(res[1], 4.0if));

	u = {{2.0if, -2.0if}, {-2.0if, 2.0if}};
	v = {4.0if, 2.0if};
	res = u.mul_vec(v);
	std::cout << res << "\n";
	assert(feq(res[0], 4.0if) && feq(res[1], -4.0if));
}

void	test_mul_mat() {
	ft::Matrix<std::complex<float> > u({{1.0if, 0.0if}, {0.0if, 1.0if}});
	ft::Matrix<std::complex<float> > u2({{1.0if, 0.0if}, {0.0if, 1.0if}});
	ft::Matrix<std::complex<float> > res = u.mul_mat(u2);
	std::cout << res << "\n";
	assert(feq(res[0][0], 1.0if) && feq(res[0][1], 0.0if));
	assert(feq(res[1][0], 0.0if) && feq(res[1][1], 1.0if));

	u = {{1.0if, 0.0if}, {0.0if, 1.0if}};
	u2 = {{2.0if, 1.0if}, {4.0if, 2.0if}};
	res = u.mul_mat(u2);
	std::cout << res << "\n";
	assert(feq(res[0][0], 2.0if) && feq(res[0][1], 1.0if));
	assert(feq(res[1][0], 4.0if) && feq(res[1][1], 2.0if));

	u =  {{3.0if, -5.0if}, {6.0if, 8.0if}};
	u2 = {{2.0if, 1.0if}, {4.0if, 2.0if}};
	res = u.mul_mat(u2);
	std::cout << res << "\n";
	assert(feq(res[0][0], -14.0if) && feq(res[0][1], -7.0if));
	assert(feq(res[1][0], 44.0if) && feq(res[1][1], 22.0if));
}

void test_07() {
	test_mul_vec();
	test_mul_mat();
	std::cout << "All done with ex07\n";
}
