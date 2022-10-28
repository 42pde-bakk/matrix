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
		auto	out = Matrix<double>::identity(4);
		auto	radians = tan(fov / 2);
		double	scale = 1.0 / radians;

		out[0][0] = scale / ratio;
		out[1][1] = scale;
		out[2][2] = -(far) / (far - near);
		out[2][3] = -1;
		out[3][2] = -(far * near) / (far - near);

		/*
		 * s/r	0	0	0
		 * 0	s	0	0
		 * 0	0	A	-1
		 * 0	0	B	0
		 */
		return (out);
	}
}

int main() {
	ft::Matrix<double> u;

	u = ft::projection(90, 1, 0.1, 10);

	std::cerr << u << "\n";
	u.to_proj(std::cout);

	std::cerr << "All done with ex14\n";
	return (0);
}
