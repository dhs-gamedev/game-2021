/**
 * Main file for the 2021-22 game - for now, just does Hello World.
 */

#include <main/application.hpp>
#include <main/util.hpp>

int main(int argc, char ** argv) {

	util::log("Game has initialized!", util::Severity::NORMAL);
    
    Application app{};
    app.mainloop();

}
