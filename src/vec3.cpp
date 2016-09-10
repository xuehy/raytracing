#include <iostream>

template <typename T>
class Vec3
{
  T x;
  T y;
  T z;
public:
  Vec3(const T &a, const T &b, const T &c) : x(a), y(b), z(c) {}
  Vec3<T> operator+(const Vec3<T>& v);
  Vec3<T> operator-(const Vec3<T>& v);
  T operator*(const Vec3<T>& v);
  void show();
};

template <typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T>& v)
{
  return Vec3<T>(x + v.x, y + v.y, z + v.z);
}

template <typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T>& v)
{
  return Vec3<T>(x - v.x, y - v.y, z - v.z);
}

template <typename T>
T Vec3<T>::operator*(const Vec3<T>& v)
{
  return v.x*x + v.y*y + v.z*z;
}

template <typename T>
void Vec3<T>::show()
{
  std::cout << x << ", " << y << ", " << z << std::endl;
}

int main()
{
  Vec3<double> v(1.,2.,3.);
  Vec3<double> u(-1.,2.5,7.1);
  v.show();
  Vec3<double> w1 = u + v;
  Vec3<double> w2 = u - v;
  w1.show();
  w2.show();
  double z = u * v;
  std::cout << z << std::endl;
}
