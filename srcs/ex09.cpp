//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cstdio>
#include <cassert>


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

	m = {{0.0, 0.0}, {0.0, 0.0}};
	assert(m.transpose() == ft::Matrix<float>({{0.0, 0.0}, {0.0, 0.0}}));

	m = {{1.0, 0.0}, {0.0, 1.0}};
	assert(m.transpose() == ft::Matrix<float>({{1.0, 0.0}, {0.0, 1.0}}));

	m = {{1.0, 2.0}, {3.0, 4.0}};
	assert(m.transpose() == ft::Matrix<float>({{1.0, 3.0}, {2.0, 4.0}}));

	m = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
	assert(m.transpose() == ft::Matrix<float>({{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}}));

	m = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
	assert(m.transpose() == ft::Matrix<float>({{1.0, 3.0, 5.0}, {2.0, 4.0, 6.0}}));

	std::cout << "All done with ex09\n";
	return (0);
}
