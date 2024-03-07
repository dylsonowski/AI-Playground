#include <Pale.hpp>

class Playground: public Pale::Application {
public:
	Playground() = default;
	~Playground() = default;

private:
};

Pale::Application *Pale::CreateApplication() {
	return new Playground();
}