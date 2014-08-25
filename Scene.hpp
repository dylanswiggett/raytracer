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
  glm::vec3 raytrace(Ray &ray, int max_depth);
  virtual void addSceneObject(SceneObject *obj);
private:
  vector<SceneObject *> *objects_;
};

#endif  // _SCENE_HPP_