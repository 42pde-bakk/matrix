//
// Created by peer on 3-10-22.
//

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

	/*
	 * Tests from the evalsheet
	 */

	u = ft::Matrix<float>({{0.0, 0.0}, {0.0, 0.0}});
	res = u.trace();
	assert(res == 0.0);

	u = ft::Matrix<float>({{1.0, 0.0}, {0.0, 1.0}});
	res = u.trace();
	assert(res == 2.0);

	u = ft::Matrix<float>({{1.0, 2.0}, {3.0, 4.0}});
	res = u.trace();
	assert(res == 5.0);

	u = ft::Matrix<float>({{8.0, -7.0}, {4.0, 2.0}});
	res = u.trace();
	assert(res == 10.0);

	u = ft::Matrix<float>({{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}});
	res = u.trace();
	assert(res == 3.0);

	std::cout << "All done with ex08\n";
	return (0);
}
