//
// Created by peer on 3-10-22.
//

#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP

#include <vector>
#include <stdexcept>
#include <iostream>


namespace ft {
	struct Shape {
		size_t	rows_nb,
				cols_nb;

		bool operator==(const Shape& rhs) const {
			return (rows_nb == rhs.rows_nb && cols_nb == rhs.cols_nb);
		}
		bool operator!=(const Shape& rhs) const {
			return !(*this == rhs);
		}
	};

	template<typename T>
	class Matrix : public std::vector<std::vector<T>> {
		typedef std::vector<std::vector<T>> vec2d;

	public:

		Matrix(const Matrix &rhs) : vec2d(rhs) {
		}

		Matrix(std::vector<std::vector<T>> rhs) : vec2d(rhs) {
		}

		using vec2d::operator=;
		Matrix &operator=(const Matrix& rhs) {
			if (this != &rhs) {
				vec2d::operator=(rhs);
			}
			return (*this);
		}

		~Matrix() = default;

		[[nodiscard]] Shape get_shape() const {
			Shape out{0, 0};

			out.rows_nb = this->size();
			if (out.rows_nb > 0) {
				out.cols_nb = (*this)[0].size();
			}
			return (out);
		}

		void add(const Matrix &v) {
			if (this->get_shape() != v.get_shape()) {
				throw std::runtime_error("Error. Trying to add matrices of different shapes!");
			}
			for (size_t i = 0; i < this->size(); ++i) {
				for (size_t j = 0; j < (*this)[i].size(); j++) {
					(*this)[i][j] += v[i][j];
				}
			}
		}

		void sub(const Matrix &v) {
			if (this->get_shape() != v.get_shape()) {
				throw std::runtime_error("Error. Trying to subtract matrices of different shapes!");
			}
			for (size_t i = 0; i < this->size(); ++i) {
				for (size_t j = 0; j < (*this)[i].size(); j++) {
					(*this)[i][j] -= v[i][j];
				}
			}
		}

		void scl(T a) {
			for (auto& row : *this) {
				for (auto& item : row) {
					item *= a;
				}
			}
		}
		friend std::ostream&	operator<<(std::ostream& o, ft::Matrix<T>& m) {
			for (auto& row : m) {
				for (auto& item : row) {
					o << item << ' ';
				}
				o << '\n';
			}
			return (o);
		}
	};
}

#endif //MATRIX_MATRIX_HPP
