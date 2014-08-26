#include <iostream>
#include "glm/glm.hpp"

#include "SceneObjects.hpp"
#include "Ray.hpp"

/**********
 * SPHERE *
 **********/

bool Sphere::raytrace(Ray *ray, Ray *ret) {
  glm::vec3 L = pos_ - ray->pos;
  float tca = glm::dot(L, ray->dir);
  if (tca < 0) return false;
  float d2 = glm::dot(L, L) - tca * tca;
  if (d2 > rad_ * rad_) return false;
  float thc = sqrt(rad_ * rad_ - d2);
  float t0 = tca - thc;
  float t1 = tca + thc;

  float t = t0;
  if (t0 < 0)
    t = t1;
  if (t1 < 0) return false;

  if (ray->rayMax < t) return false;

  glm::vec3 intersection = ray->pos + ray->dir * t;

  ray->rayMax = t;

  *ret = Ray(intersection, (intersection - pos_) / rad_);
  return true;
}

/*********
 * PLANE *
 *********/

bool Plane::raytrace(Ray *ray, Ray *ret) {
  glm::vec3 diff = ray->pos - pos_;
  float rayToOrigLength    =   glm::dot(diff, norm_);
  float parallelCompLength = - glm::dot(ray->dir, norm_);
  if (parallelCompLength < .0001 && parallelCompLength > -.0001)
    return false;
  float t = rayToOrigLength / parallelCompLength;
  if (t <= 0.0001 || t > ray->rayMax)
    return false;

  ray->rayMax = t;

  *ret = Ray(ray->pos + ray->dir * t, norm_);
  return true;
}