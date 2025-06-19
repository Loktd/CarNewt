#pragma once

#include <memory>

#include <Graphics/Generics/IDrawable2D.h>
#include <Graphics/Generics/Object2D.h>

class DisplayedObject : public IDrawable2D
{
private:
    std::unique_ptr<Object2D> m_Displayed;
protected:
    virtual std::unique_ptr<Object2D> CreateDisplayed() = 0;
public:
    void Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) override;
};
