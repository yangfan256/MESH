/* Copyright (C) 2016-2018, Stanford University
 * This file is part of MESH
 * Written by Kaifeng Chen (kfchen@stanford.edu)
 *
 * MESH is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * MESH is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _FMM_H
#define _FMM_H
#include <armadillo>
#include "Common.h"
#include "Rcwa.h"

namespace FMM{
  using namespace arma;
  using RCWA::RCWAcMatrix;
  using RCWA::RCWArMatrix;
  using RCWA::RCWArVector;
  using RCWA::jinc;
  using RCWA::meshGrid;

  /*==============================================*/
  // helper function to change a random dielectric to a tensor
  // @args:
  // epsilon: field
  // type: the type of the dielectric
  /*==============================================*/
  EpsilonVal toTensor(const EpsilonVal epsilon, const EPSTYPE type);

  /*==============================================*/
  // This function computes the Fourier transform for grating geometry
  // @args:
  // eps_xx: the Fourier transform for eps_xx
  // eps_xy: the Fourier transform for eps_xy
  // eps_zx: the Fourier transform for eps_yx
  // eps_yy: the Fourier transform for eps_yy
  // eps_zz: the Fourier transform for eps_zz
  // im_eps_xx: the Fourier transform for imaginary part
  // im_eps_xy: the Fourier transform for imaginary part
  // im_eps_yx: the Fourier transform for imaginary part
  // im_eps_yy: the Fourier transform for imaginary part
  // im_eps_zz: the Fourier transform for imaginary part
  // epsilonBGTensor: the epsilon of bacground (transformed to tensor already)
  // Gx_mat: the Gx matrix
  // Gy_mat: the Gy matrix
  // center: the center of the grating
  // width: the width of the grating
  // area: the area of one periodicity
  // hasTensor: whether this layer contains tensor
  /*==============================================*/
  void transformGrating(
    RCWAcMatrix& eps_xx,
    RCWAcMatrix& eps_xy,
    RCWAcMatrix& eps_yx,
    RCWAcMatrix& eps_yy,
    RCWAcMatrix& eps_zz,
    RCWAcMatrix& im_eps_xx,
    RCWAcMatrix& im_eps_xy,
    RCWAcMatrix& im_eps_yx,
    RCWAcMatrix& im_eps_yy,
    RCWAcMatrix& im_eps_zz,
    const EpsilonVal& epsilonBGTensor,
    const EpsilonVal& epsilon,
    const EPSTYPE epsilonType,
    const RCWArMatrix& Gx_Mat,
    const double center,
    const double width,
    const double area,
    const bool hasTensor
  );

  /*==============================================*/
  // This function computes the Fourier transform for rectangle geometry
  // @args:
  // eps_xx: the Fourier transform for eps_xx
  // eps_xy: the Fourier transform for eps_xy
  // eps_zx: the Fourier transform for eps_yx
  // eps_yy: the Fourier transform for eps_yy
  // eps_zz: the Fourier transform for eps_zz
  // im_eps_xx: the Fourier transform for imaginary part
  // im_eps_xy: the Fourier transform for imaginary part
  // im_eps_yx: the Fourier transform for imaginary part
  // im_eps_yy: the Fourier transform for imaginary part
  // im_eps_zz: the Fourier transform for imaginary part
  // epsilonBGTensor: the epsilon of bacground (transformed to tensor already)
  // Gx_mat: the Gx matrix
  // Gy_mat: the Gy matrix
  // centers: the centers of the rectangle
  // widths: the widths of the rectangle
  // area: the area of one periodicity
  // hasTensor: whether this layer contains tensor
  /*==============================================*/
  void transformRectangle(
    RCWAcMatrix& eps_xx,
    RCWAcMatrix& eps_xy,
    RCWAcMatrix& eps_yx,
    RCWAcMatrix& eps_yy,
    RCWAcMatrix& eps_zz,
    RCWAcMatrix& im_eps_xx,
    RCWAcMatrix& im_eps_xy,
    RCWAcMatrix& im_eps_yx,
    RCWAcMatrix& im_eps_yy,
    RCWAcMatrix& im_eps_zz,
    const EpsilonVal& epsBGTensor,
    const EpsilonVal& epsilon,
    const EPSTYPE epsilonType,
    const RCWArMatrix& Gx_Mat,
    const RCWArMatrix& Gy_Mat,
    const double centers[2],
    const double angle,
    const double widths[2],
    const double area,
    const bool hasTensor
  );

  /*==============================================*/
  // This function computes the Fourier transform for circle geometry
  // @args:
  // eps_xx: the Fourier transform for eps_xx
  // eps_xy: the Fourier transform for eps_xy
  // eps_zx: the Fourier transform for eps_yx
  // eps_yy: the Fourier transform for eps_yy
  // eps_zz: the Fourier transform for eps_zz
  // im_eps_xx: the Fourier transform for imaginary part
  // im_eps_xy: the Fourier transform for imaginary part
  // im_eps_yx: the Fourier transform for imaginary part
  // im_eps_yy: the Fourier transform for imaginary part
  // im_eps_zz: the Fourier transform for imaginary part
  // epsilonBGTensor: the epsilon of bacground (transformed to tensor already)
  // Gx_mat: the Gx matrix
  // Gy_mat: the Gy matrix
  // centers: the centers of the circle
  // radius: the radius of the circle
  // area: the area of one periodicity
  // hasTensor: whether this layer contains tensor
  /*==============================================*/
  void transformCircle(
    RCWAcMatrix& eps_xx,
    RCWAcMatrix& eps_xy,
    RCWAcMatrix& eps_yx,
    RCWAcMatrix& eps_yy,
    RCWAcMatrix& eps_zz,
    RCWAcMatrix& im_eps_xx,
    RCWAcMatrix& im_eps_xy,
    RCWAcMatrix& im_eps_yx,
    RCWAcMatrix& im_eps_yy,
    RCWAcMatrix& im_eps_zz,
    const EpsilonVal& epsBGTensor,
    const EpsilonVal& epsilon,
    const EPSTYPE epsilonType,
    const RCWArMatrix& Gx_Mat,
    const RCWArMatrix& Gy_Mat,
    const double centers[2],
    const double radius,
    const double area,
    const bool hasTensor
  );

  /*==============================================*/
  // This function computes the Fourier transform for ellipse geometry
  // @args:
  // eps_xx: the Fourier transform for eps_xx
  // eps_xy: the Fourier transform for eps_xy
  // eps_zx: the Fourier transform for eps_yx
  // eps_yy: the Fourier transform for eps_yy
  // eps_zz: the Fourier transform for eps_zz
  // im_eps_xx: the Fourier transform for imaginary part
  // im_eps_xy: the Fourier transform for imaginary part
  // im_eps_yx: the Fourier transform for imaginary part
  // im_eps_yy: the Fourier transform for imaginary part
  // im_eps_zz: the Fourier transform for imaginary part
  // epsilonBGTensor: the epsilon of bacground (transformed to tensor already)
  // Gx_mat: the Gx matrix
  // Gy_mat: the Gy matrix
  // area: the area of one periodicity
  // angle: the rotated angle of the ellipse
  // halfwidths: the halfwidths of the ellipse
  // period: the periodicity
  // hasTensor: whether this layer contains tensor
  /*==============================================*/
  void transformEllipse(
   RCWAcMatrix& eps_xx,
   RCWAcMatrix& eps_xy,
   RCWAcMatrix& eps_yx,
   RCWAcMatrix& eps_yy,
   RCWAcMatrix& eps_zz,
   RCWAcMatrix& im_eps_xx,
   RCWAcMatrix& im_eps_xy,
   RCWAcMatrix& im_eps_yx,
   RCWAcMatrix& im_eps_yy,
   RCWAcMatrix& im_eps_zz,
   const EpsilonVal& epsBGTensor,
   const EpsilonVal& epsilon,
   const EPSTYPE epsilonType,
   const RCWArMatrix& Gx_Mat,
   const RCWArMatrix& Gy_Mat,
   const double centers[2],
   const double angle,
   const double halfwidths[2],
   const double area,
   const bool hasTensor
 );
 /*==============================================*/
 // This function computes the Fourier transform for polygon geometry
 // @args:
 // eps_xx: the Fourier transform for eps_xx
 // eps_xy: the Fourier transform for eps_xy
 // eps_zx: the Fourier transform for eps_yx
 // eps_yy: the Fourier transform for eps_yy
 // eps_zz: the Fourier transform for eps_zz
 // im_eps_xx: the Fourier transform for imaginary part
 // im_eps_xy: the Fourier transform for imaginary part
 // im_eps_yx: the Fourier transform for imaginary part
 // im_eps_yy: the Fourier transform for imaginary part
 // im_eps_zz: the Fourier transform for imaginary part
 // epsilonBGTensor: the epsilon of bacground (transformed to tensor already)
 // Gx_mat: the Gx matrix
 // Gy_mat: the Gy matrix
 // centers: the centers of the polygon
 // edgeList: the edges of the polygon
 // area: the area of one periodicity
 // hasTensor: whether this layer contains tensor
 /*==============================================*/
 void transformPolygon(
  RCWAcMatrix& eps_xx,
  RCWAcMatrix& eps_xy,
  RCWAcMatrix& eps_yx,
  RCWAcMatrix& eps_yy,
  RCWAcMatrix& eps_zz,
  RCWAcMatrix& im_eps_xx,
  RCWAcMatrix& im_eps_xy,
  RCWAcMatrix& im_eps_yx,
  RCWAcMatrix& im_eps_yy,
  RCWAcMatrix& im_eps_zz,
  const EpsilonVal& epsBGTensor,
  const EpsilonVal& epsilon,
  const EPSTYPE epsilonType,
  const RCWArMatrix& Gx_Mat,
  const RCWArMatrix& Gy_Mat,
  const double centers[2],
  const double angle,
  const EdgeList& edgeList,
  const double area,
  const bool hasTensor
);
}

#endif