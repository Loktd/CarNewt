#pragma once

#include <memory>

#include "Intersection.h"
#include "Street.h"

class Intersection;
class Street;

class Road
{
private:
    std::shared_ptr<Intersection> m_From, m_To;
    std::shared_ptr<Street> m_Street;
    size_t m_Length;
public:
    static std::pair<std::string, std::shared_ptr<Road>> CreateFromCSVLine(std::string line);
};