#include <iostream>
#include <string>
#include "Movies.hpp"

int main(void) {
    Movies MyFavouritesMovies;
    MyFavouritesMovies.add_movie(PerfectDays);

    // 3. Add movie (including error handling if movie already added)
    MyFavouritesMovies.add_movie(PerfectDays);

    // 4. Change watch count
    MyFavouritesMovies.inc_watch_count("Perfect days");
    std::cout << PerfectDays.get_count() << std::endl;

    // TODO: fix the inc watch count (should return 2 instead of 1)
    // TODO: Add unit tests using twister
    // TODO: Switch to TTD for next implementations

    exit(0);
    return(0);
}