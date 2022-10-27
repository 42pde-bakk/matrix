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
	assert(inverse == ft::Matrix<float>({{0.649425287, 0.097701149, -0.655172414},
										 {-0.781609195, -0.126436782, 0.965517241},
										 {0.143678161, 0.074712644, -0.206896552}}));

	std::cout << "A matrix multiplied by its inverse gives the identity matrix.\nSo let's try that out:\n";
	ft::Matrix<float>	identity = u.mul_mat(inverse);
	std::cout << identity << "\n\n";

	/*
	 * Tests from the evalsheet
	 */

	u = {{1.0, 0.0}, {0.0, 1.0}};
	auto v = u.inverse();

	assert(u.inverse() == ft::Matrix<float>({{1.0, 0.0}, {0.0, 1.0}}));

	u = {{2.0, 0.0}, {0.0, 2.0}};
	assert(u.inverse() == ft::Matrix<float>({{0.5, 0.0}, {0.0, 0.5}}));

	u = {{0.5, 0.0}, {0.0, 0.5}};
	assert(u.inverse() == ft::Matrix<float>({{2.0, 0.0}, {0.0, 2.0}}));

	std::cout << "here\n";
	u = {{0.0, 1.0}, {1.0, 0.0}};
	assert(u.inverse() == ft::Matrix<float>({{0.0, 1.0}, {1.0, 0.0}}));

	u = {{1.0, 2.0}, {3.0, 4.0}};
	assert(u.inverse() == ft::Matrix<float>({{-2.0, 1.0}, {1.5, -0.5}}));

	u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
	assert(u.inverse() == ft::Matrix<float>({{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}}));


	std::cout << "All done with ex12\n";
	return (0);
}
