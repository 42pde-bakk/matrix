//
// Created by peer on 3-10-22.
//

#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include "Vector.hpp"


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
		Shape shape{};

		void	set_shape() {
			this->shape.rows_nb = this->size();
			if (this->shape.rows_nb > 0) {
				this->shape.cols_nb = (*this)[0].size();
				for (size_t i = 0; i < this->shape.rows_nb; i++) {
					if ((*this)[i].size() != this->shape.cols_nb)
						throw std::runtime_error("Bad vector given as argument to Matrix");
				}
			}
		}

	public:

		Matrix() = default;

		Matrix(const Matrix &rhs) : vec2d(rhs) {
			this->set_shape();
		}

		Matrix(std::vector<std::vector<T>> rhs) : vec2d(rhs) {
			this->set_shape();
		}

//		using vec2d::operator=;
		Matrix&	operator=(const vec2d& rhs) {
			if (this != &rhs) {
				vec2d::operator=(rhs);
				this->set_shape();
			}
			return (*this);

		}
		Matrix& operator=(const Matrix& rhs) {
			if (this != &rhs) {
				vec2d::operator=(rhs);
				this->set_shape();
			}
			return (*this);
		}

		~Matrix() = default;

		[[nodiscard]] Shape get_shape() const {
			return (this->shape);
		}

		/*
		 * ex00
		 */
		void add(const Matrix &v) {
			if (this->shape != v.shape) {
				throw std::runtime_error("Error. Trying to add matrices of different shapes!");
			}
			for (size_t i = 0; i < this->size(); ++i) {
				for (size_t j = 0; j < (*this)[i].size(); j++) {
					(*this)[i][j] += v[i][j];
				}
			}
		}

		void sub(const Matrix &v) {
			if (this->shape != v.shape) {
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

		/*
		 * ex02
		 */
		Matrix	operator+(const Matrix& rhs) const {
			Matrix out(*this);

			for (size_t i = 0; i < this->size(); i++) {
				for (size_t n = 0; n < (*this)[i].size(); n++) {
					out[i][n] += rhs[i][n];
				}
			}
			return (out);
		}
		Matrix	operator-(const Matrix& rhs) const {
			Matrix out(*this);

			for (size_t i = 0; i < this->size(); i++) {
				for (size_t n = 0; n < (*this)[i].size(); n++) {
					out[i][n] -= rhs[i][n];
				}
			}
			return (out);
		}
		Matrix	operator*(T scalar) const {
			Matrix out(*this);

			for (size_t i = 0; i < this->size(); i++) {
				for (size_t n = 0; n < (*this)[i].size(); n++) {
					out[i][n] *= scalar;
				}
			}
			return (out);
		}

		/*
		 * ex07
		 */
		Vector<T>	operator*(const Vector<T>& rhs) const {
			Vector<T> out;

			out.resize(shape.rows_nb);
			if (this->shape.cols_nb != rhs.size()) {
				return (out);
			}
			for (size_t i = 0; i < shape.rows_nb; i++) {
				for (size_t n = 0; n < shape.cols_nb; n++) {
					out[i] += (*this)[i][n] * rhs[n];
				}
			}
			return (out);
		}
		Vector<T>	mul_vec(const Vector<T>& rhs) const {
			return (*this * rhs);
		}
		Matrix	operator*(const Matrix& rhs) const {
			Matrix	out;

			out.resize(this->size());
			for (size_t i = 0; i < out.size(); i++)
				out[i].resize(rhs.shape.cols_nb);
			if (shape.cols_nb != rhs.shape.rows_nb)
				return (out);
			for (size_t a = 0; a < shape.rows_nb; a++) {
				for (size_t b = 0; b < rhs.shape.cols_nb; b++) {
					for (size_t p = 0; p < shape.cols_nb; p++) {
						out[a][b] += (*this)[a][p] * rhs[p][b];
					}
				}
			}
			return (out);
		}
		Matrix	mul_mat(const Matrix& rhs) const {
			return (*this * rhs);
		}

		/*
		 * ex08
		 */
		T	trace() const {
			T total = T();
			if (shape.rows_nb != shape.cols_nb)
				return (total);
			for (size_t i = 0; i < shape.rows_nb; i++) {
				total += (*this)[i][i];
			}
			return (total);
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
