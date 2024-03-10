template<typename T>
struct expect {
	expect() = delete;
	expect(expect &other) = delete;

	expect(T value)
		: _value(value) {}

	~expect() = default;

	inline void toBe(T other) {
		if (_value != other) {
			std::cout << "AssertionError!" << std::endl;
		}
	}

	T _value;
};
