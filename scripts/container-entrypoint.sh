#!/bin/sh
set -eu

workspace_dir="${WEST_TOPDIR:-/workdir}"
zephyr_revision="${ZEPHYR_REVISION:-v4.2.0}"
manifest_url="https://github.com/zephyrproject-rtos/zephyr"

cd "$workspace_dir"

if [ -f .west/config ]; then
    if [ ! -f zephyr/west.yml ]; then
        if [ -e zephyr ]; then
            echo "Found .west/config but zephyr/west.yml is missing and zephyr/ already exists." >&2
            exit 1
        fi
        git clone --depth 1 --branch "$zephyr_revision" "$manifest_url" zephyr
    fi
else
    if [ -e .west ] || [ -e zephyr ]; then
        echo "Cannot initialize Zephyr: .west or zephyr already exists without a valid workspace." >&2
        exit 1
    fi
    west init -m "$manifest_url" --mr "$zephyr_revision" "$workspace_dir"
fi

west update
west zephyr-export
exec "$@"