#pragma once

#include <Exceptions/MessagedException.hpp>

class UnknownSceneName : public MessagedException
{
public:
    UnknownSceneName(const std::string& message) : MessagedException(message) {}
};
