//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int main() {
	auto u = ft::Vector<float>({0.0, 0.0, 1.0});
	auto v = ft::Vector<float>({1.0, 0.0, 0.0});
	auto res = ft::cross_product(u, v);
	std::cout << res << "\n";
	assert(feq(res[0], 0.0) && feq(res[1], 1.0) && feq(res[2], 0.0));

	u = {1.0, 2.0, 3.0};
	v = {4.0, 5.0, 6.0};
	res = ft::cross_product(u, v);
	res = ft::cross_product(u, v);
	std::cout << res << "\n";
	assert(feq(res[0], -3.0) && feq(res[1], 6.0) && feq(res[2], -3.0));

	u = {4.0, 2.0, -3.0};
	v = {-2.0, -5.0, 16.0};
	res = ft::cross_product(u, v);
	std::cout << res << "\n";
	assert(feq(res[0], 17.0) && feq(res[1], -58.0) && feq(res[2], -16.0));

	std::cout << "All done with ex06\n";
	return (0);
}
