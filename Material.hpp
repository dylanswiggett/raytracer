#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_

class Material {
public:
  Material() : r(1), g(1), b(1), diffuse(0), reflectivity(.2) { };
  float r, g, b;
  float diffuse;
  float reflectivity;
  float transparency, index_of_refraction;
  float light_emit;
};

class MaterialBuilder {
  MaterialBuilder() { };
  MaterialBuilder &color(float r, float g, float b) {
    m.r = r;
    m.g = g;
    m.b = b;
    return *this;
  };
  MaterialBuilder &diffuse(float d) {
    m.diffuse = d;
    return *this;
  };
  MaterialBuilder &reflectivity(float r) {
    m.reflectivity = r;
    return *this;
  };
  MaterialBuilder &transparency(float t, float ior) {
    m.transparency = t;
    m.index_of_refraction = ior;
    return *this;
  };
  MaterialBuilder &light_emit(float l) {
    m.light_emit = l;
    return *this;
  };
  Material build() {
    return m;
  }
private:
  Material m;
};

#endif  // _MATERIAL_HPP_