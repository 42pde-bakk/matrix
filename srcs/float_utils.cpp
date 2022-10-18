//
// Created by peer on 18-10-22.
//

#include <cmath>

constexpr double EPSILON = 0.00001;
bool	feq(double a, double b) {
	return (std::fabs(a - b) < EPSILON);
}

//bool	feq(float a, float b) {
//	return (std::abs(a - b) < EPSILON);
//}
