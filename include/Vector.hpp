//
// Created by peer on 2-9-22.
//

#ifndef MATRIX_VECTOR_HPP
#define MATRIX_VECTOR_HPP
#include <vector>
#include <stdexcept>

namespace ft {

	template <typename T>
	class Vector {
		std::vector<T>	data;

	public:
		Vector() = default;
		~Vector() = default;
		Vector(const Vector& v) = default;
		Vector(const std::vector<T>& v) : data(v) { }
		Vector& operator=(const Vector& v) = default;

		void	add(const Vector& rhs) {
			if (this->size() != rhs.size())
				throw std::runtime_error("Vector not same size");
			for (size_t i = 0; i < this->size(); i++) {
				this->data[i] += rhs.data[i];
			}
		}
		void	sub(const Vector& rhs) {
			if (this->size() != rhs.size())
				throw std::runtime_error("Vector not same size");
			for (size_t i = 0; i < this->size(); i++) {
				this->data[i] -= rhs.data[i];
			}
		}
		void	scl(T f) {
			for (size_t i = 0; i < this->size(); i++) {
				this->data[i] *= f;
			}
		}

		[[nodiscard]] size_t	size() const {
			return (this->data.size());
		}
		T	operator[](size_t idx) {
			return (this->data[idx]);
		}
		constexpr T&	operator[](size_t idx) const {
			return (this->data[idx]);
		}

	};

}


#endif //MATRIX_VECTOR_HPP
