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
	ft::Matrix<double> u;

	u = ft::projection(90, 1, 0.1, 10);

	std::cerr << u << "\n";
	u.to_proj(std::cout);

	std::cerr << "All done with ex14\n";
	return (0);
}
