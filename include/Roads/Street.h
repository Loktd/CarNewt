#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Intersection.h"
#include <Generics/Identifiable.h>

class Street : public Identifiable
{
private:
    std::string m_Name;
    size_t m_SpeedLimit;
public:
    static std::shared_ptr<Street> CreateFromCSVLine(std::string line);

    Street(const std::string& id, const std::string& name, size_t speedLimit);
};