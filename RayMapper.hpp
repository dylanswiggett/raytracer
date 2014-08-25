#ifndef _RAY_MAPPER_HPP_
#define _RAY_MAPPER_HPP_

#include "glm/glm.hpp"
#include "Scene.hpp"
#include "Ray.hpp"

class RayMapper {
public:
  RayMapper(Scene *scene_init) : scene_(scene_init) { };
  glm::vec3 colorAlongPath(Ray r);
private:
  glm::vec3 raytrace(Ray r, int max_depth);
  Scene *scene_;
};

#endif  // _RAY_MAPPER_HPP_