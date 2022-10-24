//
// Created by peer on 3-10-22.
//

#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP

#include <vector>
#include <cstdio>
#include <stdexcept>
#include <array>
#include <iostream>
#include <iomanip>
#include "Vector.hpp"
#include <complex>


constexpr float EPSILON = 0.00001;
bool	feq(double a, double b);

template <typename T>
bool	feq(std::complex<T> a, std::complex<T> b) {
	return (a == b);
}

template<typename T>
std::complex<T>	fma(std::complex<T> x, std::complex<T> y, std::complex<T> z);

template<typename T>
bool operator>(const std::complex<T> lhs, const float rhs) {
	return (lhs.real() > rhs);
}

template<typename T>
bool operator<(const std::complex<T> lhs, std::complex<T> rhs) {
	if (lhs.real() < rhs.real())
		return (true);
	else
		return (lhs.imag() < rhs.imag());
}

template<typename T>
bool operator<(const std::complex<T> lhs, const float rhs) {
	return (lhs.real() < rhs);
}


template<typename T>
inline T my_abs(T x) {
	return (x < T(0)) ? -x : x;
}


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

		explicit Matrix(size_t n) : vec2d(n) {
			for (size_t i = 0; i < n; i++) {
				(*this)[i].assign(n, T());
			}
		}

		bool	operator==(const Matrix& rhs) const {
			if (this->shape != rhs.shape)
				return (false);
			for (size_t row = 0; row < shape.rows_nb; row++) {
				for (size_t col = 0; col < shape.cols_nb; col++) {
					if (!feq((*this)[row][col], rhs[row][col])) {
						return (false);
					}
				}
			}
			return (true);
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
					out[i] = std::fma((*this)[i][n], rhs[n], out[i]);
				}
			}
			return (out);
		}
		[[nodiscard]] Vector<T>	mul_vec(const Vector<T>& rhs) const {
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
						out[a][b] = std::fma((*this)[a][p], rhs[p][b], out[a][b]);
//						out[a][b] += (*this)[a][p] * rhs[p][b];
					}
				}
			}
			return (out);
		}
		[[nodiscard]] Matrix	mul_mat(const Matrix& rhs) const {
			return (*this * rhs);
		}

		/*
		 * ex08
		 */
		[[nodiscard]] T	trace() const {
			T total = T();
			if (shape.rows_nb != shape.cols_nb)
				return (total);
			for (size_t i = 0; i < shape.rows_nb; i++) {
				total += (*this)[i][i];
			}
			return (total);
		}

		/*
		 * ex09
		 */
		[[nodiscard]] Matrix	transpose() const {
			Matrix	out(*this);

			for (size_t i = 0; i < shape.rows_nb; i++) {
				for (size_t j = 0; j < shape.cols_nb; j++) {
					out[i][j] = (*this)[j][i];
				}
			}
			return (out);
		}

		/*
		 * ex10
		 */
		void	mult_and_add_rows(size_t ixrdest, size_t ixrsrc, T mplr) {
			for (size_t ix = 0; ix < shape.cols_nb; ix++) {
				(*this)[ixrdest][ix] += mplr * (*this)[ixrsrc][ix];
			}
		}
		void	normalize_row(size_t row_idx, size_t lead) {
			const T lead_elem = (*this)[row_idx][lead];
			for (size_t i = 0; i < shape.cols_nb; i++) {
				(*this)[row_idx][i] /= lead_elem;
			}
		}
		Matrix	row_echelon() {
			size_t lead = 0;

			for (size_t rix = 0; rix < shape.rows_nb; rix++) {
				if (lead >= shape.cols_nb)
					return (*this);
				size_t iix = rix;
				while ((*this)[iix][lead] == T()) {
					iix++;
					if (iix == shape.rows_nb) {
						iix = rix;
						lead++;
						if (lead == shape.cols_nb)
							return (*this);
					}
				}
				std::swap((*this)[iix], (*this)[rix]);
				this->normalize_row(rix, lead);

				for (iix = 0; iix < shape.rows_nb; iix++) {
					if (iix != rix) {
						T lv = (*this)[iix][lead];
						this->mult_and_add_rows(iix, rix, -lv);
					}
				}
				lead++;
			}
			return (*this);
		}

		/*
		 * ex11
		 */
	private:
		[[nodiscard]] Matrix	squareMatrix(size_t n) const {
			Matrix out;
			out.resize(n);
			for (size_t i = 0; i < n; i++) {
				out[i].resize(n, 0);
			}
			out.set_shape();
			return (out);
		}

		[[nodiscard]] Matrix	minor(size_t x, size_t y) const {
			size_t len = this->size() - 1;
			Matrix result = squareMatrix(len);

			for (size_t i = 0; i < len; i++) {
				for (size_t j = 0; j < len; j++) {
					if (i < x && j < y)
						result[i][j] = (*this)[i][j];
					else if (i >= x && j < y)
						result[i][j] = (*this)[i + 1][j];
					else if (i < x && j >= y)
						result[i][j] = (*this)[i][j + 1];
					else
						result[i][j] = (*this)[i + 1][j + 1];
				}
			}
			return (result);
		}

	public:
		[[nodiscard]] T	perm() const {
			if (this->size() == 1) {
				return (*this)[0][0];
			}
			T sum = 0;
			for (size_t i = 0; i < this->size(); i++) {
				sum += (*this)[0][i] * this->minor(0, i).perm();
			}
			return (sum);
		}
		[[nodiscard]] T	determinant() const {
			T result = 0;
			T sign = 1;

			if (shape.rows_nb != shape.cols_nb)
				throw std::runtime_error("Bad shape given to Matrix::determinant()");
			if (shape.rows_nb == 1)
				return (*this)[0][0];
			else if (shape.rows_nb == 2) {
				return ((*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0]);
			}

			for (size_t i = 0; i < shape.rows_nb; i++) {
				auto first = (*this)[0][i];
				Matrix minority = this->minor(0, i);
				T minority_det = minority.determinant();
//				result = std::fma(sign * first, minority_det, result);
				result += sign * first * minority_det;
;				sign = -sign;
			}
			return (result);
		}

		/*
		 * ex12
		 */
		static Matrix	identity(size_t n) {
			Matrix out(n);
			for (size_t i = 0; i < n; i++) {
				out[i][i] = 1;
			}
			return (out);
		}
		[[nodiscard]] Matrix	hstack(const Matrix& rhs) const {
			Matrix	out(*this);

			if (this->shape.rows_nb != rhs.shape.rows_nb)
				throw std::runtime_error("hstack: bad rhs matrix");
			for (size_t i = 0; i < out.shape.rows_nb; i++) {
				out[i].insert(out[i].end(), rhs[i].begin(), rhs[i].end());
			}
			return (out);
		}
		[[nodiscard]] Matrix	vstack(const Matrix& rhs) const {
			Matrix	out(*this);

			if (this->shape.cols_nb != rhs.shape.cols_nb)
				throw std::runtime_error("vstack: bad rhs matrix");
			out.insert(out.end(), rhs.begin(), rhs.end());
			return (out);
		}

		[[nodiscard]] Matrix	inverse() const {
			Matrix	out(*this);

			if (this->shape.rows_nb != shape.cols_nb)
				throw std::runtime_error("bad matrix for inverse");
			const T det = this->determinant();
			for (size_t rownb = 0; rownb < shape.rows_nb; rownb++) {
				for (size_t colnb = 0; colnb < shape.cols_nb; colnb++) {
					T first = (*this)[(rownb + 1) % 3][(colnb + 1) % 3] * (*this)[(rownb + 2) % 3][(colnb + 2) % 3];
					T second = (*this)[(rownb + 1) % 3][(colnb + 2) % 3] * (*this)[(rownb + 2) % 3][(colnb + 1) % 3];
					out[rownb][colnb] = (first - second) / det;
				}
			}
			return (out);
		}

		/*
		 * ex13
		 */
		[[nodiscard]] size_t	rank() const {
			Matrix	copy(*this);
			size_t rank = 0;
			std::vector<bool>	row_selected(shape.rows_nb, false);

			for (size_t i = 0; i < shape.cols_nb; i++) {
				size_t j;
				for (j = 0; j < shape.rows_nb; j++) {
					if (!row_selected[j] && my_abs(copy[j][i]) > EPSILON)
						break ;
				}
				if (j != shape.rows_nb) {
					rank++;
					row_selected[j] = true;
					for (size_t p = i + 1; p < shape.cols_nb; p++) {
						copy[j][p] /= copy[j][i];
					}
					for (size_t k = 0; k < shape.rows_nb; k++) {
						if (k != j && my_abs(copy[k][i]) > EPSILON) {
							for (size_t p = i + 1; p < shape.cols_nb; p++) {
								copy[k][p] = std::fma(-copy[j][p], copy[k][i], copy[k][p]);
							}
						}
					}
				}
			}
			return (rank);
		}

		friend std::ostream&	operator<<(std::ostream& o, ft::Matrix<T>& m) {
			for (auto& row : m) {
				for (auto& item : row) {
					o << std::setprecision(5) << item << ' ';
				}
				o << '\n';
			}
			return (o);
		}
		void	to_proj(std::ostream& o) const {
			for (size_t rownb = 0; rownb < shape.rows_nb; rownb++) {
				for (size_t colnb = 0; colnb < shape.cols_nb; colnb++) {
					o << std::setprecision(1) << (*this)[rownb][colnb];
					if (colnb != shape.cols_nb - 1)
						o << ", ";
				}
				std::cout << "\n";
			}
		}
	};
}

#endif //MATRIX_MATRIX_HPP
