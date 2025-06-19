#pragma once

#include "MessagedException.hpp"

class WeakPointerInvalid : public MessagedException
{
public:
    WeakPointerInvalid(const std::string& message) : MessagedException(message) {}
};