/**
 * Main file for the 2021-22 game.
 */

#include <main/application.hpp>
#include <main/util.hpp>

int main(int argc, char ** argv) {

	util::log("Initializing game ...", util::Severity::NORMAL);
    
    Application app{};
	util::log("Game has initialized!", util::Severity::NORMAL);
    app.mainloop();

}
