#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <array>

#include <Exceptions/LoaderExceptions.hpp>

class CSVProcessor
{
public:
    template<int N>
    static std::array<std::string, N> split(std::string line);
};

template<int N>
inline std::array<std::string, N> CSVProcessor::split(std::string line)
{
    size_t delimiterCount = 0;
    for (char c : line) {
        if (c == ',') {
            delimiterCount++;
        }
    }
    if (delimiterCount + 1 != N) {
        throw CVSColumnMismatch("CVS file has " + std::to_string(delimiterCount + 1) + " columns instead of " + std::to_string(N) + " columns.");
    }

    std::array<std::string, N> result;
    std::stringstream stream(line);
    std::string cell;
    for (int i = 0; i < result.size(); i++) {
        std::getline(stream, cell, ',');
        result[i] = cell;
    }

    return result;
}
