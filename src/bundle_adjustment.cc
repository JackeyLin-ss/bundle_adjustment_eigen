#include "eigen_type.h"
#include "vertex.h"
#include <Eigen/Core>
#include <iostream>

class PoseVertex : public Vertex<6, Vector6d> {
public:
  PoseVertex() {}

  void SetPose(const Eigen::Matrix4d &tcw) {
    Eigen::Matrix3d _R = tcw.block(0, 0, 3, 3);
    Eigen::Vector3d t = tcw.block(0, 3, 3, 1);

    double d = 0.5 * (_R(0, 0) + _R(1, 1) + _R(2, 2) - 1);
    Vector3d omega;
    Vector3d upsilon;

    Vector3d dR = deltaR(_R);
    Eigen::Matrix3d V_inv;

    if (d > 0.99999) {

      omega = 0.5 * dR;
      Eigen::Matrix3d Omega = skew(omega);
      V_inv = Eigen::Matrix3d::Identity() - 0.5 * Omega +
              (1. / 12.) * (Omega * Omega);
    } else {
      double theta = acos(d);
      omega = theta / (2 * sqrt(1 - d * d)) * dR;
      Eigen::Matrix3d Omega = skew(omega);
      V_inv = (Eigen::Matrix3d::Identity() - 0.5 * Omega +
               (1 - theta / (2 * tan(theta / 2))) / (theta * theta) *
                   (Omega * Omega));
    }

    Vector6d res;

    upsilon = V_inv * t;
    for (int i = 0; i < 3; i++) {
      res[i] = omega[i];
    }
    for (int i = 0; i < 3; i++) {
      res[i + 3] = upsilon[i];
    }

    SetEstimation(res);
  }
};

class PointVertex : public Vertex<3, Vector3d> {
public:
  PointVertex() {}
};

int main(int argc, char **argv) {

  // prepare fake data ;

  return 1;
}
