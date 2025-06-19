#pragma once

#include <vector>
#include <array>
#include <memory>

#include <Roads/Road.h>
#include <Loader/CSVProcessor.hpp>
#include <Exceptions/LoaderExceptions.hpp>
#include <Generics/Identifiable.h>
#include <Graphics/Generics/DisplayedObject.h>
#include <Graphics/Shapes/Circle.h>

class Road;

class Intersection : public Identifiable, public DisplayedObject
{
private:
    double m_XCoordinate, m_YCoordinate;

    std::vector<std::weak_ptr<Road>> m_OutwardRoads;
    std::vector<std::weak_ptr<Road>> m_InwardRoads;
protected:
    std::unique_ptr<Object2D> CreateDisplayed() override;
public:
    static std::shared_ptr<Intersection> CreateFromCSVLine(std::string line);

    Intersection(const std::string& id, double xCoord, double yCoord);
    void AddInward(std::weak_ptr<Road> road);
    void AddOutward(std::weak_ptr<Road> road);

    glm::vec2 Position() const;
};