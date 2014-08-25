#include <vector>
#include "glm/glm.hpp"
using namespace std;

#include "Scene.hpp"
#include "SceneObject.hpp"

Scene::Scene() {
  objects_ = new vector<SceneObject *>();
}

Scene::~Scene() {
  delete objects_;
}

glm::vec3 Scene::raytrace(Ray &ray, int max_depth) {
  Ray *r = nullptr;
  Material *m;

  for (auto obj : *objects_) {
    Ray *r_temp = obj->raytrace(&ray);
    if (r_temp != nullptr) {
      if (r != nullptr)
        delete r;
      r = r_temp;
      m = obj->getmat();
    }
  }

  glm::vec3 color(0,0,0);

  if (r != nullptr) {
    color = glm::vec3(m->r, m->g, m->b);
    float c = glm::dot(r->dir, glm::normalize(glm::vec3(0, 1, -1))) + .2;
    if (c < 0) c = 0;
    if (c > 1) c = 1;
    color *= c;

    if (max_depth > 0 && m->reflectivity > 0) {
      glm::vec3 parallel_comp = r->dir * glm::dot(r->dir, ray.dir);
      glm::vec3 direction = ray.dir - parallel_comp - parallel_comp;
      Ray reflection(r->pos, direction);
      glm::vec3 refl_ray = raytrace(reflection, max_depth - 1);

      color = color * (1 -m->reflectivity) + refl_ray * m->reflectivity;
    }

    delete r;
    return color;
  }

  return color;
}

void Scene::addSceneObject(SceneObject *obj) {
  objects_->push_back(obj);
}