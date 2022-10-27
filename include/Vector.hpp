//
// Created by peer on 2-9-22.
//

#ifndef MATRIX_VECTOR_HPP
#define MATRIX_VECTOR_HPP
#include <vector>
#include <stdexcept>
#include <ostream>
#include <iostream>
#include <cmath>
#include <complex>

namespace std {
	template <typename T>
	std::complex<T>	fma(std::complex<T> x, std::complex<T> y, std::complex<T> z) {
		return (x * y + z);
	}
}

template <typename T>
bool	operator>(std::complex<T> lhs, std::complex<T> rhs) {
	if (lhs.real() > rhs.real())
		return (true);
	else if (lhs.real() < rhs.real())
		return (false);
	else
		return (lhs.imag() > rhs.imag());
}


namespace ft {

	template <typename T>
	class Vector : public std::vector<T> {

	public:
		Vector() = default;
		~Vector() = default;
		Vector(const Vector& v) : std::vector<T>(v) {
		}
		Vector(const std::vector<T>& v) : std::vector<T>(v) {
		}
		using std::vector<T>::operator=;
		Vector& operator=(const Vector& v) {
			std::vector<T>::operator=(v);
			return (*this);
		}

		bool	operator==(const Vector& rhs) const {
			if (this->size() != rhs.size())
				return (false);
			for (size_t i = 0; i < this->size(); i++) {
				if ((*this)[i] != rhs[i])
					return (false);
			}
			return (true);
		}

		/*
		 * ex00
		 */
		void	add(const Vector& rhs) {
			if (this->size() != rhs.size())
				throw std::runtime_error("Vector not same size");
			for (size_t i = 0; i < this->size(); i++) {
				(*this)[i] += rhs[i];
			}
		}
		void	sub(const Vector& rhs) {
			if (this->size() != rhs.size())
				throw std::runtime_error("Vector not same size");
			for (size_t i = 0; i < this->size(); i++) {
				(*this)[i] -= rhs[i];
			}
		}
		void	scl(T f) {
			for (size_t i = 0; i < this->size(); i++) {
				(*this)[i] *= f;
			}
		}

		/*
		 * ex02
		 */
		Vector	operator-(const Vector& rhs) const {
			Vector out;
			out.resize(this->size());
			for (size_t i = 0; i < this->size(); i++) {
				out[i] = (*this)[i] - rhs[i];
			}
			return (out);
		}
		Vector	operator+(const Vector& rhs) const {
			Vector out;
			out.resize(this->size());
			for (size_t i = 0; i < this->size(); i++) {
				out[i] = (*this)[i] + rhs[i];
			}
			return (out);
		}
		Vector	operator*(T scalar) const {
			Vector out;
			out.resize(this->size());
			for (size_t i = 0; i < this->size(); i++) {
				out[i] = (*this)[i] * scalar;
			}
			return (out);
		}

		/*
		 * ex03
		 */
		T	dot(const Vector& rhs) const {
			T	dotproduct = T();

			if (this->size() != rhs.size())
				return (dotproduct);
			for (size_t i = 0; i < this->size(); i++) {
				dotproduct = std::fma(rhs[i], (*this)[i], dotproduct);
			}
			return (dotproduct);
		}

		/*
		 * ex04
		 */
		[[nodiscard]] T	norm_1() const {
			T out = T();

			for (auto& item : *this) {
				out += fabs(item);
			}
			return (out);
		}
		[[nodiscard]] T norm() const {
			T out = T();

			for (auto& item : *this) {
				out = std::fma(item, item, out);
			}
			return (sqrt(out));
		}
		[[nodiscard]] T norm_inf() const {
			T max_item = T();

			for (auto& item : *this) {
				T item_abs = std::abs(item);
				if (item_abs > max_item)
					max_item = item_abs;
			}
			return (max_item);
		}

		/*
		 * ex05
		 */
		T	angle_cos(const Vector& rhs) const {
			// https://www.youtube.com/watch?v=2pIlGSu6Ta4
			// https://www.geeksforgeeks.org/cosine-similarity/
			return this->dot(rhs) / (this->norm() * rhs.norm());
		}

		/*
		 * ex06
		 */
		Vector	cross(const Vector& rhs) const {
			Vector out;

			if (this->size() != 3 || rhs.size() != 3) {
				return (out);
			}
			out.resize(this->size());
			out[0] = std::fma((*this)[1], rhs[2], -rhs[1] * (*this)[2]);
			out[1] = std::fma((*this)[2], rhs[0], -rhs[2] * (*this)[0]);
			out[2] = std::fma((*this)[0], rhs[1], -rhs[0] * (*this)[1]);
			return (out);		}


		friend std::ostream&	operator<<(std::ostream& o, ft::Vector<T>& vec) {
			for (auto& item : vec) {
				o << item << ' ';
			}
			o << '\n';
			return (o);
		}
	};

	template <typename T>
	T	angle_cos(const Vector<T>& u, const Vector<T>& v) {
		return u.angle_cos(v);
	}
	template <typename T>
	Vector<T>	cross_product(const Vector<T>& u, const Vector<T>& v) {
		return (u.cross(v));
	}
}


#endif //MATRIX_VECTOR_HPP
