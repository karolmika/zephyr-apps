# zephyr-apps
Zephyr playground project

# Setting up Environment on new computer

```
docker build -t zephyr-dev-setup:1.0 .
docker images
docker compose up -d
docker compose exec zephyr_apps bash
```

Rebuilding the same version with docker compose:

```
docker compose build
```

To validate the docker compose file (i.ex. check if the syntax is ok):

```
docker compose --file compose.yml config
```

# Possible problems

Fix to not able to save file edited in VS Code:

```
sudo chown -R user /workdir/
```