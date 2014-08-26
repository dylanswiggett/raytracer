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

bool Scene::raytrace(Ray &ray, Ray *collision_ret, Material **material_ret) {
  Ray r;
  Material *m;
  bool success = false;

  for (auto obj : *objects_) {
    Ray r_temp;
    if (obj->raytrace(&ray, &r_temp)) {
      r = r_temp;
      m = obj->getmat();
      success = true;
    }
  }

  if (success) {
    *collision_ret = r;
    *material_ret = m;
    return true;
  }

  return false;
}

void Scene::addSceneObject(SceneObject *obj) {
  objects_->push_back(obj);
}