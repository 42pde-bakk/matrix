//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


void	test_mul_vec() {
	ft::Matrix<float> u = ft::Matrix<float>({{1.0, 0.0}, {0.0, 1.0}});
	ft::Vector<float> v = ft::Vector<float>({4.0, 2.0});
	auto res = u.mul_vec(v);
	std::cout << res << "\n";
	assert(feq(res[0], 4.0) && feq(res[1], 2.0));

	u = {{2.0, 0.0}, {0.0, 2.0}};
	v = {4.0, 2.0};
	res = u.mul_vec(v);
	std::cout << res << "\n";
	assert(feq(res[0], 8.0) && feq(res[1], 4.0));

	u = {{2.0, -2.0}, {-2.0, 2.0}};
	v = {4.0, 2.0};
	res = u.mul_vec(v);
	std::cout << res << "\n";
	assert(feq(res[0], 4.0) && feq(res[1], -4.0));
}

void	test_mul_mat() {
	ft::Matrix<float> u({{1.0, 0.0}, {0.0, 1.0}});
	ft::Matrix<float> u2({{1.0, 0.0}, {0.0, 1.0}});
	ft::Matrix<float> res = u.mul_mat(u2);
	std::cout << res << "\n";
	assert(feq(res[0][0], 1.0) && feq(res[0][1], 0.0));
	assert(feq(res[1][0], 0.0) && feq(res[1][1], 1.0));

	u = {{1.0, 0.0}, {0.0, 1.0}};
	u2 = {{2.0, 1.0}, {4.0, 2.0}};
	res = u.mul_mat(u2);
	std::cout << res << "\n";
	assert(feq(res[0][0], 2.0) && feq(res[0][1], 1.0));
	assert(feq(res[1][0], 4.0) && feq(res[1][1], 2.0));

	u =  {{3.0, -5.0}, {6.0, 8.0}};
	u2 = {{2.0, 1.0}, {4.0, 2.0}};
	res = u.mul_mat(u2);
	std::cout << res << "\n";
	assert(feq(res[0][0], -14.0) && feq(res[0][1], -7.0));
	assert(feq(res[1][0], 44.0) && feq(res[1][1], 22.0));
}

int main() {
	test_mul_vec();
	test_mul_mat();
	std::cout << "All done with ex07\n";
	return (0);
}
