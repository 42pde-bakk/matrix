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
		size_t rows_nb,
				cols_nb;

		bool operator==(const Shape& rhs) const {
			return (rows_nb == rhs.rows_nb && cols_nb == rhs.cols_nb);
		}
		bool operator!=(const Shape& rhs) const {
			return !(*this == rhs);
		}
	};

	template<typename T>
	class Matrix {
		std::vector<std::vector<T>> data;

	public:
//		Matrix(size_t n, size_t value) : data(n, value) {
//		}

		Matrix(const Matrix &rhs) {
			this->data = rhs.data;
		}

		Matrix(std::vector<std::vector<T>> rhs) {
			this->data = rhs;
		}

		Matrix &operator=(const std::vector<std::vector<float>>& rhs) {
			this->data = rhs;
			return (*this);
		}
		Matrix &operator=(const Matrix& rhs) {
			this->data = rhs.data;
			return (*this);
		}

		~Matrix() = default;

		[[nodiscard]] Shape get_shape() const {
			Shape out{0, 0};

			out.rows_nb = this->data.size();
			if (out.rows_nb > 0) {
				out.cols_nb = this->data[0].size();
			}
			return (out);
		}

		void add(const Matrix &v) {
			if (this->get_shape() != v.get_shape()) {
				throw std::runtime_error("Error. Trying to add matrices of different shapes!");
			}
			for (size_t i = 0; i < data.size(); ++i) {
				for (size_t j = 0; j < data[i].size(); j++) {
					this->data[i][j] += v.data[i][j];
				}
			}
		}

		void sub(const Matrix &v) {
			if (this->get_shape() != v.get_shape()) {
				throw std::runtime_error("Error. Trying to subtract matrices of different shapes!");
			}
			for (size_t i = 0; i < data.size(); ++i) {
				for (size_t j = 0; j < data[i].size(); j++) {
					this->data[i][j] -= v.data[i][j];
				}
			}
		}

		void scl(T a) {
			for (auto& row : this->data) {
				for (auto& item : row) {
					item *= a;
				}
			}
//			for (size_t i = 0; i < data.size(); ++i) {
//				for (size_t j = 0; j < data[i].size(); j++) {
//					this->data[i][j] *= a;
//				}
//			}
		}
		std::vector<T>&	operator[](size_t idx) {
			return (this->data[idx]);
		}
		constexpr std::vector<T>&	operator[](size_t idx) const {
			return (this->data[idx]);
		}
		friend std::ostream&	operator<<(std::ostream& o, ft::Matrix<T>& m) {
			for (auto& row : m.data) {
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
