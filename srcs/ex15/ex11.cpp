//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int test_ex11() {
	{
		ft::Matrix<std::complex<float> > u({
			{1.0if, -1.0if},
			{-1.0if, 1.0if}
		});
		std::complex<float> determinant = u.determinant();
		std::cout << "first determinant is " << determinant << "\n";
	//	assert(feq(determinant, 0.0if));
	}
	{
		ft::Matrix<std::complex<float> > u({
			{2.0if, 0.0if, 0.0if},
			{0.0if, 2.0if, 0.0if},
			{0.0if, 0.0if, 2.0if}
		});
		std::complex<float> determinant = u.determinant();
		std::cout << "second determinant is " << determinant << "\n";
	//	assert(feq(determinant, 8.0if));
	}
	{
		ft::Matrix<std::complex<float> > u({
			{8.0if, 5.0if, -2.0if},
			{4.0if, 7.0if, 20.0if},
			{7.0if, 6.0if, 1.0if}
		});
		std::complex<float> determinant = u.determinant();
		std::cout << "third determinant is " << determinant << "\n";
	//	assert(feq(determinant, -174.0if));
	}
	{
		ft::Matrix<std::complex<float> > u({
			{8.0if,  5.0if,  -2.0if, 4.0if},
			{4.0if,  2.5if,  20.0if, 4.0if},
			{8.0if,  5.0if,  1.0if,  4.0if},
			{28.0if, -4.0if, 17.0if, 1.0if}
		});
		std::complex<float> determinant = u.determinant();
		std::cout << "fourth and last determinant is " << determinant << "\n";
	//	assert(feq(determinant, 1032.0if));
	}
	std::cout << "All done with ex11\n";
	return (0);
}
