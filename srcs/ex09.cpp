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

int main() {
	ft::Matrix<float>	m({{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}});
	ft::Matrix<float>	t = m.transpose();
	std::cout << "Original matrix:\n" << m << '\n';
	std::cout << "Transposed matrix:\n" << t << '\n';
	for (size_t row_nb = 0; row_nb < 3; row_nb++) {
		for (size_t col_nb = 0; col_nb < 3; col_nb++) {
			assert(feq(t[row_nb][col_nb], m[col_nb][row_nb]));
		}
	}

	std::cout << "All done with ex07\n";
	return (0);
}
