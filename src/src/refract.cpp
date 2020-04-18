#include <Eigen/Core>

Eigen::Vector3d refract(const Eigen::Vector3d &in, const Eigen::Vector3d &n, float c1, float c2)
{
    ////////////////////////////////////////////////////////////////////////////
    auto r = c1 / c2;
    auto c = -n.dot(in);

    Eigen::Vector3d refraction = r * in + (r * c + sqrt(1 - pow(r, 2) * (1 - pow(c, 2)))) * n;
    return refraction;
    ////////////////////////////////////////////////////////////////////////////
}
