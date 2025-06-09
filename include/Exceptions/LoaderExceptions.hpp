#pragma once

#include "MessagedException.hpp"

class ConfigurationFileNotFound : public MessagedException
{
public:
    ConfigurationFileNotFound(const std::string& message) : MessagedException(message) {}
};

class FileCouldNotBeOpened : public MessagedException
{
public:
    FileCouldNotBeOpened(const std::string& message) : MessagedException(message) {}
};