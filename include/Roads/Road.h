#pragma once

#include <memory>

#include "Intersection.h"
#include "Street.h"
#include <Generics/Identifiable.h>
#include <Roads/RoadNetwork.h>

class Intersection;
class Street;
class RoadNetwork;

class Road : public Identifiable
{
private:
    std::shared_ptr<Intersection> m_From, m_To;
    std::shared_ptr<Street> m_Street;
public:
    static std::vector<std::shared_ptr<Road>> CreateFromCSVLine(std::string line, const std::shared_ptr<RoadNetwork>& network);

    Road(const std::string& id, std::shared_ptr<Intersection> from, std::shared_ptr<Intersection> to, std::shared_ptr<Street> street); 
};