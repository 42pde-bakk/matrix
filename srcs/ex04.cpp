//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"
#include <cassert>
#include <iomanip>


int main() {
	auto u = ft::Vector<float>({0.0, 0.0, 0.0});
	std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm(), 0.0));
	assert(feq(u.norm_1(), 0.0));
	assert(feq(u.norm_inf(), 0.0));

	u = {1.0, 2.0, 3.0};
	std::cout << std::setprecision(8) << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm_1(), 6.0));
	assert(feq(u.norm(), 3.7416575));
	assert(feq(u.norm_inf(), 3.0));

	u = {-1.0, -2.0};
	std::cout << u.norm_1() << ", " << u.norm() << ", " << u.norm_inf() << "\n";
	assert(feq(u.norm_1(), 3.0));
	assert(feq(u.norm(), 2.23607));
	assert(feq(u.norm_inf(), 2.0));

	/*
	 * Tests from the evalsheet
	 */
	// Euclidean norm
	assert(ft::Vector<double>({0.0}).norm() == 0.0);
	assert(ft::Vector<double>({1.0}).norm() == 1.0);
	assert(ft::Vector<double>({0.0, 0.0}).norm() == 0.0);
	assert(ft::Vector<double>({1.0, 0.0}).norm() == 1.0);
	assert(feq(ft::Vector<double>({2.0, 1.0}).norm(), 2.236067977));
	assert(feq(ft::Vector<double>({4.0, 2.0}).norm(), 4.472135955));
	assert(feq(ft::Vector<double>({-4.0, -2.0}).norm(), 4.472135955));

	// Manhattan norm
	assert(ft::Vector<double>({0.0}).norm_1() == 0.0);
	assert(ft::Vector<double>({1.0}).norm_1() == 1.0);
	assert(ft::Vector<double>({0.0, 0.0}).norm_1() == 0.0);
	assert(ft::Vector<double>({1.0, 0.0}).norm_1() == 1.0);
	assert(ft::Vector<double>({2.0, 1.0}).norm_1() == 3.0);
	assert(ft::Vector<double>({4.0, 2.0}).norm_1() == 6.0);
	assert(ft::Vector<double>({-4.0, -2.0}).norm_1() == 6.0);

	// Supremeum norm
	assert(ft::Vector<double>({0.0}).norm_inf() == 0.0);
	assert(ft::Vector<double>({1.0}).norm_inf() == 1.0);
	assert(ft::Vector<double>({0.0, 0.0}).norm_inf() == 0.0);
	assert(ft::Vector<double>({1.0, 0.0}).norm_inf() == 1.0);
	assert(ft::Vector<double>({2.0, 1.0}).norm_inf() == 2.0);
	assert(ft::Vector<double>({4.0, 2.0}).norm_inf() == 4.0);
	assert(ft::Vector<double>({-4.0, -2.0}).norm_inf() == 4.0);

	return (0);
}
