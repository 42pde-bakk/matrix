//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>


int main() {
	auto u = ft::Vector<float>({0.0, 0.0});
	auto v = ft::Vector<float>({1.0, 1.0});
	std::cout << "dot product between {0.0, 0.0} and {1.0, 1.0} gives " << u.dot(v) << "\n";
	assert(feq(u.dot(v), 0.0));

	u = {1.0, 1.0};
	v = {1.0, 1.0};
	std::cout << "dot product between {1.0, 1.0} and {1.0, 1.0} gives " << u.dot(v) << "\n";
	assert(feq(u.dot(v), 2.0));

	u = {-1.0, 6.0};
	v = {3.0, 2.0};
	std::cout << "dot product between {-1.0, 6.0} and {3.0, 2.0} gives " << u.dot(v) << "\n";
	assert(feq(u.dot(v), 9.0));

	/*
	 * Tests from the evalsheet
	 */
	u = {0.0, 0.0};
	v = {0.0, 0.0};
	assert(u.dot(v) == 0.0);

	u = {1.0, 0.0};
	v = {0.0, 0.0};
	assert(u.dot(v) == 0.0);

	u = {1.0, 0.0};
	v = {1.0, 0.0};
	assert(u.dot(v) == 1.0);

	u = {1.0, 0.0};
	v = {0.0, 1.0};
	assert(u.dot(v) == 0.0);

	u = {1.0, 1.0};
	v = {1.0, 1.0};
	assert(u.dot(v) == 2.0);

	u = {4.0, 2.0};
	v = {2.0, 1.0};
	assert(u.dot(v) == 10.0);

	return (0);
}
