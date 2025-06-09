#pragma once

#include <exception>
#include <string>
#include <iostream>

class MessagedException : public std::exception
{
private:
    std::string m_Message;
public:
    MessagedException(const std::string& message) : m_Message(message) {}

    const std::string& Message() const {
        return m_Message;
    }

    virtual const char* what() const noexcept override {
        return m_Message.c_str();
    }
};