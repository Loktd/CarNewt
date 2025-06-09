#include <Roads/Street.h>

std::shared_ptr<Street> Street::CreateFromCSVLine(std::string line)
{
    std::array<std::string, 3> tokenized = CSVProcessor::split<3>(line);

    std::string id = "S" + tokenized[0];
    std::string name = tokenized[1];
    size_t limit;
    try {
        limit = std::stoull(tokenized[2]);
    }
    catch (const std::invalid_argument& e) {
        throw CVSNumberNotFound("Street speed limit contains non-number value in line: \"" + line + "\".");
    }
    catch (const std::out_of_range& e) {
        throw CVSNumberTooBig("Street speed limit too big in line: \"" + line + "\".");
    }

    return std::make_shared<Street>(id, name, limit);
}

Street::Street(const std::string& id, const std::string& name, size_t speedLimit)
    : Identifiable(id), m_Name(name), m_SpeedLimit(speedLimit)
{
}
