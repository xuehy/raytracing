#include "vec3.h"
const static float pi = 3.1415926536;
const static unsigned width = 1280;
const static unsigned height = 720;
const static float fov = 45;

template <typename T>
struct Ray
{
  Vec3<T> start;
  Vec3<T> dir;
  Ray(const Vec3<T>& _start, const Vec3<T>& _dir) : start(_start), dir(_dir)
  {}
};


