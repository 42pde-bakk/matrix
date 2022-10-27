//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int main() {
	ft::Matrix<float> u;
	ft::Matrix<float> echelon;
	u = {{1.0, 0.0, 0.0},
		 {0.0, 1.0, 0.0},
		 {0.0, 0.0, 1.0} };
	echelon = u.row_echelon();
	std::cout << echelon << '\n';
	assert(echelon == ft::Matrix<float>({{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}}));

	u = {{1.0, 2.0},
		 {3.0, 4.0}};
	echelon = u.row_echelon();
	std::cout << echelon << '\n';
	assert(echelon == ft::Matrix<float>({{1.0, 0.0}, {0.0, 1.0}}));

	u = {{1.0, 2.0},
		 {2.0, 4.0}};
	echelon = u.row_echelon();
	std::cout << echelon << '\n';
	assert(echelon == ft::Matrix<float>({{1.0, 2.0}, {0.0, 0.0}}));

	u = {{8.0, 5.0, -2.0, 4.0, 28.0},
		 {4.0, 2.5, 20.0, 4.0, -4.0},
		 {8.0, 5.0, 1.0, 4.0, 17.0}};
	echelon = u.row_echelon();
	std::cout << echelon << '\n';

	/*
	 * Tests from the evalsheet
	 */
	u = {{0.0, 0.0}, {0.0, 0.0}};
	echelon = u.row_echelon();
	assert(echelon == ft::Matrix<float>({{0.0, 0.0}, {0.0, 0.0}}));

	u = {{1.0, 0.0}, {0.0, 1.0}};
	echelon = u.row_echelon();
	assert(echelon == ft::Matrix<float>({{1.0, 0.0}, {0.0, 1.0}}));

	u = {{4.0, 2.0}, {2.0, 1.0}};
	echelon = u.row_echelon();
	assert(echelon == ft::Matrix<float>({{1.0, 0.5}, {0.0, 0.0}}));

	u = {{-7.0, 2.0}, {4.0, 8.0}};
	echelon = u.row_echelon();
	assert(echelon == ft::Matrix<float>({{1.0, 0.0}, {0.0, 1.0}}));

	u = {{0.0, 0.0}, {0.0, 0.0}};
	echelon = u.row_echelon();
	assert(echelon == ft::Matrix<float>({{0.0, 0.0}, {0.0, 0.0}}));

	u = {{1.0, 2.0}, {4.0, 8.0}};
	echelon = u.row_echelon();
	assert(echelon == ft::Matrix<float>({{1.0, 2.0}, {0.0, 0.0}}));

	std::cout << "All done with ex10\n";
	return (0);
}
