#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Intersection.h"

class Street
{
private:
    std::string m_Name;
    size_t m_SpeedLimit;
public:
    static std::pair<std::string, std::shared_ptr<Street>> CreateFromCSVLine(std::string line);
};