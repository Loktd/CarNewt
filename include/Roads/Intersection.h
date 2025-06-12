#pragma once

#include <vector>
#include <array>
#include <memory>

#include "Road.h"
#include <Loader/CSVProcessor.hpp>
#include <Exceptions/LoaderExceptions.hpp>
#include <Generics/Identifiable.h>
#include <Graphics/IDrawable2D.h>
#include <Graphics/Shapes/Circle.h>

class Road;

class Intersection : public Identifiable, public IDrawable2D
{
private:
    double m_XCoordinate, m_YCoordinate;

    std::vector<std::shared_ptr<Road>> m_OutwardRoads;
    std::vector<std::shared_ptr<Road>> m_InwardRoads;

    Circle m_Circle;
public:
    static std::shared_ptr<Intersection> CreateFromCSVLine(std::string line);

    Intersection(const std::string& id, double xCoord, double yCoord);
    void AddInward(std::shared_ptr<Road> road);
    void AddOutward(std::shared_ptr<Road> road);

    glm::vec2 Position() const;

    void Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) override;
};