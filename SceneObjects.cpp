#include <iostream>
#include "glm/glm.hpp"

#include "SceneObjects.hpp"
#include "Ray.hpp"

/**********
 * SPHERE *
 **********/

Ray *Sphere::raytrace(Ray *ray) {
  glm::vec3 L = pos_ - ray->pos;
  float tca = glm::dot(L, ray->dir);
  if (tca < 0) return nullptr;
  float d2 = glm::dot(L, L) - tca * tca;
  if (d2 > rad_ * rad_) return nullptr;
  float thc = sqrt(rad_ * rad_ - d2);
  float t0 = tca - thc;
  float t1 = tca + thc;

  float t = t0;
  if (t0 < 0)
    t = t1;
  if (t1 < 0) return nullptr;

  if (ray->rayMax < t) return nullptr;

  glm::vec3 intersection = ray->pos + ray->dir * t;

  ray->rayMax = t;

  return new Ray(intersection, glm::normalize(intersection - pos_));
}

/*********
 * PLANE *
 *********/

Ray *Plane::raytrace(Ray *ray) {
  glm::vec3 diff = ray->pos - pos_;
  float rayToOrigLength    =   glm::dot(diff, norm_);
  float parallelCompLength = - glm::dot(ray->dir, norm_);
  if (parallelCompLength < .0001 && parallelCompLength > -.0001)
    return nullptr;
  float t = rayToOrigLength / parallelCompLength;
  if (t <= 0.0001 || t > ray->rayMax)
    return nullptr;

  ray->rayMax = t;

  return new Ray(ray->pos + ray->dir * t, norm_);
}