//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int test_10() {
	ft::Matrix<std::complex<float> > u;
	ft::Matrix<std::complex<float> > echelon;
	u = {{1.0if, 0.0if, 0.0if},
		 {0.0if, 1.0if, 0.0if},
		 {0.0if, 0.0if, 1.0if} };
	echelon = u.row_echelon();
	std::cout << echelon << '\n';
	assert(echelon == ft::Matrix<std::complex<float> >({{1.0if, 0.0if, 0.0if}, {0.0if, 1.0if, 0.0if}, {0.0if, 0.0, 1.0}}));

	u = {{1.0if, 2.0if},
		 {3.0if, 4.0if}};
	echelon = u.row_echelon();
	std::cout << echelon << '\n';
	assert(echelon == ft::Matrix<std::complex<float> >({{1.0if, 0.0if}, {0.0if, 1.0if}}));

	u = {{1.0if, 2.0if},
		 {2.0if, 4.0if}};
	echelon = u.row_echelon();
	std::cout << echelon << '\n';
	assert(echelon == ft::Matrix<std::complex<float> >({{1.0if, 2.0if}, {0.0if, 0.0if}}));

	u = {{8.0if, 5.0if, -2.0if, 4.0if, 28.0if},
		 {4.0if, 2.5if, 20.0if, 4.0if, -4.0if},
		 {8.0if, 5.0if, 1.0if, 4.0if, 17.0if}};
	echelon = u.row_echelon();
	std::cout << echelon << '\n';

	std::cout << "All done with ex10\n";
	return (0);
}
