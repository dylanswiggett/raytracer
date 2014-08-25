#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <vector>
#include "glm/glm.hpp"
using namespace std;

#include "Ray.hpp"
#include "SceneObject.hpp"

class Scene {
public:
  Scene();
  virtual ~Scene();
  void raytrace(Ray &ray, Ray **collision_ret, Material **material_ret);
  virtual void addSceneObject(SceneObject *obj);
private:
  vector<SceneObject *> *objects_;
};

#endif  // _SCENE_HPP_