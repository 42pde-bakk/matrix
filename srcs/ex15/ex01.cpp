//
// Created by peer on 3-10-22.
//

#include <complex>
#include "Vector.hpp"
#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std::complex_literals;

template <typename K>
ft::Vector<K>	linear_combination(const std::vector<ft::Vector<K>>& u, const std::vector<K>& coefs) {
	ft::Vector<K> out;
	out.resize(coefs.size());
	if (u.size() != coefs.size())
		return (out);
	for (size_t i = 0; i < u.front().size(); i++) {
		for (size_t n = 0; n < u.size(); n++) {
			/*
			 * fma(x, y, z) does x * y + z in one step
			 */
			out[i] = std::fma(coefs[n], u[n][i], out[i]);
		}
	}
	return (out);
}

int main() {
	auto e1 = ft::Vector<std::complex<float>>({1.0if, 0.0if, 0.0if});
	auto e2 = ft::Vector<std::complex<float>>({0.0if, 1.0if, 0.0if});
	auto e3 = ft::Vector<std::complex<float>>({0.0if, 0.0if, 1.0if});

	auto v1 = ft::Vector<std::complex<float>>({1.0if, 2.0if, 3.0if});
	auto v2 = ft::Vector<std::complex<float>>({0.0if, 10.0if, -100.0if});

	std::vector<std::complex<float>>	coefs1 = {10.0if, -2.0if, 0.5if};
	auto lin_comb1 = linear_combination({e1, e2, e3}, coefs1);
	for (size_t i = 0; i < lin_comb1.size(); i++) {
		std::cout << lin_comb1[i] << ' ';
	}
	std::cout << "\n";
	assert(lin_comb1[0] == 10.0 && lin_comb1[1] == -2.0 && lin_comb1[2] == 0.5);

	std::vector<std::complex<float>> coefs2 = {10.0, -2.0};
	auto lin_comb2 = linear_combination({v1, v2}, coefs2);
	assert(lin_comb2[0] == 10.0 && lin_comb2[1] == 0.0);

	return (0);
}