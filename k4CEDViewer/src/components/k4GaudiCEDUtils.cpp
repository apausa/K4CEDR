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
#include "k4GaudiCEDUtils.h"
#define endmsg std::endl

namespace k4ced {

std::ostream& info() {
  if (k4ced::GlobalLog::instance().level() <= LogLevel::Info) {
    std::cout << k4ced::GlobalLog::instance().name() << "  INFO ";
    return std::cout;
  }
  return (null_stream);
}
std::ostream& debug() {
  if (k4ced::GlobalLog::instance().level() <= LogLevel::Debug) {
    std::cout << k4ced::GlobalLog::instance().name() << "  DEBUG ";
    return std::cout;
  }
  return (null_stream);
}
std::ostream& verbose() {
  if (k4ced::GlobalLog::instance().level() <= LogLevel::Verbose) {
    std::cout << k4ced::GlobalLog::instance().name() << "  VERBOSE ";
    return std::cout;
  }
  return (null_stream);
}
std::ostream& error() {
  if (k4ced::GlobalLog::instance().level() <= LogLevel::Error) {
    std::cout << k4ced::GlobalLog::instance().name() << "  ERROR ";
    return std::cout;
  }
  return (null_stream);
}
std::ostream& warning() {
  if (k4ced::GlobalLog::instance().level() <= LogLevel::Warning) {
    std::cout << k4ced::GlobalLog::instance().name() << "  WARNING ";
    return std::cout;
  }
  return (null_stream);
}

edm4hep::TrackState getTrackStateAt(const edm4hep::Track& trk, int location) {

  edm4hep::TrackState ts0;

  for (auto ts : trk.getTrackStates()) {

    if (ts.location == location)
      return ts;
  }
  return ts0;
}

} // namespace k4ced
