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
//	static_assert(u[0] == 7.0, "Failed addition")

	u = ft::Vector<float>({2., 3.});
	u.scl(2.);
	assert(u[0] == 4.0);
	assert(u[1] == 6.0);
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