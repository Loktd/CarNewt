#include <Generics/Identifiable.h>

std::unordered_set<std::string> Identifiable::s_UsedIDSet;

Identifiable::Identifiable(const std::string& id) : m_ID(id)
{
    if (s_UsedIDSet.count(id) > 0) {
        throw DuplicateIDFound("Tried to use the following ID twice: \"" + id + "\".");
    }
    s_UsedIDSet.insert(id);
}

const std::string& Identifiable::ID() const
{
    return m_ID;
}

Identifiable::~Identifiable() {}
