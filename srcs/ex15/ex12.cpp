//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int test_ex12() {
	ft::Matrix<std::complex<float> > u;
	ft::Matrix<std::complex<float> > inverse;

	u = {{1.0if, 0.0if, 0.0if},
		 {0.0if, 1.0if, 0.0if},
		 {0.0if, 0.0if, 1.0if}};
	inverse = u.inverse();
	std::cout << inverse << "\n";
	assert(inverse == ft::Matrix<std::complex<float> >({{1.0if, 0.0if, 0.0if},
										{0.0if, 1.0if, 0.0if},
										{0.0if, 0.0if, 1.0if}}));

	u = {{2.0if, 0.0if, 0.0if},
		 {0.0if, 2.0if, 0.0if},
		 {0.0if, 0.0if, 2.0if}};
	inverse = u.inverse();
	std::cout << inverse << "\n";
	assert(inverse == ft::Matrix<std::complex<float> >({{0.5if, 0.0if, 0.0if},
										 {0.0if, 0.5if, 0.0if},
										 {0.0if, 0.0if, 0.5if}}));

	u = {{8.0if, 5.0if, -2.0if},
		 {4.0if, 7.0if, 20.0if},
		 {7.0if, 6.0if, 1.0if}};
	inverse = u.inverse();
	std::cout << inverse << "\n";
	assert(inverse == ft::Matrix<std::complex<float> >({{0.64943if, -0.78161if, 0.14368if},
										 {0.097701if, -0.12644if, 0.074713if},
										 {-0.65517if, 0.96552if, -0.2069if}}));


	std::cout << "All done with ex12\n";
	return (0);
}
