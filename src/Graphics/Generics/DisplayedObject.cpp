#include <Graphics/Generics/DisplayedObject.h>

void DisplayedObject::Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera)
{
    if (m_Displayed == nullptr) {
        m_Displayed = CreateDisplayed();
    }
    
    m_Displayed->Draw(shader, camera);
}
