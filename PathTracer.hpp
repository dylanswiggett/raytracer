#ifndef _PATH_TRACER_HPP_
#define _PATH_TRACER_HPP_

#include "glm/glm.hpp"
#include "Scene.hpp"

class PathTracer {
public:
  PathTracer(Scene *scene_init) : scene_(scene_init) { };
  glm::vec3 colorAlongPath(Ray path);
private:
  glm::vec3 random_dir_in_hemisphere(glm::vec3 normal);
  glm::vec3 pathtrace(Ray r, int max_depth);
  Scene *scene_;
};

#endif  // _PATH_TRACER_HPP_