#include "ray.h"
#include <list>
#include <limits>
#include <opencv2/opencv.hpp>

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
protected:
  Vec3<T> m_center;
  T m_radius;
};

template <typename T>
using Scene = std::list<Sphere<T>*> ;

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
  return Vec3<T>(obj ? 1 : 0);
}

template <typename T>
void render(const Scene<T>& scene)
{
  Vec3<T> eye(0);
  T h = tan(fov / 360 * 2 * pi / 2) * 2;
  T w = h * width / height;
  cv::Mat img = cv::Mat(h, w, CV_8UC3);
  for(int y = 0; y < h; ++y)
    for(int x = 0; x < w; ++x)
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
	r = min(r,255);
	g = min(g,255);
	b = min(b,255);
	img.at<cv::Vec3b>(y,x) = cv::Vec3b(b,g,r);
      }
  imshow("ds", img);
  waitKey(0);
}

