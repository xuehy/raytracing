#include <iostream>
#include <cmath>
template <typename T>
class Vec3
{
  T x;
  T y;
  T z;
public:
  Vec3(const T& a) : x(a), y(a), z(a) {}
  Vec3(const T &a, const T &b, const T &c) : x(a), y(b), z(c) {}
  Vec3<T> operator+(const Vec3<T>& v);
  Vec3<T> operator-(const Vec3<T>& v) const;
  T operator*(const Vec3<T>& v);
  void normalize();
  void show();
  T getX() {return x;}
  T getY() {return y;}
  T getZ() {return z;}
};

template <typename T>
void Vec3<T>::normalize()
{
  T a = sqrt(x*x+y*y+z*z);
  x /= a;
  y /= a;
  z /= a;
}

template <typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T>& v)
{
  return Vec3<T>(x + v.x, y + v.y, z + v.z);
}

template <typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T>& v) const
{
  return Vec3<T>(this->x - v.x, this->y - v.y, this->z - v.z);
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

