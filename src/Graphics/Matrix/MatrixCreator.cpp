#include <Graphics/Matrix/MatrixCreator.h>

glm::mat4 MatrixCreator::Translate(const glm::vec3& by) {
    glm::vec4
        row1(1, 0, 0, 0),
        row2(0, 1, 0, 0),
        row3(0, 0, 1, 0),
        row4(by.x, by.y, by.z, 1);

    return glm::mat4(row1, row2, row3, row4);
}

glm::mat4 MatrixCreator::Scale(const glm::vec3& factor) {
    glm::vec4
        row1(factor.x, 0, 0, 0),
        row2(0, factor.y, 0, 0),
        row3(0, 0, factor.z, 0),
        row4(0, 0, 0, 1);

    return glm::mat4(row1, row2, row3, row4);
}

glm::mat4 MatrixCreator::Rotate(float angle, const glm::vec3& around)
{
    float cosine = cosf(angle);
    float sine = sinf(angle);
    glm::vec3 normalized = normalize(around);

    glm::vec4
        row1(cosine * (1 - normalized.x * normalized.x) + normalized.x * normalized.x, normalized.x * normalized.y * (1 - cosine) + normalized.z * sine, normalized.x * normalized.z * (1 - cosine) - normalized.y * sine, 0),
        row2(normalized.x * normalized.y * (1 - cosine) - normalized.z * sine, cosine * (1 - normalized.y * normalized.y) + normalized.y * normalized.y, normalized.y * normalized.z * (1 - cosine) + normalized.x * sine, 0),
        row3(normalized.x * normalized.z * (1 - cosine) + normalized.y * sine, normalized.y * normalized.z * (1 - cosine) - normalized.x * sine, cosine * (1 - normalized.z * normalized.z) + normalized.z * normalized.z, 0),
        row4(0, 0, 0, 1);

    return glm::mat4(row1, row2, row3, row4);
}