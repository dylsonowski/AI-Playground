#include "palepch.hpp"
template<typename T>
struct expect {
	// Contructors
	expect() = delete;
	expect(expect &other) = delete;

	expect(T value, std::optional<std::string> message)
		: _value(value), _message(message) {}

	~expect() = default;

	// Methods
	inline void toBe(T other) {
		if (_value != other) {
			
		}
	}

	// Attributes
	T _value;
	std::optional<std::string> _message;
};
