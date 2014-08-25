#include "PathTracer.hpp"
#include <iostream>

#define GLM_FORCE_RADIANS
#include <glm/gtx/rotate_vector.hpp>

#define NUM_RAYS 40
#define PI 3.1415

glm::vec3 PathTracer::colorAlongPath(Ray path) {
  float light;
  return pathtrace(path, 1, &light);
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
    perp = glm::vec3(1, 0, 0);

  perp = glm::rotate(perp, theta, normal);

  return normal * sin(phi) + perp * cos(phi);
}

glm::vec3 PathTracer::pathtrace(Ray r, int max_depth, float *light) {
  Ray *collision = nullptr;
  Material *m;

  scene_->raytrace(r, &collision, &m);

  if (collision != nullptr) {
    float total_light = 0;
    if (max_depth > 0) {
      for (int i = 0; i < NUM_RAYS; i++) {
        float light_incident;
        glm::vec3 dir = random_dir_in_hemisphere(collision->dir);

        glm::vec3 refl_color = pathtrace(Ray(collision->pos, dir), max_depth - 1, &light_incident);

        total_light += light_incident;
      }
      total_light /= NUM_RAYS;
    }

    *light = total_light + m->light_emit;
    return glm::vec3(m->r, m->g, m->b) * min(*light, 1.0f);
  } else {
    return glm::vec3(0,0,0);
  }
}
