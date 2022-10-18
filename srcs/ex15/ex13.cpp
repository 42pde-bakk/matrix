//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cstdio>
#include <cassert>


int test_ex13() {
	ft::Matrix<std::complex<float> > u;
	size_t	rank;

	u = {{1.0if, 0.0if, 0.0if},
		 {0.0if, 1.0if, 0.0if},
		 {0.0if, 0.0if, 1.0if}};
	rank = u.rank();
	std::cout << "rank is " << rank << "\n";
//	assert(rank == 3);

	u = {{1.0if, 2.0if, 0.0if, 0.0if},
		 {2.0if, 4.0if, 0.0if, 0.0if},
		 {-1.0if, 2.0if, 1.0if, 1.0if}};
	rank = u.rank();
	std::cout << "rank is " << rank << "\n";
//	assert(rank == 2);

	u = {{8.0if, 5.0if, -2.0if},
		 {4.0if, 7.0if, 20.0if,},
		 {7.0if, 6.0if, 1.0if},
		 {21.0if, 18.0if, 7.0if}};
	rank = u.rank();
	std::cout << "rank is " << rank << "\n";
//	assert(rank == 3);

	std::cout << "All done with ex13\n";
	return (0);
}
