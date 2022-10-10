//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <vector>
#include <stdexcept>
#include <cstdio>
#include <stdexcept>
#include <cassert>
#include <limits>
#include <cmath>


int main() {
	auto u = ft::Vector<float>({0.0, 0.0});
	auto v = ft::Vector<float>({1.0, 1.0});
	assert(feq(u.dot(v), 0.0));

	u = {1.0, 1.0};
	v = {1.0, 1.0};
	assert(feq(u.dot(v), 2.0));


	u = {-1.0, 6.0};
	v = {3.0, 2.0};
	assert(feq(u.dot(v), 9.0));

	return (0);
}
