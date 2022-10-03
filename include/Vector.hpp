//
// Created by peer on 2-9-22.
//

#ifndef MATRIX_VECTOR_HPP
#define MATRIX_VECTOR_HPP
#include <vector>
#include <stdexcept>
#include <ostream>

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


		friend std::ostream&	operator<<(std::ostream& o, ft::Vector<T>& vec) {
			for (auto& item : vec) {
				o << item << ' ';
			}
			o << '\n';
			return (o);
		}
	};

}


#endif //MATRIX_VECTOR_HPP
