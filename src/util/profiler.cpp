#include "profiler.hpp"

#include <main/application.hpp>

namespace prof {

Profiler::Profiler() {
    // Nothing yet
}

StrainLevel Profiler::calculate_strain(double secs) {

    static const double FRAME_LIMIT = 1.0 / (double) FRAMERATE;

    // Performance will be impacted if the frame rate is slowed by computation
    if (secs >= FRAME_LIMIT)        return StrainLevel::SEVERE;
    if (secs >= FRAME_LIMIT * 0.80) return StrainLevel::VERY_HEAVY;
    if (secs >= FRAME_LIMIT * 0.50) return StrainLevel::HEAVY;
    if (secs >= FRAME_LIMIT * 0.30) return StrainLevel::NORMAL;
    if (secs >= FRAME_LIMIT * 0.10) return StrainLevel::LIGHT;
    else                            return StrainLevel::VERY_LIGHT;

}

}
