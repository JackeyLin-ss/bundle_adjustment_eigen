#pragma once

#include "eigen_type.h"
#include <Eigen/Dense>

template <int D, typename T> class Vertex {
public:
  typedef T VertexType;
  Vertex() { dimention_ = D; }

  void SetEstimation(const VertexType &et) { estimate_ = et; }
  int dimention() { return dimention_; }

  void Plus(const VertexType &update) { estimate_ += update; }

  VertexType Estimation() { return estimate_; }

  void SetId(int id) { id_ = id; }

private:
  int id_;
  int dimention_;
  VertexType estimate_;

public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};
