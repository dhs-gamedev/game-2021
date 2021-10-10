/**
 * Main file for the 2021-22 game - for now, just does Hello World.
 */

#include <gl/window.hpp>
#include <main/util.hpp>

int main(int argc, char ** argv) {

	util::log("Game has initialized!", util::Severity::NORMAL);
    
    gl::Window wn{500, 500};
    while (wn.is_open()) {
        // TODO - rendering code goes here
        wn.clear();
        wn.render();
        wn.poll_events(); 
    }

}
