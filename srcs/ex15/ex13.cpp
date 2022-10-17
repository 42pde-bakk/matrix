//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cstdio>
#include <cassert>


int main() {
	ft::Matrix<float> u;
	size_t	rank;

	u = {{1.0, 0.0, 0.0},
		 {0.0, 1.0, 0.0},
		 {0.0, 0.0, 1.0}};
	rank = u.rank();
	std::cout << "rank is " << rank << "\n";
	assert(rank == 3);

	u = {{1.0, 2.0, 0.0, 0.0},
		 {2.0, 4.0, 0.0, 0.0},
		 {-1.0, 2.0, 1.0, 1.0}};
	rank = u.rank();
	std::cout << "rank is " << rank << "\n";
	assert(rank == 2);

	u = {{8.0, 5.0, -2.0},
		 {4.0, 7.0, 20.0,},
		 {7.0, 6.0, 1.0},
		 {21.0, 18.0, 7.0}};
	rank = u.rank();
	std::cout << "rank is " << rank << "\n";
	assert(rank == 3);

	std::cout << "All done with ex13\n";
	return (0);
}
