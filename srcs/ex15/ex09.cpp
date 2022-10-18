//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cstdio>
#include <cassert>


int test_09() {
	ft::Matrix<std::complex<float> >	m({{1.0if, 2.0if, 3.0if}, {4.0if, 5.0if, 6.0if}, {7.0if, 8.0if, 9.0if}});
	ft::Matrix<std::complex<float> >	t = m.transpose();
	std::cout << "Original matrix:\n" << m << '\n';
	std::cout << "Transposed matrix:\n" << t << '\n';
	for (size_t row_nb = 0; row_nb < 3; row_nb++) {
		for (size_t col_nb = 0; col_nb < 3; col_nb++) {
			assert(feq(t[row_nb][col_nb], m[col_nb][row_nb]));
		}
	}

	std::cout << "All done with ex09\n";
	return (0);
}
