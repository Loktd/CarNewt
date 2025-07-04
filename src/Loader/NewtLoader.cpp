#include <Loader/NewtLoader.h>

const std::string NewtLoader::ROADS_FILE_NAME = "roads.csv";
const std::string NewtLoader::STREETS_FILE_NAME = "streets.csv";
const std::string NewtLoader::INTERSECTIONS_FILE_NAME = "intersection.csv";

void NewtLoader::CheckForFile(std::string fileName)
{
    if (!std::filesystem::is_regular_file(GetFilePath(fileName))) {
        throw ConfigurationFileNotFound(fileName + " not found...");
    }
}

std::string NewtLoader::GetFilePath(std::string fileName)
{
    return m_DirectoryPath + "/" + fileName;
}

std::ifstream NewtLoader::OpenFile(std::string fileName)
{
    std::ifstream result = std::ifstream(GetFilePath(fileName));

    if (!result.is_open()) {
        throw FileCouldNotBeOpened(fileName + " couldn't be opened...");
    };

    return result;
}

void NewtLoader::AskForDirectory()
{
    std::string path;
    do {
        std::cout << "Please enter the path of the network configuration directory: ";
        std::cin >> path;
        if (!std::filesystem::is_directory(path)) {
            std::cout << "There is no directory with the given name\n";
            path = "";
        }
    } while (!std::filesystem::is_directory(path));

    m_DirectoryPath = path;
}

std::shared_ptr<RoadNetwork> NewtLoader::LoadRoadNetwork()
{
    CheckForFile(ROADS_FILE_NAME);
    CheckForFile(STREETS_FILE_NAME);
    CheckForFile(INTERSECTIONS_FILE_NAME);

    std::shared_ptr<RoadNetwork> result = std::make_shared<RoadNetwork>();

    std::string line;

    std::ifstream intersectionsFile = OpenFile(INTERSECTIONS_FILE_NAME);
    std::getline(intersectionsFile, line);
    while (std::getline(intersectionsFile, line))
    {
        std::shared_ptr<Intersection> ptr = Intersection::CreateFromCSVLine(line);
        result->Add(ptr);
    }

    std::ifstream streetsFile = OpenFile(STREETS_FILE_NAME);
    std::getline(streetsFile, line);
    while (std::getline(streetsFile, line))
    {
        std::shared_ptr<Street> ptr = Street::CreateFromCSVLine(line);
        result->Add(ptr);
    }

    std::ifstream roadsFile = OpenFile(ROADS_FILE_NAME);
    std::getline(roadsFile, line);
    while (std::getline(roadsFile, line))
    {
        auto roadList = Road::CreateFromCSVLine(line, result);
        for (std::shared_ptr<Road> road : roadList) {
            result->Add(road);
        }
    }

    return result;
}
