#include "mesh.h"
int main()
{
  Scene<float> scene = { new Sphere<float>({0, -10002, -20}, 10000),
			 new Sphere<float>({0, 2, -20},      4    ),
			 new Sphere<float>({5, 0, -15},      2    ),
			 new Sphere<float>({-5, 0, -15},     2    ),
			 new Sphere<float>({-2, -1, -10},    1    ) };
  render(scene);
  return 0;
}
