#include "mesh.h"
int main()
{
  Scene<float> scene;
  scene.objects = { new Sphere<float>({0, -10002, -20}, 10000, Vec3<float>(.8,.8,.8)),
			 new Sphere<float>({0, 2, -20},      4, Vec3<float>(.8,.5,.5)    ),
			 new Sphere<float>({5, 0, -15},      2, Vec3<float>(.3,.8,.8)    ),
			 new Sphere<float>({-5, 0, -15},     2, Vec3<float>(.3, .5, .8)    ),
			 new Sphere<float>({-2, -1, -10},    1, Vec3<float>(.3,.8,.3)    ) };
  scene.lights = {new Light<float>(Vec3<float>(-10,20,30), Vec3<float>(2,2,2))};
  render(scene);
  return 0;
}
