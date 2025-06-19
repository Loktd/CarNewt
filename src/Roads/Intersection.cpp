#include <Roads/Intersection.h>

std::unique_ptr<Object2D> Intersection::CreateDisplayed()
{
    return std::make_unique<Circle>(glm::vec2(m_XCoordinate, m_YCoordinate), 10, glm::vec4(0, 0, 0, 1));
}

std::shared_ptr<Intersection> Intersection::CreateFromCSVLine(std::string line)
{
    std::array<std::string, 4> tokenized = CSVProcessor::split<4>(line);

    std::string id = "I" + tokenized[0];
    double x;
    double y;
    try {
        x = std::stod(tokenized[1]);
        y = std::stod(tokenized[2]);
    }
    catch (const std::invalid_argument& e) {
        throw CVSNumberNotFound("Intersection location contains non-number value in line: \"" + line + "\".");
    }
    catch (const std::out_of_range& e) {
        throw CVSNumberTooBig("Intersection location number too big in line: \"" + line + "\".");
    }
    std::string type = tokenized[3];

    return std::make_shared<Intersection>(id, x, y);
}

Intersection::Intersection(const std::string& id, double xCoord, double yCoord)
    : Identifiable(id), m_XCoordinate(xCoord), m_YCoordinate(yCoord)
{
}

void Intersection::AddInward(std::shared_ptr<Road> road)
{
    m_InwardRoads.push_back(road);
}

void Intersection::AddOutward(std::shared_ptr<Road> road)
{
    m_OutwardRoads.push_back(road);
}

glm::vec2 Intersection::Position() const
{
    return glm::vec2(m_XCoordinate, m_YCoordinate);
}
