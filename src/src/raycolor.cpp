#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"
#include "refract.h"
#include "iostream"
using namespace std;
bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  int hit_id = 0;
  double t = 0;
  Eigen::Vector3d n(0,0,0);
  bool hasHit = false;
  double min_t_epsilon = 1e-6;
  if (first_hit(ray, min_t, objects, hit_id, t, n))
  {
    auto obj = objects[hit_id];
    hasHit = true;
    rgb += blinn_phong_shading(ray, hit_id, t, n, objects, lights);
    if (num_recursive_calls > 0 && obj->material->km.sum() > 0) {
      Eigen::Vector3d interesction_point = (ray.origin + t * ray.direction);
      Eigen::Vector3d reflection = reflect(ray.direction.normalized(), n);

      Ray new_ray;
      new_ray.origin = interesction_point;
      new_ray.direction = reflection.normalized();


      Eigen::Vector3d reflected_rgb(0, 0, 0);
      raycolor(new_ray, min_t_epsilon, objects, lights, num_recursive_calls - 1, reflected_rgb);
      rgb += (obj->material->km.array() * reflected_rgb.array()).matrix();

      // choose medium to be 1 and 1.3, i.e water and air
      Eigen::Vector3d refraction = refract(ray.direction.normalized(), n, 1.0, 1.3);

      Ray new_ray_refraction;
      new_ray_refraction.origin = interesction_point;
      new_ray_refraction.direction = refraction.normalized();

      Eigen::Vector3d refraction_rgb(0, 0, 0);
      raycolor(new_ray_refraction, min_t_epsilon, objects, lights, num_recursive_calls - 1, refraction_rgb);
      rgb += 0.3 * refraction_rgb;
    }
  }
  return hasHit;
  ////////////////////////////////////////////////////////////////////////////
}
