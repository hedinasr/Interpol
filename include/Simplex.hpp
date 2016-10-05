#ifndef SIMPLEX_H
#define SIMPLEX_H

#include "Point.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

/*! \class Simplex
 * \brief Simplex is the generalization of the triangle in N-dimension
 */
template <unsigned int N = 1> class Simplex {

private:
  std::vector<Point<N> > points;

public:
  Simplex() {}

  ~Simplex() {}

  //! compute factorial(n)
  int factorial(int n) { return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n; }

  //! return the matrix determinant
  static float determinant(float matrix[N][N], float size) {
    float s = 1, det = 0, m_minor[N][N];
    int i, j, m, n, c;
    if (size == 1) {
      return (matrix[0][0]);
    } else {
      det = 0;
      for (c = 0; c < size; c++) {
        m = 0;
        n = 0;
        for (i = 0; i < size; i++) {
          for (j = 0; j < size; j++) {
            m_minor[i][j] = 0;
            if (i != 0 && j != c) {
              m_minor[m][n] = matrix[i][j];
              if (n < (size - 2))
                n++;
              else {
                n = 0;
                m++;
              }
            }
          }
        }
        det = det + s * (matrix[0][c] * determinant(m_minor, size - 1));
        s = -1 * s;
      }
    }
    return (det);
  }

  //! push point in the simplex
  void pushPoint(const Point<N> &p) {
    // TODO check if the Simplex is ! full
    // std::cout << points.size() << std::endl;
    if (points.size() <= N)
      points.push_back(p);
    else // error
      std::cout << "Cannot insert point in the Simplex" << std::endl;
  }

  //! return the matrix volume
  float calculateVol() {
    float m[N][N];
    for (size_t i = 0; i < N; i++) {
      for (size_t j = 0; j < N; j++) {
        m[i][j] = points[j + 1][i] - points[0][i];
      }
    }
    float det = determinant(m, N);
    float res = det / (factorial(N));
    return std::abs(res);
  }

  //! print the simplex
  void to_str() {
    for (unsigned i = 0; i <= N; i++) {
      std::cout << "Point [" << i << "] : {" << points[i] << "} || ";
    }
  }

  //! read-write overriding of operator[]
  Point<N> operator[](unsigned int i) { return points[i]; }

  //! read-only overriding of operator[]
  const Point<N> operator[](unsigned int i) const { return points[i]; }

  friend bool operator==(const Simplex &s1, const Simplex &s2) {
    if (s1.getSize() != s2.getSize())
      return false;
    for (int i = 0; i < s1.getSize(); i++) {
      if (s1[i] != s2[i])
        return false;
    }
    return true;
  }

  friend bool operator!=(const Simplex &s1, const Simplex &s2) {
    return !(s1 == s2);
  }

  int getSize() const { return points.size(); }
};

#endif
