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
        auto road = std::make_shared<Road>(id, from, to, street);
        result.push_back(road);
        Road::ConnectToIntersections(road);
    }

    for (size_t i = 0; i < backwardCount; i++) {
        std::string id = idBase + "B" + std::to_string(i + 1);
        auto road = std::make_shared<Road>(id, from, to, street);
        result.push_back(road);
        Road::ConnectToIntersections(road);
    }

    return result;
}

void Road::ConnectToIntersections(std::shared_ptr<Road> road)
{
    if (auto from = road->m_From.lock()) {
        from->AddOutward(road);
    }
    if (auto to = road->m_From.lock()) {
        to->AddInward(road);
    }
}

std::unique_ptr<Object2D> Road::CreateDisplayed()
{
    std::shared_ptr<Intersection> from = m_From.lock();
    std::shared_ptr<Intersection> to = m_To.lock();

    if (from && to) {
        return std::make_unique<Line>(from->Position(), to->Position(), glm::vec4(0, 0, 0, 1), 10);
    }

    throw WeakPointerInvalid("A road's weak pointer to an intersection is invalid when trying to create the displayed shape.");
}

Road::Road(const std::string& id, std::weak_ptr<Intersection> from, std::weak_ptr<Intersection> to, std::weak_ptr<Street> street)
    : Identifiable(id), m_From(from), m_To(to), m_Street(street)
{
}
