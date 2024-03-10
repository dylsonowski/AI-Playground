#pragma once
namespace Pale::Core::Math {
	template<typename T = int>
	class Matrix {
	public:
		// Constructors
		Matrix();
		Matrix(uint16_t width, uint16_t heigh);
		Matrix(uint16_t width, uint16_t heigh, std::vector<T> data);
		Matrix(Matrix &other);
		~Matrix() = default;

		// Getters
		inline uint16_t getWidth() {
			return _width;
		}

		inline uint16_t getHeight() {
			return _height;
		}

		inline T getValue(uint16_t x, uint16_t y) {
			// expect<int>(1).toBe(2);
		}

	private:
		uint16_t _width;
		uint16_t _height;
		std::vector<std::vector<T>> _matrix;
	};
} // namespace Pale::Core::Math
