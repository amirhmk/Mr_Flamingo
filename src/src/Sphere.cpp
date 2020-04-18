#include "Sphere.h"
#include "Ray.h"

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d center_off = ray.origin - center;

  double B_inside = pow(ray.direction.dot(center_off), 2);
  double disc = B_inside - (ray.direction.dot(ray.direction) * (center_off.dot(center_off) - pow(radius, 2)));

  // No solution
  if (disc < 0)
  {
    return false;
  }
  else
  {
    double t_1 = (-ray.direction.dot(center_off) + sqrt(disc)) / ray.direction.dot(ray.direction);
    double t_2 = (-ray.direction.dot(center_off) - sqrt(disc)) / ray.direction.dot(ray.direction);

    if (t_1 > min_t)
    {
      if (t_1 < t_2 && t_2 > min_t)
      {
        t = t_1;
        n << ((ray.origin + t_1 * ray.direction) - center) / radius;
        return true;
      }
    }
    if (t_2 > min_t)
    {
      t = t_2;
      n << ((ray.origin + t_2 * ray.direction) - center) / radius;
      return true;
    }
    return false;
  }
  ////////////////////////////////////////////////////////////////////////////
}

