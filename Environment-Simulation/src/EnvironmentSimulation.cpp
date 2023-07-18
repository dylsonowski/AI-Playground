#include <Pale.h>

class EnvironemntSimulation: public Pale::Application {
public:
	EnvironemntSimulation() = default;
	~EnvironemntSimulation() = default;

private:
};

Pale::Application *Pale::CreateApplication() {
	return new EnvironemntSimulation();
}