#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <algorithm> // std::max

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Vector3d L(0,0,0);
  auto obj = objects[hit_id];
  double ambient_light_I = 0.1;
  Eigen::Vector3d interesction_point = (ray.origin + t*ray.direction);

  for (auto &light: lights) {
    Eigen::Vector3d d(0,0,0);
    double max_t = 0;
    light->direction(interesction_point, d, max_t);

    Ray light_ray;
    light_ray.origin = interesction_point;
    light_ray.direction = d;

    Eigen::Vector3d light_vector = d;

    int light_hit_id;
    double light_hit_t;
    Eigen::Vector3d temp_n(0,0,0);
    Eigen::Vector3d v = -ray.direction.normalized();
    auto lambertian = (obj->material->kd.array() * light->I.array() * std::max(0.0, n.normalized().dot(light_vector))).matrix();

    auto h = (v + light_vector).normalized();
    auto specular = (obj->material->ks.array() * light->I.array() * pow(std::max(0.0, n.normalized().dot(h)), obj->material->phong_exponent)).matrix();

    double min_t_epsilon = 1e-6;
    // Check for shadow
    if (first_hit(light_ray, min_t_epsilon, objects, light_hit_id, light_hit_t, temp_n))
    {
      // Don't care if item is "behind" the light
      if (light_hit_t > max_t) {
        L += lambertian;
        L += specular;
      }      
    }
    // No shadow
    else {
      L += lambertian;
      L += specular;
    }
  }  
  // Ambient
  L += obj->material->ka * ambient_light_I;
  return L;
  ////////////////////////////////////////////////////////////////////////////
}
