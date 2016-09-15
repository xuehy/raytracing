template <typename T>
class Light
{
public:
  Light(const Vec3<T>& p, const Vec3<T>& clr): position_(p), color_(clr) {}
  Vec3<T> position() const {return position_;}
  Vec3<T> color() const {return color_;}
protected:
  Vec3<T> position_;
  Vec3<T> color_;
};

