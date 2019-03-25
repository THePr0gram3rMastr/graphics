#include <iostream>

//Copyright (C) 2019 Cian Martin Bohan (@cianmarbo).
//3 - dimensional vector class that can add, sub and return the dot of 2 vectors

//warning: this program was witten in the late hours of the night

template<class T> class Vec3 {
private:
  T x, y, z;
  T dotProduct;
public:

  //default constructor if no arguments are provided
  Vec3() {
    x = 0;
    y = 0;
    z = 0;
  }

  //overloaded constructor for defining a Vector3

  Vec3(T xVal, T yVal, T zVal) {
    x = xVal;
    y = yVal;
    z = zVal;
  }

  //overloaded constructor for assigning the result of vec1*vec2

  Vec3(T dot) {
    dotProduct = dot;
  }

  //print vector

  void printVec() {
    std::cout << x << "\n";
    std::cout << y << "\n";
    std::cout << z << "\n";
  }

  //print dot product

  void printDot() {
    std::cout << dotProduct << "\n";
  }

  //vector addition

  Vec3 add(const Vec3& otherVec) const {

    return Vec3(x + otherVec.x, y + otherVec.y, z + otherVec.z);
  }

  //overloaded "+" operator

  Vec3 operator+(const Vec3& otherVec) const {

    return add(otherVec);
  }

  //vector subtraction

  Vec3 sub(const Vec3& otherVec) const {

    return Vec3(x - otherVec.x, y - otherVec.y, z - otherVec.z);
  }

  //overloaded "-" operator

  Vec3 operator-(const Vec3& otherVec) const {

    return sub(otherVec);
  }

  //vector dot product

  Vec3 dot(const Vec3& otherVec) const {

    return Vec3( (x * otherVec.x) + (y * otherVec.y) + (z* otherVec.z) );
  }

  //overloaded "*" operator

  Vec3 operator*(const Vec3& otherVec) const {

    return dot(otherVec);
  }

  //update player position on the x axis

  T updateXPos(T* pos) {

    *pos+=x;

    return *pos;
  }

  //update player position on the y axis

  T updateYPos(T* pos) {

    *pos+=y;

    return *pos;
  }

  //update player position on the z axis

  T updateZPos(T* pos) {

    *pos+=z;

    return *pos;
  }

};

//printUpdatedPos is a function template as positions may vary in type

template<class T>
void printUpdatedPos(T* x, T* y, T* z) {
  std::cout << "The new X position is: " << *x << std::endl;
  std::cout << "The new Y position is: " << *y << std::endl;
  std::cout << "The new Z position is: " << *z << std::endl;
}

int main(int argc, char** argv, char** envp) {

  float playerPos[3] = {
    6,
    9,
    7
  };

  std::cout << "The player is at " << playerPos[0] << ", " << playerPos[1] << ", " << playerPos[2] << std::endl;

  Vec3<float> vec1(3, 4, 5);

  vec1.printVec();

  //using type inference here as positions will not always be the same data type

  auto newXPos = vec1.updateXPos(&playerPos[0]);
  auto newYPos = vec1.updateYPos(&playerPos[1]);
  auto newZPos = vec1.updateZPos(&playerPos[2]);

  std::cout << "The player has moved!" << std::endl;

  printUpdatedPos<float>(&newXPos, &newYPos, &newZPos);

  Vec3<float> vec2(7, 4, 5);

  vec2.printVec();

  Vec3<float> add = vec1 + vec2;

  add.printVec();

  Vec3<float> sub = vec1 - vec2;

  sub.printVec();

  Vec3<float> dot = vec1*vec2;

  dot.printDot();

  return 0;
}
