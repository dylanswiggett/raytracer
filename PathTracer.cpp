#include "PathTracer.hpp"

#define GLM_FORCE_RADIANS
#include <glm/gtx/rotate_vector.hpp>

#define NUM_RAYS 50
#define PI 3.1415

glm::vec3 PathTracer::colorAlongPath(Ray path) {
  return pathtrace(path, 2);
}

glm::vec3 PathTracer::random_dir_in_hemisphere(glm::vec3 normal) {
  // from http://mathworld.wolfram.com/SpherePointPicking.html
  float u = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
  float v = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);

  float theta = 2*PI*u;
  float phi = acos(2*v-1);

  glm::vec3 perp;

  if (normal.y != 0 || normal.x != 0)
    perp = glm::normalize(glm::vec3(normal.y, -normal.x, 0));
  else
    perp = glm::normalize(glm::vec3(1, 0, 0));

  perp = glm::rotate(perp, theta, normal);

  return normal * sin(phi) + perp * cos(phi);
}

glm::vec3 PathTracer::pathtrace(Ray r, int max_depth) {
  Ray *collision = nullptr;
  Material *m;

  for (int i = 0; i < NUM_RAYS; i++) {
    scene_->raytrace(r, &collision, &m);
  }
}
