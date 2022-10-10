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
	ft::Matrix<float> u;
	float determinant;

	u = {{1.0, -1.0},
		 {-1.0, 1.0}};
	determinant = u.determinant();
	std::cout << "first determinant is " << determinant << "\n";
	assert(feq(determinant, 0.0));

	u = {{2.0, 0.0, 0.0},
		 {0.0, 2.0, 0.0},
		 {0.0, 0.0, 2.0}};
	determinant = u.determinant();
	std::cout << "second determinant is " << determinant << "\n";
	assert(feq(determinant, 8.0));

	u = {{8.0, 5.0, -2.0},
		 {4.0, 7.0, 20.0},
		 {7.0, 6.0, 1.0}};
	determinant = u.determinant();
	std::cout << "third determinant is " << determinant << "\n";
	assert(feq(determinant, -174.0));

	u = {{8.0, 5.0, -2.0, 4.0},
		 {4.0, 2.5, 20.0, 4.0},
		 {8.0, 5.0, 1.0, 4.0},
		 {28.0, -4.0, 17.0, 1.0}};
	determinant = u.determinant();
	std::cout << "fourth and last determinant is " << determinant << "\n";
	assert(feq(determinant, 1032.0));

	std::cout << "All done with ex11\n";
	return (0);
}
