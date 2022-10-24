//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int main() {
	ft::Matrix<float> u;
	ft::Matrix<float> inverse;

	u = {{1.0, 0.0, 0.0},
		 {0.0, 1.0, 0.0},
		 {0.0, 0.0, 1.0}};
	inverse = u.inverse();
	std::cout << inverse << "\n";
	assert(inverse == ft::Matrix<float>({{1.0, 0.0, 0.0},
										{0.0, 1.0, 0.0},
										{0.0, 0.0, 1.0}}));

	u = {{2.0, 0.0, 0.0},
		 {0.0, 2.0, 0.0},
		 {0.0, 0.0, 2.0}};
	inverse = u.inverse();
	std::cout << inverse << "\n";
	assert(inverse == ft::Matrix<float>({{0.5, 0.0, 0.0},
										 {0.0, 0.5, 0.0},
										 {0.0, 0.0, 0.5}}));

	u = {{8.0, 5.0, -2.0},
		 {4.0, 7.0, 20.0},
		 {7.0, 6.0, 1.0}};
	inverse = u.inverse();
	std::cout << inverse << "\n";
	assert(inverse == ft::Matrix<float>({{0.64943, -0.78161, 0.14368},
										 {0.097701, -0.12644, 0.074713},
										 {-0.65517, 0.96552, -0.2069}}));

	/*
	 * Tests from the evalsheet
	 */

	u = {{1.0, 0.0}, {0.0, 1.0}};
	auto v = u.inverse();
	std::cout << v << "\n";
	assert(u.inverse() == ft::Matrix<float>({{1.0, 0.0}, {0.0, 1.0}}));

	u = {{2.0, 0.0}, {0.0, 2.0}};
	assert(u.inverse() == ft::Matrix<float>({{0.5, 0.0}, {0.0, 0.5}}));

	u = {{0.5, 0.0}, {0.0, 0.5}};
	assert(u.inverse() == ft::Matrix<float>({{2.0, 0.0}, {0.0, 2.0}}));

	u = {{0.0, 1.0}, {1.0, 0.0}};
	assert(u.inverse() == ft::Matrix<float>({{0.0, 1.0}, {1.0, 0.0}}));

	u = {{1.0, 2.0}, {3.0, 4.0}};
	assert(u.inverse() == ft::Matrix<float>({{-2.0, 1.0}, {1.5, -0.5}}));

	u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
	assert(u.inverse() == ft::Matrix<float>({{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}}));


	std::cout << "All done with ex12\n";
	return (0);
}
