//
// Created by peer on 3-10-22.
//

#include <complex>
using namespace std::complex_literals;

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int main() {
	ft::Matrix<float> u;
	float res;

	u = {{1.0, 0.0}, {0.0, 1.0}};
	res = u.trace();
	std::cout << res << '\n';
	assert(feq(res, 2.0));

	u = {{2.0, -5.0, 0.0}, {4.0, 3.0, 7.0}, {-2.0, 3.0, 4.0}};
	res = u.trace();
	std::cout << res << '\n';
	assert(feq(res, 9.0));

	u = {{-2.0, -8.0, 4.0}, {1.0, -23.0, 4.0}, {0.0, 6.0, 4.0}};
	res = u.trace();
	std::cout << res << '\n';
	assert(feq(res, -21.0));

	std::cout << "All done with ex08\n";
	return (0);
}
