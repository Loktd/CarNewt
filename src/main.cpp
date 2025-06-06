#include <WindowingEngine.h>

int main() {
    WindowingEngine& engine = WindowingEngine::GetInstance();
    while (engine.keepRunning()) {
        engine.run();
    }
}