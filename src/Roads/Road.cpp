#include <Roads/Road.h>

std::vector<std::shared_ptr<Road>> Road::CreateFromCSVLine(std::string line, const std::shared_ptr<RoadNetwork>& network)
{
    std::array<std::string, 6> tokenized = CSVProcessor::split<6>(line);
    std::vector<std::shared_ptr<Road>> result;

    std::string idBase = "R" + tokenized[0];
    std::string fromID = "I" + tokenized[1];
    std::string toID = "I" + tokenized[2];
    std::string streetID = "S" + tokenized[5];
    size_t forwardCount;
    size_t backwardCount;
    try {
        forwardCount = std::stoull(tokenized[3]);
        backwardCount = std::stoull(tokenized[4]);
    }
    catch (const std::invalid_argument& e) {
        throw CVSNumberNotFound("Lane count contains non-number value in line: \"" + line + "\".");
    }
    catch (const std::out_of_range& e) {
        throw CVSNumberTooBig("Lane count number too big in line: \"" + line + "\".");
    }

    std::shared_ptr<Intersection> from = network->GetIntersection(fromID), to = network->GetIntersection(toID);
    std::shared_ptr<Street> street = network->GetStreet(streetID);

    for (size_t i = 0; i < forwardCount; i++) {
        std::string id = idBase + "F" + std::to_string(i + 1);
        result.push_back(std::make_shared<Road>(id, from, to, street));
    }

    for (size_t i = 0; i < backwardCount; i++) {
        std::string id = idBase + "B" + std::to_string(i + 1);
        result.push_back(std::make_shared<Road>(id, from, to, street));
    }

    return result;
}

Road::Road(const std::string& id, std::shared_ptr<Intersection> from, std::shared_ptr<Intersection> to, std::shared_ptr<Street> street)
    : Identifiable(id), m_From(from), m_To(to), m_Street(street)
{
}
