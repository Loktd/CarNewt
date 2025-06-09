#pragma once

#include <string>
#include <unordered_set>

#include <Exceptions/LoaderExceptions.hpp>

class Identifiable
{
private:
    static std::unordered_set<std::string> s_UsedIDSet;
protected:
    std::string m_ID;
public:
    Identifiable(const std::string& id);

    const std::string& ID() const;

    virtual ~Identifiable();
};