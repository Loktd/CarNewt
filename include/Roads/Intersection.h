#pragma once

#include <vector>
#include <array>
#include <memory>

#include "Road.h"

class Road;

class Intersection
{
private:
    std::vector<std::shared_ptr<Road>> m_OutwardRoads;
    std::vector<std::shared_ptr<Road>> m_InwardRoads;
public:
    static std::pair<std::string, std::shared_ptr<Intersection>> CreateFromCSVLine(std::string line);
};