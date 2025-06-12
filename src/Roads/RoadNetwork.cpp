#include <Roads/RoadNetwork.h>

void RoadNetwork::Add(std::shared_ptr<Intersection> added)
{
    m_IntersectionMap[added->ID()] = added;
}

void RoadNetwork::Add(std::shared_ptr<Road> added)
{
    m_RoadMap[added->ID()] = added;
}

void RoadNetwork::Add(std::shared_ptr<Street> added)
{
    m_StreetMap[added->ID()] = added;
}

std::shared_ptr<Intersection> RoadNetwork::GetIntersection(const std::string& id) const
{
    return m_IntersectionMap.at(id);
}

std::shared_ptr<Street> RoadNetwork::GetStreet(const std::string& id) const
{
    return m_StreetMap.at(id);
}

void RoadNetwork::Draw(std::shared_ptr<Shader2D> shader, std::shared_ptr<Camera2D> camera) {
    for (auto [name, intersection] : m_IntersectionMap) {
        intersection->Draw(shader, camera);
    }

    for (auto [name, road] : m_RoadMap) {
        road->Draw(shader, camera);
    }
}
