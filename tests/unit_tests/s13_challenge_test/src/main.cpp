#include <zephyr/ztest.h>
#include <string>
#include "Movies.hpp"

/* Add new movie, read it back and check if the data are correct (movie sucesfully added)*/
ZTEST(s13_challenge_test, test_add_new_movie)
{
    const std::string movie_name{"Perfect Days"};
    constexpr int movie_rate = 7;
    constexpr int movie_watch_count = 1;

    Movie perfect_days{movie_name, movie_rate, movie_watch_count};
    Movies my_favourite_movies;
    my_favourite_movies.add_movie(perfect_days);
    Movie* stored_movie = my_favourite_movies.get_movie(movie_name);

    zassert_not_null(stored_movie, "Movie was not added");
    zassert_true(stored_movie->get_name() == movie_name, "Incorrect name");
    zassert_equal(stored_movie->get_rate(), movie_rate, "Incorrect rate");
    zassert_equal(stored_movie->get_count(), movie_watch_count, "Incorrect watch count");
}

/* Try to get movie that doesn't exsist. Null pointer should be returned. */
ZTEST(s13_challenge_test, test_get_not_exsisting_movie)
{
    Movies MyFavouritesMovies;
    Movie perfect_days{"Perfect Days", 7, 1};

    MyFavouritesMovies.add_movie(perfect_days);
    Movie* mv = MyFavouritesMovies.get_movie("perfect days");
    zassert_is_null(mv, "Movie shouldn't be found.");
}

ZTEST_SUITE(s13_challenge_test, NULL, NULL, NULL, NULL, NULL);