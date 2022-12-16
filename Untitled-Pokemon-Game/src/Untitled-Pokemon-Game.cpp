#include <Pale.h>

class Untitled_Pokemon_Game: public Pale::Application {
public:
	Untitled_Pokemon_Game() = default;
	~Untitled_Pokemon_Game() = default;

private:
};

Pale::Application *Pale::CreateApplication() {
	return new Untitled_Pokemon_Game();
}