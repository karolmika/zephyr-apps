#include <vector>
#include <string>
#include "Movie.hpp"

class Movies {
private:
    std::vector <Movie> movies;
public:
    /**
     * @brief It will search the movies vector to see if a movie already exists,
     *        if it does then return fals. Otherwise, create a movie object from
     *        provided information
     * @param name Name of the movie
     * @param rate Initial rate of the movie
     * @param count Initial watch counter for the movie
     * 
     * @return -1 if movie already exists, otherwise 0 (movie added)
     */
    int add_movie(const std::string& name, int rate, int count);

    /**
     * @brief Read movie from the vector list baded on the provided movie name.
     * @param name Name of the movie 
     * @return Pointer to Movie object in the vector list or NULL ptr if movie
     *         is not exisiting. 
     */
    Movie* get_movie(const std::string& name);

    /**
     * @brief Increment watch counter for the provided movie name. Function first
     *        check if movie exists.
     * @param name Name of the movie
     */
    void inc_watch_count(const std::string& name);

    /**
     * @brief Loops through all movie objects an reads the name to collect them as
     *        one single string. Each name is seperated by a colon (,) i.ex.
     *        Movie1, Movie2, Movie3 ...  
     */
    std::string display();
    
};