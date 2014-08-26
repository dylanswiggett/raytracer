#ifndef _RAY_HPP_
#define _RAY_HPP_

#include "glm/glm.hpp"

class Ray {
public:
  Ray() { };
  Ray(glm::vec3 init_pos, glm::vec3 init_dir) : pos(init_pos), dir(init_dir) { rayMax = 1000000; };

  glm::vec3 pos, dir;
  float rayMax;
};

#endif  // _RAY_HPP_