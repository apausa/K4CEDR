/*
 * Copyright (c) 2020-2024 Key4hep-Project.
 *
 * This file is part of Key4hep.
 * See https://key4hep.github.io/key4hep-doc/ for further info.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DetectorUtils_h
#define DetectorUtils_h 1

#include <array>
#include <string>

#include "DD4hep/Detector.h"

namespace k4ced {

// structure for calculating the track length of given particles
struct CalorimeterDrawParams {
  double r_inner, delta_r, z_0, delta_z;
};

CalorimeterDrawParams getCalorimeterParameters(dd4hep::Detector& theDetector, std::string name, bool selfCall = false);

double calculateTrackLength(const CalorimeterDrawParams& barrel, const CalorimeterDrawParams& endcap, double x,
                            double y, double z, double px, double py, double pz, double rel_X0 = 0.5);

// get the outer extents of the tracker
std::array<double, 2> getTrackerExtent(dd4hep::Detector& theDetector);

// get the outer extents of the yoke
std::array<double, 2> getYokeExtent(dd4hep::Detector& theDetector);

} // namespace k4ced

#endif
