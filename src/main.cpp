#include "mesh.h"
int main()
{
  Scene<float> scene;
  scene.objects = { new Sphere<float>({0, -10002, -20}, 10000, Vec3<float>(.8,.8,.8), 0.2),
		    new Sphere<float>({0, 2, -20},      4, Vec3<float>(.8,.5,.5), 0.5    ),
		    new Sphere<float>({5, 0, -15},      2, Vec3<float>(.3,.8,.8), 0.2, 0.4    ),
		    new Sphere<float>({-5, 0, -15},     2, Vec3<float>(.3, .5, .8), 0.2    ),
		    new Sphere<float>({2, -1, -9},    1, Vec3<float>(.1,.1,.1), 0.1, 0.8    ) };
  scene.lights = {new Light<float>(Vec3<float>(-10,20,30), Vec3<float>(2,2,2))};
  render(scene);
  return 0;
}
