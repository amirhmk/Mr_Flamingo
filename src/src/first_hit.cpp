#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  int i = 0;
  t = 9e99;
  double temp_t = t;
  Eigen::Vector3d temp_n = n;
  bool interSects = false;
  for (auto const &obj : objects)
  {
    if (obj->intersect(ray, min_t, temp_t, temp_n))
    {
      if (temp_t < t)
      {
        t = temp_t;
        n = temp_n;
        interSects = true;
        hit_id = i;
      }
    };
    i++;
  }
  return interSects;
  ////////////////////////////////////////////////////////////////////////////
}
