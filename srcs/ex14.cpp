//
// Created by peer on 3-10-22.
//

#include "Matrix.hpp"
#include "Vector.hpp"

namespace ft {
	/*
	 * ex14 (Bonus)
	 * https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix
	 */
	Matrix<double>	projection(double fov, double ratio, double near, double far) {
		auto	radians = tan((fov / 2) * (M_PI / 180));
		double	scale = 1.0 / radians;

		return Matrix<double>({
				{scale / ratio, 0.0, 0.0, 0.0},
				{0.0, scale, 0.0, 0.0},
				{0.0, 0.0, -far / (far - near), -1.0},
				{0.0, 0.0, -(far * near) / (far - near), 0.0}
		});
		/*
		 * s/r	0	0	0
		 * 0	s	0	0
		 * 0	0	A	-1
		 * 0	0	B	0
		 */
	}
}

int main() {
	ft::Matrix<double> u;

	u = ft::projection(90, 1.0, 1, 100);

	std::cerr << u << "\n";
	u.to_proj(std::cout);

	std::cerr << "All done with ex14\n";
	return (0);
}
