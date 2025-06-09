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
public:
    void AskForDirectory();
    std::shared_ptr<RoadNetwork> LoadRoadNetwork();
};