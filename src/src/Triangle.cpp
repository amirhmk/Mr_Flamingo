#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>
#include <iostream>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d corner_a = std::get<0>(corners);
  Eigen::Vector3d corner_b = std::get<1>(corners);
  Eigen::Vector3d corner_c = std::get<2>(corners);

  Eigen::Matrix3d A;
  Eigen::Vector3d b;

  A << corner_a - corner_b, corner_a - corner_c, ray.direction;
  b << corner_a - ray.origin;

  Eigen::Vector3d x = A.inverse() * (b);

  double beta = x[0];
  double gamma = x[1];
  double t_temp = x[2];

  if (beta > 0 && gamma > 0 && beta + gamma < 1)
  {
    t = t_temp;
    n = (corner_b - corner_a).cross(corner_c - corner_a).normalized();
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}


