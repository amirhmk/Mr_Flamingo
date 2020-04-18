#ifndef REFRACT_H
#define REFRACT_H
#include <Eigen/Core>
// Refract an incoming ray into an out going ray with coefficient
//
// Inputs:
//   in  incoming _unit_ ray direction
//   n  surface _unit_ normal about which to reflect
//   c1 coefficinet of first material
//   c2 coefficient of second material
// Returns outward _unit_ ray direction
Eigen::Vector3d refract(const Eigen::Vector3d &in, const Eigen::Vector3d &n, float c1, float c2);
#endif
