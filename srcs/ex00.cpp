//
// Created by peer on 2-9-22.
//

#include "Vector.hpp"
#include "Matrix.hpp"
#include <cassert>

void test_vector() {
	auto u = ft::Vector<float>({2., 3.});
	auto v = ft::Vector<float>({5., 7.});
	u.add(v);
	assert(u[0] == 7.0);
	assert(u[1] == 10.0);

	u = ft::Vector<float>({2., 3.});
	v = ft::Vector<float>({5., 7.});
	u.sub(v);
	assert(u[0] == -3.0);
	assert(u[1] == -4.0);

	u = ft::Vector<float>({2., 3.});
	u.scl(2.);
	assert(u[0] == 4.0);
	assert(u[1] == 6.0);

	/*
	 * Tests from the evalsheet:
	 */
	std::cout << "Correction:\n\n";
	std::cout << "Add:\n";
	u = {0, 0};
	v = {0, 0};
	u.add(v);
	assert(u == ft::Vector<float>({0, 0}));
	u = {1, 0};
	v = {0, 1};
	u.add(v);
	assert(u == ft::Vector<float>({1, 1}));
	u = {1, 1};
	v = {1, 1};
	u.add(v);
	assert(u == ft::Vector<float>({2, 2}));
	u = {21, 21};
	v = {21, 21};
	u.add(v);
	assert(u == ft::Vector<float>({42, 42}));
	u = {-21, 21};
	v = {21, -21};
	u.add(v);
	assert(u == ft::Vector<float>({0, 0}));
	u = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	u.add(v);
	assert(u == ft::Vector<float>({9, 9, 9, 9, 9, 9, 9, 9, 9, 9}));

	std::cout << "Subtract:\n";
	u = {0, 0};
	v = {0, 0};
	u.sub(v);
	assert(u == ft::Vector<float>({0, 0}));
	u = {1, 0};
	v = {0, 1};
	u.sub(v);
	assert(u == ft::Vector<float>({1, -1}));
	u = {1, 1};
	v = {1, 1};
	u.sub(v);
	assert(u == ft::Vector<float>({0, 0}));
	u = {21, 21};
	v = {21, 21};
	u.sub(v);
	assert(u == ft::Vector<float>({0, 0}));
	u = {-21, 21};
	v = {21, -21};
	u.sub(v);
	assert(u == ft::Vector<float>({-42, 42}));
	u = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	u.sub(v);
	assert(u == ft::Vector<float>({-9, -7, -5, -3, -1, 1, 3, 5, 7, 9}));

	std::cout << "Multiply:\n";
	u = {0, 0};
	u.scl(1);
	assert(u == ft::Vector<float>({0, 0}));
	u = {1, 0};
	u.scl(1);
	assert(u == ft::Vector<float>({1, 0}));
	u = {1, 1};
	u.scl(2);
	assert(u == ft::Vector<float>({2, 2}));
	u = {21, 21};
	u.scl(2);
	assert(u == ft::Vector<float>({42, 42}));
	u = {42, 42};
	u.scl(0.5);
	assert(u == ft::Vector<float>({21, 21}));
}

void	test_matrix() {
	auto u = ft::Matrix<float>({{1.0, 2.0}, {3.0, 4.0}});
	auto v = ft::Matrix<float>({{7.0, 4.0}, {-2.0, 2.0}});
	u.add(v);
	std::cout << u << "\n";
	assert(u[0][0] == 8.0 && u[0][1] == 6.0);
	assert(u[1][0] == 1.0 && u[1][1] == 6.0);

	u = ft::Matrix<float>({{1.0, 2.0}, {3.0, 4.0}});
	v = ft::Matrix<float>({{7.0, 4.0}, {-2.0, 2.0}});
	u.sub(v);
	std::cout << u << "\n";
	assert(u[0][0] == -6.0 && u[0][1] == -2.0);
	assert(u[1][0] == 5.0 && u[1][1] == 2.0);

	u = ft::Matrix<float>({{1.0, 2.0}, {3.0, 4.0}});
	u.scl(2.0);
	std::cout << u << "\n";
	assert(u[0][0] == 2.0 && u[0][1] == 4.0);
	assert(u[1][0] == 6.0 && u[1][1] == 8.0);
}

int main() {
	test_vector();
	test_matrix();
}
