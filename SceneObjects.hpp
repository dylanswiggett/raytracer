#ifndef _SCENE_OBJECTS_HPP_
#define _SCENE_OBJECTS_HPP_

#include "glm/glm.hpp"

#include "SceneObject.hpp"
#include "Ray.hpp"

class Sphere : public SceneObject {
public:
  Sphere(glm::vec3 position, float radius) : pos_(position), rad_(radius) { };
  virtual bool raytrace(Ray *ray, Ray *ret);
private:
  glm::vec3 pos_;
  float rad_;
};

class Plane : public SceneObject {
public:
  Plane(glm::vec3 position, glm::vec3 normal) : pos_(position), norm_(glm::normalize(normal)) { };
  virtual bool raytrace(Ray *ray, Ray *ret);
protected:
  glm::vec3 pos_;
  glm::vec3 norm_;
};

#endif  // _SCENE_OBJECTS_HPP_