#ifndef POINT_H
#define POINT_H

#include <array>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

#define STATIC_ASSERT(e) static_assert(e, "!(" #e ")")

/*! \class Point
 * \brief This class stores all data for point representation in any dimension
 */
template <std::size_t N = 2> class Point {

private:
  float coord[N];
  float valeur;
  std::size_t size;

public:
  Point() : coord(), valeur(15), size(N) {}

  ~Point() {}

  Point(const float &x, const float &y, const float &valeur)
      : valeur(valeur), size(N) {
    STATIC_ASSERT(N == 2);
    coord[0] = x;
    coord[1] = y;
  }

  Point(const float &x, const float &y, const float &z, const float &valeur)
      : valeur(valeur), size(N) {
    STATIC_ASSERT(N == 3);
    coord[0] = x;
    coord[1] = y;
    coord[2] = z;
  }

  Point(std::vector<float> points, const float &valeur)
      : valeur(valeur), size(N) {
    for (size_t i = 0; i < points.size(); i++) {
      coord[i] = points[i];
    }
  }

  //! This constructor initialize and set all coordinate value to x
  Point(const float &x, const float &valeur) : valeur(valeur), size(N) {
    for (size_t i = 0; i < N; i++) {
      coord[i] = x;
    }
  }

  //! read-only accessor
  float at(unsigned int i) const { return coord[i]; }

  //! read-write overriding of operator[]
  float &operator[](unsigned int i) { return coord[i]; }

  //! read-only overriding of operator[]
  const float &operator[](unsigned int i) const { return coord[i]; }

  friend bool operator==(const Point &p1, const Point &p2) {
    if (p1.size != p2.size)
      return false;
    for (unsigned i = 0; i < p1.size; i++) {
      if (p1.coord[i] != p2.coord[i] || p1.valeur != p2.valeur)
        return false;
    }
    return true;
  }

  friend bool operator!=(const Point &p1, const Point &p2) {
    return !(p1 == p2);
  }

  //! to string conversion of point
  std::string to_str() {
    if (N > 0) {
      std::stringstream s;
      s << "{ X0: " << coord[0];
      for (std::size_t i = 1; i < N; i++) {
        s << " | X" << i << ": " << coord[i];
      }
      s << " }";
      s << " || val = " << valeur << std::endl;
      return s.str();
    }
    return "{}";
  }

  friend Point operator+(Point const &p1, Point const &p2) {
    Point result(p1);
    result += p2;
    return result;
  }

  friend Point operator-(Point const &p1, Point const &p2) {
    Point result(p1);
    result -= p2;
    return result;
  }

  //! print in the standard output
  friend std::ostream &operator<<(std::ostream &stream, const Point &point) {
    stream << "(";
    for (unsigned i = 0; i < N - 1; i++)
      stream << point[i] << ", ";
    stream << point[N - 1] << ")";
    return stream;
  }

  //! return the distance between p1 and p2
  static float distance(const Point<N> &p1, const Point<N> &p2) {
    float dist = 0;
    for (unsigned i = 0; i < N; i++)
      dist += pow((p2[i] - p1[i]), 2);
    return sqrt(dist);
  }

  //! return the value of the point
  float getValeur() { return valeur; }

  //! return the absolute highest coordinate of the point
  float coordMax() {
    float max = 0;
    for (size_t i = 0; i < N; i++) {
      if (std::abs(coord[i]) > max)
        max = std::abs(coord[i]);
    }
    return max;
  }
};

#endif // POINT_H
