#include <iostream>
#include <png++/png.hpp>

#include "glm/glm.hpp"

using namespace std;

#include "Scene.hpp"
#include "SceneObject.hpp"
#include "SceneObjects.hpp"

int main(int argc, char** argv) {
  png::image<png::rgb_pixel> image(512, 512);

  Scene scene;

  Sphere *s = new Sphere(glm::vec3(-3, .2, 0), 3);
  s->getmat()->reflectivity = .4;
  scene.addSceneObject(s);
  scene.addSceneObject(new Sphere(glm::vec3(1, 4, 1), 1));
  scene.addSceneObject(new Sphere(glm::vec3(3, .4, -1), 2));

  Plane *p = new Plane(glm::vec3(5, 0, 0), glm::vec3(-1, 0, 0));
  p->getmat()->reflectivity = .3;
  p->getmat()->r = p->getmat()->g = 0;
  scene.addSceneObject(p);

  p = new Plane(glm::vec3(0, 0, 8), glm::vec3(0, -1, -1));
  p->getmat()->reflectivity = .3;
  p->getmat()->b = p->getmat()->g = 0;
  scene.addSceneObject(p);

  p = new Plane(glm::vec3(0, 0, 8), glm::vec3(0, 1, -1));
  p->getmat()->reflectivity = .3;
  p->getmat()->r = p->getmat()->b = 0;
  scene.addSceneObject(p);

  glm::vec3 camPos(0, 0, -10);
  glm::vec3 camFor(0, 0, 1);
  glm::vec3 camRight(1, 0, 0);
  glm::vec3 camUp(0, 1, 0);

  int w = image.get_width();
  int h = image.get_height();

  float rightOffset = 2 / ((float) w);
  float upOffset = 2 / ((float) h);

  for (float x = 0; x < w; x++) {
    for (float y = 0; y < h; y++) {
      Ray camRay(camPos,
        glm::normalize(camFor +
          camRight * ((x - w/2) * rightOffset) +
          camUp * ((y - h/2) * upOffset)));

      glm::vec3 color = scene.raytrace(camRay, 3);

      image[x][y] = png::rgb_pixel(color.x * 255, color.y * 255, color.z * 255);
    }
  }

  image.write("test_png.png");
}