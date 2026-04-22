# Intro
This is a project for running examples and write challenge programs for Udemy C++ Course:
`https://www.udemy.com/course/beginning-c-plus-plus-programming/`

The course itself use standard Windows environment but I decided to use Zephyr as it is my main focus lately 
and it will be nice to experience with used of C++ for writing Zephyr OS, even if it is build only for native sim.

About suport C++ in Zephyr:
`https://docs.zephyrproject.org/latest/develop/languages/cpp/index.html`

# Build

I use common build directory for all other application in the workspace. The stucture looks like this:
`build_common/<app_name>/<board>/` so for example to build `cpp_course` application for `native_sim` board:

```
west build -p always applications/cpp_course/ --board native_sim --build-dir build_common/cpp_course/native_sim/
```