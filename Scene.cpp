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

void Scene::raytrace(Ray &ray, Ray **collision_ret, Material **material_ret) {
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

  if (r != nullptr)
    *collision_ret = r;

  *material_ret = m;
}

void Scene::addSceneObject(SceneObject *obj) {
  objects_->push_back(obj);
}