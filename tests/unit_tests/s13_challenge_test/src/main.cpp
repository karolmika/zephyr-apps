#include <zephyr/ztest.h>
#include <string>
#include "Movies.hpp"

/* Add new movie, read it back and check if the data are correct (movie sucesfully added)*/
ZTEST(s13_challenge_test, test_add_new_movie)
{
    const std::string movie_name{"Perfect Days"};
    constexpr int movie_rate = 7;
    constexpr int movie_watch_count = 1;

    Movies my_favourite_movies;
    int res = my_favourite_movies.add_movie(movie_name, movie_rate, movie_watch_count);
    Movie* stored_movie = my_favourite_movies.get_movie(movie_name);

    zassert_equal(res, 0, "Add movie return error!");
    zassert_not_null(stored_movie, "Movie was not added");
    zassert_true(stored_movie->get_name() == movie_name, "Incorrect name");
    zassert_equal(stored_movie->get_rate(), movie_rate, "Incorrect rate");
    zassert_equal(stored_movie->get_count(), movie_watch_count, "Incorrect watch count");
}

ZTEST(s13_challenge_test, test_add_exisiting_movie) {
    Movies MyFavouritesMovies;
    int res1 = MyFavouritesMovies.add_movie("Perfect Days", 7, 1);
    int res2 = MyFavouritesMovies.add_movie("Perfect Days", 7, 1);

    zassert_equal(res1, 0, "Add movie should be added.");
    zassert_equal(res2, -1, "Add movie should not be added.");
}

/* Try to get movie that doesn't exsist. Null pointer should be returned. */
ZTEST(s13_challenge_test, test_get_not_exsisting_movie)
{
    Movies MyFavouritesMovies;

    MyFavouritesMovies.add_movie("Perfect Days", 7, 1);
    Movie* mv = MyFavouritesMovies.get_movie("perfect days");
    zassert_is_null(mv, "Movie shouldn't be found.");
}

ZTEST(s13_challenge_test, test_set_movie_watch_cnt)
{
    Movie perfect_days{"Perfect Days", 7, 1};
    perfect_days.set_count(5);

    int result = perfect_days.get_count();
    zassert_equal(result, 5, "Watch count not incremented!");
}

ZTEST(s13_challenge_test, test_inc_movie_watch_cnt)
{
    Movie perfect_days{"Perfect Days", 7, 1};
    perfect_days.inc_count();

    int result = perfect_days.get_count();
    zassert_equal(result, 2, "Watch count not incremented!");
}

ZTEST(s13_challenge_test, test_display_all_movies)
{
    Movies MyFavouritesMovies;

    MyFavouritesMovies.add_movie("Perfect Days", 7, 1);
    MyFavouritesMovies.add_movie("Diuna", 8, 1);
    MyFavouritesMovies.add_movie("Spider Man", 9, 1);

    std::string display_movies = MyFavouritesMovies.display();
    zassert_equal(display_movies, "Perfect Days, Diuna, Spider Man");
}

ZTEST(s13_challenge_test, test_display_all_movies_selfcheck)
{
    Movies MyFavouritesMovies;

    MyFavouritesMovies.add_movie("Perfect Days", 7, 1);
    MyFavouritesMovies.add_movie("Diuna", 8, 1);
    MyFavouritesMovies.add_movie("Spider Man", 9, 1);

    std::string display_movies = MyFavouritesMovies.display();
    zassert_not_equal(display_movies, "Perfect Days, Diuna");
}

ZTEST_SUITE(s13_challenge_test, NULL, NULL, NULL, NULL, NULL);