#pragma once

#include <memory>

#include "Intersection.h"
#include "Street.h"
#include <Generics/Identifiable.h>
#include <Roads/RoadNetwork.h>
#include <Graphics/Generics/IDrawable2D.h>
#include <Graphics/Shapes/Line.h>

class Intersection;
class Street;
class RoadNetwork;

class Road : public Identifiable, public IDrawable2D
{
private:
    std::shared_ptr<Intersection> m_From, m_To;
    std::shared_ptr<Street> m_Street;

    Line m_Line;

    static void ConnectToIntersections(std::shared_ptr<Road> road);
public:
    static std::vector<std::shared_ptr<Road>> CreateFromCSVLine(std::string line, const std::shared_ptr<RoadNetwork>& network);

    Road(const std::string& id, std::shared_ptr<Intersection> from, std::shared_ptr<Intersection> to, std::shared_ptr<Street> street);
    void Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) override;
};