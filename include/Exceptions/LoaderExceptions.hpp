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

class CVSColumnMismatch : public MessagedException
{
public:
    CVSColumnMismatch(const std::string& message) : MessagedException(message) {}
};

class CVSNumberNotFound : public MessagedException
{
public:
    CVSNumberNotFound(const std::string& message) : MessagedException(message) {}
};

class CVSNumberTooBig : public MessagedException
{
public:
    CVSNumberTooBig(const std::string& message) : MessagedException(message) {}
};