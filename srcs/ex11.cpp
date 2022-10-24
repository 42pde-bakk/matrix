//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int main() {
	{
		ft::Matrix<float> u({
			{1.0, -1.0},
			{-1.0, 1.0}
		});
		float determinant = u.determinant();
		std::cout << "first determinant is " << determinant << "\n";
		assert(feq(determinant, 0.0));
	}
	{
		ft::Matrix<float> u({
			{2.0, 0.0, 0.0},
			{0.0, 2.0, 0.0},
			{0.0, 0.0, 2.0}
		});
		float determinant = u.determinant();
		std::cout << "second determinant is " << determinant << "\n";
		assert(feq(determinant, 8.0));
	}
	{
		ft::Matrix<float> u({
			{8.0, 5.0, -2.0},
			{4.0, 7.0, 20.0},
			{7.0, 6.0, 1.0}
		});
		float determinant = u.determinant();
		std::cout << "third determinant is " << determinant << "\n";
		assert(feq(determinant, -174.0));
	}
	{
		ft::Matrix<float> u({
			{8.0,  5.0,  -2.0, 4.0},
			{4.0,  2.5,  20.0, 4.0},
			{8.0,  5.0,  1.0,  4.0},
			{28.0, -4.0, 17.0, 1.0}
		});
		float determinant = u.determinant();
		std::cout << "fourth and last determinant is " << determinant << "\n";
		assert(feq(determinant, 1032.0));
	}

	/*
	 * Tests from the evalsheet
	 */
	ft::Matrix<float>	u;
	u = {{0.0, 0.0}, {0.0, 0.0}};
	assert(u.determinant() == 0.0);

	u = {{1.0, 0.0}, {0.0, 1.0}};
	assert(u.determinant() == 1.0);

	u = {{2.0, 0.0}, {0.0, 2.0}};
	assert(u.determinant() == 4.0);

	u = {{1.0, 1.0}, {1.0, 1.0}};
	assert(u.determinant() == 0.0);

	u = {{0.0, 1.0}, {1.0, 0.0}};
	assert(u.determinant() == -1.0);

	u = {{1.0, 2.0}, {3.0, 4.0}};
	assert(u.determinant() == -2.0);

	u = {{-7.0, 5.0}, {4.0, 6.0}};
	assert(u.determinant() == -62.0);

	u = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
	assert(u.determinant() == 1.0);

	std::cout << "All done with ex11\n";
	return (0);
}
