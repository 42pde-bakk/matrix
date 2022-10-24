//
// Created by peer on 3-10-22.
//

#include "Vector.hpp"
#include <iostream>
#include <cstdio>
#include <cassert>

template <typename K>
ft::Vector<K>	linear_combination(const std::vector<ft::Vector<K>>& u, const std::vector<K>& coefs) {
	/*
	 * this function adds together (coefs[i] * u[i]) for i < coefs.size()
	 */
	if (u.empty() || u.size() != coefs.size()) {
		std::cerr << "u.size != coefs.size\n";
		return (ft::Vector<K>());
	}
	for (size_t i = 0; i < u.size(); i++) {
		if (u[i].size() != u[0].size()) {
			std::cerr << "Vectors in u have different size.\n";
			return (ft::Vector<K>());
		}
	}
	ft::Vector<K> out;
	out.resize(u[0].size());
	for (size_t i = 0; i < u.size(); i++) {
		out.add(u[i] * coefs[i]);
	}
	return (out);
}

int main() {
	auto e1 = ft::Vector<float>({1.0, 0.0, 0.0});
	auto e2 = ft::Vector<float>({0.0, 1.0, 0.0});
	auto e3 = ft::Vector<float>({0.0, 0.0, 1.0});

	auto v1 = ft::Vector<float>({1.0, 2.0, 3.0});
	auto v2 = ft::Vector<float>({0.0, 10.0, -100.0});

	std::vector<float>	coefs1 = {10.0, -2.0, 0.5};
	auto lin_comb1 = linear_combination({e1, e2, e3}, coefs1);
	for (size_t i = 0; i < lin_comb1.size(); i++) {
		std::cout << lin_comb1[i] << ' ';
	}
	std::cout << "\n";
	assert(lin_comb1 == ft::Vector<float>({10.0, -2.0, 0.5}));

	std::vector<float> coefs2 = {10.0, -2.0};
	auto lin_comb2 = linear_combination({v1, v2}, coefs2);
	std::cout << lin_comb2 << "\n";
	assert(lin_comb2 == ft::Vector<float>({10.0, 0.0, 230.0}));

	/*
	 * Tests from the correction:
	 */
	ft::Vector<float> result;
	e1 = {-42.0, 42.0};
	coefs1 = {-1.0};
	result = linear_combination({e1}, coefs1);
	std::cout << result << "\n";
	assert(result == ft::Vector<float>({42.0, -42.0}));

	e1 = {-42.0};
	e2 = {-42.0};
	e3 = {-42.0};
	coefs1 = {-1.0, 1.0, 0.0};
	result = linear_combination({e1, e2, e3}, coefs1);
	std::cout << result << "\n";
	assert(result == ft::Vector<float>({0.0}));

	e1 = {-42.0, 42.0};
	e2 = {1.0, 3.0};
	e3 = {10.0, 20.0};
	coefs1 = {1.0, -10.0, -1.0};
	result = linear_combination({e1, e2, e3}, coefs1);
	std::cout << result << "\n";
	assert(result == ft::Vector<float>({-62.0, -8.0}));

	e1 = {-42.0, 100.0, -69.5};
	e2 = {1.0, 3.0, 5.0};
	coefs1 = {1.0, -10.0};
	result = linear_combination({e1, e2}, coefs1);
	std::cout << result << "\n";
	assert(result == ft::Vector<float>({-52.0, 70.0, -119.5}));

	return (0);
}