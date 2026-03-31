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
    picocom \
    libusb-1.0-0 \
    && rm -rf /var/lib/apt/lists/*

# (Optional) Python tools you want globally available in the container
RUN pip3 install --no-cache-dir \
    west \
    gcovr \
    pytest

# Download and install nrfutil binary
RUN wget -O /usr/local/bin/nrfutil "https://files.nordicsemi.com/ui/api/v1/download?repoKey=swtools&path=external/nrfutil/executables/x86_64-unknown-linux-gnu/nrfutil&isNativeBrowsing=false" && \
    chmod +x /usr/local/bin/nrfutil

# Install nrfutil device tools
RUN nrfutil install device

# Install SEGGER J-Link
COPY JLink_Linux_V924a_x86_64 /opt/SEGGER/JLink_Linux_V924a_x86_64
RUN ln -sfn /opt/SEGGER/JLink_Linux_V924a_x86_64 /opt/SEGGER/JLink
ENV PATH="/opt/SEGGER/JLink_Linux_V924a_x86_64:${PATH}"
ENV LD_LIBRARY_PATH="/opt/SEGGER/JLink:${LD_LIBRARY_PATH}"

# Quality-of-life: make sure locale etc. if you need it (optional)
ENV LANG=C.UTF-8
ENV PROTOCOL_BUFFERS_PYTHON_IMPLEMENTATION=python

# Go back to the original non-root user (often "user")
USER user
