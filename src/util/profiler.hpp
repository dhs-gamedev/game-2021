/**
 * For profiling the game's performance, and possibly other things later.
 */

#pragma once

namespace prof {

/**
 * The amount of strain the game is under.
 */
enum StrainLevel {
    VERY_LIGHT,
    LIGHT,
    NORMAL,
    HEAVY,
    VERY_HEAVY,
    SEVERE,
};

class Profiler {

public:
    Profiler();

    /**
     * Get the strain level from the time taken in a frame.
     */
    StrainLevel calculate_strain(double seconds_in_frame);
    
};

}
