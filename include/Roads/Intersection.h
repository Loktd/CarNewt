#pragma once

#include <vector>
#include <array>
#include <memory>

#include "Road.h"
#include <Loader/CSVProcessor.hpp>
#include <Exceptions/LoaderExceptions.hpp>
#include <Generics/Identifiable.h>

class Road;

class Intersection : public Identifiable
{
private:
    double m_XCoordinate, m_YCoordinate;

    std::vector<std::shared_ptr<Road>> m_OutwardRoads;
    std::vector<std::shared_ptr<Road>> m_InwardRoads;
public:
    static std::shared_ptr<Intersection> CreateFromCSVLine(std::string line);

    Intersection(const std::string& id, double xCoord, double yCoord);
};