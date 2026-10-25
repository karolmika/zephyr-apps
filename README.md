# zephyr-apps
Zephyr playground project

# Setting up Environment on new computer

```
docker build -t zephyr-dev-setup:1.1 .
docker images
docker compose up -d
docker compose exec zephyr_apps bash
```

SEGGER J-Link is optional for building the image. To use it in the container,
extract the Linux J-Link package to `~/downloads/JLink_Linux_V924a_x86_64` on
the host; Compose mounts that directory's parent at `/downloads`.

Rebuilding the same version with docker compose:

```
docker compose build
```

To validate the docker compose file (i.ex. check if the syntax is ok):

```
docker compose --file compose.yml config
```

To remove old image run:

```
docker image rm zephyr-dev-setup:1.0
```

# Possible problems

Fix to not able to save file edited in VS Code. 


```
sudo chown -R user /workdir/
```

Error "detected dubious ownership":

```
git config --global --add safe.directory /workdir
```

Check if the NRF board is connected and can be discovered:

```
nrfutil device list
```