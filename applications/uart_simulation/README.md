# App purpose

The goal for this Zephyr application is a sample console over UART connection using NRF54 board and native sim target. The console can support some sample command for example to read the version or some help command just to confirm that the connection is working. 

Main goal is to prepare native SIM target for this application that will work with the simulated UART on the Linux virtual terminal (/dev/pts/).

## Building the app

Below is a build command for `native_sim` target:

```
west build -p always applications/uart_simulation/ --board native_sim --build-dir build_uart_sim
```

Build command for `nrf5340dk/nrf5340/cpuapp` target:

```
west build -p always applications/uart_simulation/ --board nrf5340dk/nrf5340/cpuapp --build-dir build_uart_sim
```

## Running the app

To run `native_sim` target application run exe file:

```
./build_uart_sim/zephyr/zephyr.exe
```

# Testing nativ sim target

To test the native sim communication over PTY UART, there is a Python script prepare which run the same command that are normally typed into the consol by the user.

# Supported commands

Below is a list of supported commands:

## version

Setting the version:

```
version --set 1.2.3
```

Reading the version:

```
version --get
1.2.3
```
