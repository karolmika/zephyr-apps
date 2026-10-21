#include <iostream>
#include <string>
#include "Movies.hpp"

void Movies::add_movie(Movie m) {
    if(NULL != get_movie(m.get_name())) {
        std::cout << "ERROR: Movie already exists." << std::endl;
    }
    else {
        movies.push_back(m);
    }
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
        movie->set_count(movie->get_count() + 1);
    } else {
        std::cout << "ERROR: Movie with given name {" << name << "} is not on the list." << std::endl;
    }
}