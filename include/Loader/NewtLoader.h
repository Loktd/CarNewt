#pragma once 

#include <string>
#include <memory>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <functional>

#include <Roads/Intersection.h>
#include <Roads/RoadNetwork.h>
#include <Exceptions/LoaderExceptions.hpp>

class NewtLoader
{
private:
    static const std::string ROADS_FILE_NAME;
    static const std::string STREETS_FILE_NAME;
    static const std::string INTERSECTIONS_FILE_NAME;

    std::string m_DirectoryPath;

    void CheckForFile(std::string fileName);
    std::string GetFilePath(std::string fileName);
    std::ifstream OpenFile(std::string fileName);

    template<typename T>
    void CreateAll(const std::string& fileName, std::shared_ptr<RoadNetwork> to);
public:
    void AskForDirectory();
    std::shared_ptr<RoadNetwork> LoadRoadNetwork();
};

template<typename T>
inline void NewtLoader::CreateAll(const std::string& fileName, std::shared_ptr<RoadNetwork> to)
{
    std::ifstream file = OpenFile(fileName);

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        auto [id, next] = T::CreateFromCSVLine(line);
        to->Add(id, next);
    }
}
