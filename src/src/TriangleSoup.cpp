#include "TriangleSoup.h"
#include "Triangle.h"
#include "first_hit.h"
bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  int i = -1;
  if (first_hit(ray, min_t, triangles, i, t, n))
  {
    return true;
  };
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
