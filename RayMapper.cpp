#include "RayMapper.hpp"

glm::vec3 RayMapper::colorAlongPath(Ray r) {
  return raytrace(r, 3);
}

glm::vec3 RayMapper::raytrace(Ray r, int max_depth) {
  Ray collision;
  Material *m;

  glm::vec3 color(0,0,0);

  if (scene_->raytrace(r, &collision, &m)) {
    color = glm::vec3(m->r, m->g, m->b);

    float c = glm::dot(collision.dir, glm::normalize(glm::vec3(0, 1, -1))) + .2;
    if (c < 0) c = 0;
    if (c > 1) c = 1;
    color *= c;

    if (max_depth > 0 && m->reflectivity > 0) {
      glm::vec3 parallel_comp = collision.dir * glm::dot(collision.dir, r.dir);
      glm::vec3 direction = r.dir - parallel_comp - parallel_comp;
      Ray reflection(collision.pos, direction);
      glm::vec3 refl_ray = raytrace(reflection, max_depth - 1);

      color = color * (1 -m->reflectivity) + refl_ray * m->reflectivity;
    }
  }

  return color;
}
