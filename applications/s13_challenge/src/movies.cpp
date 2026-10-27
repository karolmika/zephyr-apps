#include <iostream>
#include <string>
#include "Movies.hpp"

int Movies::add_movie(const std::string& name, int rate, int count) {
    for (Movie movie: movies) {
        if (name == movie.get_name()) {
            return -1;
        }
    }

    Movie m{name, rate, count};
    movies.push_back(m);
    return 0;
}

Movie* Movies::get_movie(const std::string& name) {
    for (auto it = this->movies.begin(); it != this->movies.end(); ++it)
    {
        if (name == it->get_name())
        {
            return &*it;
        }
    }
    return nullptr;
}

void Movies::inc_watch_count(const std::string& name) {
    Movie* movie = get_movie(name);

    if (movie != nullptr) {
        movie->inc_count();
    } else {
        std::cout << "ERROR: Movie with given name {" << name << "} is not on the list." << std::endl;
    }
}

std::string Movies::display(void) {
    std::string movies_names {};
    int s = this->movies.size();
    int cnt = 0;

    for (auto it = this->movies.begin(); it != this->movies.end(); ++it) {
        if (++cnt != s) {
            movies_names += ( it->get_name() + ", ");
        }
        else {
            movies_names += it->get_name();
        }

    }
    return movies_names;
}