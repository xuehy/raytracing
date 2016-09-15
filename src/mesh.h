#include "ray.h"
#include "light.hpp"
#include <list>
#include <limits>
#include <opencv2/opencv.hpp>
#include <algorithm>
template <typename T>
class Sphere
{
public:
  Sphere(const Vec3<T> &c, const T &r) : m_center(c), m_radius(r)
  {}
  Vec3<T> normal(const Vec3<T>& pos) const
  {
    return (pos - m_center).normalized();
  }
  bool intersect(const Ray<T>& ray, T* distance = NULL) const
  {
    auto l = m_center - ray.start;
    auto a = l * ray.dir;
    if( a < 0 ) return false;
    auto b2 = l * l - a * a;
    auto r2 = m_radius * m_radius;
    if(b2 > r2) return false;
    auto c = sqrt(r2 - b2);
    if (distance)
      {
	T near = a - c;
	T far = a + c;
	*distance = (near < 0) ? far : near;
      }
    return true;
  }
  Vec3<T> color() const {return m_color;}
protected:
  Vec3<T> m_center;
  T m_radius;
  Vec3<T> m_color;
};

template <typename T>
struct Scene
{
  std::list<Sphere<T>*> objects;
  std::list<Light<T>*> lights;
};



template <typename T>
Vec3<T> trace(const Ray<T>& ray, const Scene<T>& scene)
{
  T nearest = std::numeric_limits<T>::max();
  const Sphere<T>* obj = NULL;
  for(auto& o : scene)
    {
      T distance = std::numeric_limits<T>::max();
      if(o->intersect(ray, &distance))
	{
	  if(distance < nearest)
	    {
	      nearest = distance;
	      obj = o;
	    }
	}
    }
  return Vec3<T>(10.0/nearest);
    //  return Vec3<T>(obj ? 1 : 0);
}

template <typename T>
void render(const Scene<T>& scene)
{
  Vec3<T> eye(0);
  T h = tan(fov / 360 * 2 * pi / 2) * 2;
  T w = h * width / height;
  cv::Mat img = cv::Mat::zeros(height, width, CV_8UC3);
  uchar *image = reinterpret_cast<uchar*>(img.data);

  for(int y = 0; y < height; ++y)
    for(int x = 0; x < width; ++x)
      {
	Vec3<T> direction((T(x) - width/2) / width * w,
			  (T(height)/2 - y) / height * h,
			  -1.0f);
	direction.normalize();

	auto pixel = trace(Ray<T>(eye, direction), scene);

	uchar r,g,b;
	r = pixel.getX() * 255 + 0.5;
	g = pixel.getY() * 255 + 0.5;
	b = pixel.getZ() * 255 + 0.5;

	r = std::min(r,(uchar)255);
	g = std::min(g,(uchar)255);
	b = std::min(b,(uchar)255);
	int index = 3 * (y * width + x);

	image[index] = b;
	image[index + 1] = g;
	image[index + 2] = r;

	
      }
  cv::imshow("Rendered Scene", img);
  cv::waitKey(0);
}

