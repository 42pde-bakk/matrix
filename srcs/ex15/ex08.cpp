//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int test_ex08() {
	ft::Matrix<std::complex<float> > u;
	std::complex<float> res;

	u = {{1.0if, 0.0if}, {0.0if, 1.0if}};
	res = u.trace();
	std::cout << res << '\n';
	assert(feq(res, 2.0if));

	u = {{2.0if, -5.0if, 0.0if}, {4.0if, 3.0if, 7.0if}, {-2.0if, 3.0if, 4.0if}};
	res = u.trace();
	std::cout << res << '\n';
	assert(feq(res, 9.0if));

	u = {{-2.0if, -8.0if, 4.0if}, {1.0if, -23.0if, 4.0if}, {0.0if, 6.0if, 4.0if}};
	res = u.trace();
	std::cout << res << '\n';
	assert(feq(res, -21.0if));

	std::cout << "All done with ex08\n";
	return (0);
}
