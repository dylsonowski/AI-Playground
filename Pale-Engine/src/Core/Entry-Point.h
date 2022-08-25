#pragma once
#include "Core/Application.h"

extern Pale::Application* Pale::CreateApplication();

int main(int argc, char** argv) {
    auto app = Pale::CreateApplication();
    app->Run();
    delete app;
}