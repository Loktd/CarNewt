#include <Engine/WindowingEngine.h>

int main(int argc, char** argv) {
    WindowingEngine& engine = WindowingEngine::GetInstance();
    while (engine.KeepRunning()) {
        engine.Run();
    }
}