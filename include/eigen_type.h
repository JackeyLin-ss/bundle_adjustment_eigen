#pragma once
#include <Eigen/Core>
typedef Eigen::Matrix<double, 6, 1> Vector6d;
typedef Eigen::Matrix<double, 3, 1> Vector3d;

Vector3d deltaR(const Eigen::Matrix3d &R) {
  Vector3d v;
  v(0) = R(2, 1) - R(1, 2);
  v(1) = R(0, 2) - R(2, 0);
  v(2) = R(1, 0) - R(0, 1);
  return v;
}

Eigen::Matrix3d skew(const Vector3d &v) {
  Eigen::Matrix3d m;
  m.fill(0.);
  m(0, 1) = -v(2);
  m(0, 2) = v(1);
  m(1, 2) = -v(0);
  m(1, 0) = v(2);
  m(2, 0) = -v(1);
  m(2, 1) = v(0);
  return m;
}
