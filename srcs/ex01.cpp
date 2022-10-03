//
// Created by peer on 3-10-22.
//

#include "Vector.hpp"
#include <iostream>
#include <cstdio>
#include <cassert>

template <typename K>
ft::Vector<K>	linear_combination(const std::vector<ft::Vector<K>>& u, const std::vector<K>& coefs) {
	ft::Vector<K> out;
	out.resize(coefs.size());
	if (u.size() != coefs.size())
		return (out);
	for (size_t i = 0; i < u.front().size(); i++) {
		for (size_t n = 0; n < u.size(); n++) {
			out[i] += coefs[n] * u[n][i];
		}
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
	assert(lin_comb1[0] == 10.0 && lin_comb1[1] == -2.0 && lin_comb1[2] == 0.5);

	std::vector<float> coefs2 = {10.0, -2.0};
	auto lin_comb2 = linear_combination({v1, v2}, coefs2);
	assert(lin_comb2[0] == 10.0 && lin_comb2[1] == 0.0);

	return (0);
}