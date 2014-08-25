#ifndef _PATH_TRACER_HPP_
#define _PATH_TRACER_HPP_

#include "glm/glm.hpp"
#include "Scene.hpp"

class PathTracer {
public:
  PathTracer(Scene *scene_init) : scene_(scene_init) { };
  glm::vec3 colorAlongPath(glm::vec3 path);
private:
  Scene *scene_;
};

#endif  // _PATH_TRACER_HPP_