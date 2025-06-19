#pragma once

#include <unordered_map>
#include <memory>

#include "Intersection.h"
#include <Graphics/Generics/IDrawable2D.h>

class Intersection;
class Road;
class Street;

class RoadNetwork : IDrawable2D
{
private:
    std::unordered_map<std::string, std::shared_ptr<Intersection>> m_IntersectionMap;
    std::unordered_map<std::string, std::shared_ptr<Street>> m_StreetMap;
    std::unordered_map<std::string, std::shared_ptr<Road>> m_RoadMap;

public:
    void Add(std::shared_ptr<Intersection> added);
    void Add(std::shared_ptr<Road> added);
    void Add(std::shared_ptr<Street> added);

    std::shared_ptr<Intersection> GetIntersection(const std::string& id) const;
    std::shared_ptr<Street> GetStreet(const std::string& id) const;

    void Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) override;
};
