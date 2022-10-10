//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int main() {
	auto u = ft::Vector<float>({1.0, 0.0});
	auto v = ft::Vector<float>({1.0, 0.0});
	auto res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, 1.0));

	u = {1.0, 0.0};
	v = {0.0, 1.0};
	res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, 0.0));

	u = {-1.0, 1.0};
	v = {1.0, -1.0};
	res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, -1.0));

	u = {2.0, 1.0};
	v = {4.0, 2.0};
	res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, 1.0));

	u = {1.0, 2.0, 3.0};
	v = {4.0, 5.0, 6.0};
	res = ft::angle_cos(u, v);
	std::cout << res << "\n";
	assert(feq(res, 0.974631846));

	std::cout << "All done with ex05\n";
	return (0);
}
