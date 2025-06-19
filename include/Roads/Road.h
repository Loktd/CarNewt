#pragma once

#include <memory>

#include "Intersection.h"
#include "Street.h"
#include <Generics/Identifiable.h>
#include <Roads/RoadNetwork.h>
#include <Graphics/Generics/DisplayedObject.h>
#include <Graphics/Shapes/Line.h>
#include <Exceptions/ModelExceptions.hpp>

class Intersection;
class Street;
class RoadNetwork;

class Road : public Identifiable, public DisplayedObject
{
private:
    std::weak_ptr<Intersection> m_From, m_To;
    std::weak_ptr<Street> m_Street;

    static void ConnectToIntersections(std::shared_ptr<Road> road);
protected:
    std::unique_ptr<Object2D> CreateDisplayed();
public:
    static std::vector<std::shared_ptr<Road>> CreateFromCSVLine(std::string line, const std::shared_ptr<RoadNetwork>& network);

    Road(const std::string& id, std::weak_ptr<Intersection> from, std::weak_ptr<Intersection> to, std::weak_ptr<Street> street);
};