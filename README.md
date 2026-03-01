# zephyr-apps
Zephyr playground project

# Setting up Environment on new computer

## Clone repository
git clone <zephyr_apps_repo>
cd <zephyr_apps_repo>

## Build docker
docker build -t zephyr-dev-setup:1.0 .
docker images
docker compose up -d
docker compose exec zephyr bash

## Initialize west
