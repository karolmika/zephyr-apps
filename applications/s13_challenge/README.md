# Intro
This is a project for `Section 13` challenge from the Udemy C++ Course:
`https://www.udemy.com/course/beginning-c-plus-plus-programming/`

The course itself use standard Windows environment but I decided to use Zephyr as it is my main focus lately 
and it will be nice to experience with used of C++ for writing Zephyr OS, even if it is build only for native sim.

About suport C++ in Zephyr:
`https://docs.zephyrproject.org/latest/develop/languages/cpp/index.html`

# Build

I use common build directory for all other application in the workspace. The stucture looks like this:
`build_common/<app_name>/<board>/` so for example to build `s13_challenge` application for `native_sim` board:

```
west build -p always applications/s13_challenge/ --board native_sim --build-dir build_common/s13_challenge/native_sim/
```
# The Challenge

For this challenge you are to develop the foundation for a program for a movie fanatics to keep track of what movies they have watched and how many times they watched each movies. The program must support two classes:
- Class `Movie` for the movie models (movie name, movie rating, how many times movie been watched )
- Class `Movies` to models a collection of movie objects

Obviously, `Movies` need to know about `Movie` since it's a collection of movie object. However, our main driver should only interact with the Movie class. For example, a simpl main should be ablt to:
- create a Movie object
- ask the Movies object to add a movie by providing the movie name, rating and watched count
- ask the Movie object to increment the watched count by 1 for a movie given its name
- ask the Movies object to display all of its movies

Aditionally an error handling, as follows:
- if we try to add a movie whose name is already in the movie collection 
- if we try to increment the watch count for a movie whose name is int he movies collection we should display an error for a user

Some tips:
- Use seperate files for each class.
- Don't create a menu-driven system in the first working version (just focus on getting program working and improve it later)