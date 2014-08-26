#ifndef _SCENE_OBJECT_HPP_
#define _SCENE_OBJECT_HPP_

#include "Ray.hpp"
#include "Material.hpp"

class SceneObject {
public:
  // Attempts to trace the given ray onto this object. If no collision
  // occurs, the return value is false. If a collision occurs, a ray
  // is returned containing the material values of the object hit, from
  // the point of collision and in the direction of the surface normal.
  virtual bool raytrace(Ray *ray, Ray *ret) = 0;
  virtual Material *getmat() { return &material; };
  virtual void setmat(Material m) { material = m; };

protected:
  Material material;
};

#endif  // _SCENE_OBJECT_HPP_