# Dockerfile
FROM ghcr.io/zephyrproject-rtos/zephyr-build:v0.28.7

# Temporarily become root to install packages
USER root

# Install extra tools you need
RUN apt-get update && apt-get install -y --no-install-recommends \
    doxygen \
    graphviz \
    plantuml \
    clang-format \
    clang-tidy \
    gdb-multiarch \
    && rm -rf /var/lib/apt/lists/*

# (Optional) Python tools you want globally available in the container
RUN pip3 install --no-cache-dir \
    west \
    gcovr \
    pytest

# Quality-of-life: make sure locale etc. if you need it (optional)
ENV LANG=C.UTF-8

# Go back to the original non-root user (often "user")
USER user
