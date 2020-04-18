#include "Plane.h"
#include "Ray.h"
#include <iostream>
bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  double denom = normal.dot(ray.direction);
  if (abs(denom) < 1e-6)
  {
    return false;
  };
  double numerator = (point - ray.origin).dot(normal);

  t = numerator / denom;
  if (t > min_t)
  {
    n = normal;
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

