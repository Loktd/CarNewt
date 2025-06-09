#pragma once

#include <map>
#include <memory>

#include "Intersection.h"

class RoadNetwork
{
private:
public:
    void Add(std::string id, std::shared_ptr<Intersection> added);
    void Add(std::string id, std::shared_ptr<Road> added);
    void Add(std::string id, std::shared_ptr<Street> added);
};
