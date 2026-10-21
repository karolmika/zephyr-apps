#include <vector>
#include <string>
#include "Movie.hpp"

class Movies {
private:
    std::vector <Movie> movies;
public:
    void add_movie(Movie m);
    Movie* get_movie(const std::string& name);
    void inc_watch_count(const std::string& name);
};