#pragma once

#include <vector>
#include <array>
#include <memory>

#include "Road.h"
#include <Loader/CSVProcessor.hpp>
#include <Exceptions/LoaderExceptions.hpp>

class Road;

class Intersection
{
private:
    double m_XCoordinate, m_YCoordinate;

    std::vector<std::shared_ptr<Road>> m_OutwardRoads;
    std::vector<std::shared_ptr<Road>> m_InwardRoads;
public:
    static std::pair<std::string, std::shared_ptr<Intersection>> CreateFromCSVLine(std::string line);

    Intersection(double xCoord, double yCoord);
};