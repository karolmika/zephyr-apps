# App purpose

The goal for this Zephyr application is a sample console over UART connection using NRF54 board and native sim target. The console can support some sample command for example to read the version or some help command just to confirm that the connection is working. 

Main goal is to prepare native SIM target for this application that will work with the simulated UART on the Linux virtual terminal (/dev/pts/).

## Building the app

### Native Sim Target

Below is a build command for `native_sim` target:

```
west build -p always applications/uart_simulation/ --board native_sim --build-dir build_uart_sim
```

Build command for `native_sim` with stdin/stdout UART connected at build time via snippet:

```
west build -S native-sim-stdinout -p always applications/uart_simulation/ --board native_sim --build-dir build_uart_sim
```

Build command for `native_sim` with dedicated PTY UART via snippet:

```
west build -S native-sim-pty -p always applications/uart_simulation/ --board native_sim --build-dir build_uart_sim
```

### NRF5340DK Target

Build command for `nrf5340dk/nrf5340/cpuapp` target:

```
west build -S cdc-acm-console -p always applications/uart_simulation/ --board nrf5340dk/nrf5340/cpuapp --build-dir build_uart_sim
```

## Running the app

To run `native_sim` target application run exe file:

```
./build_uart_sim/zephyr/zephyr.exe
```

When built with `-S native-sim-stdinout`, stdin/stdout UART is already enabled,
so no extra runtime argument (`-uart_stdinout`) is needed.

```
./build_uart_sim/zephyr/zephyr.exe
```

When built with `-S native-sim-pty`, UART is attached to a PTY device (`/dev/pts/*`).
Run the same executable and connect to the printed PTY with your terminal tool.

Example:

```
./build_uart_sim/zephyr/zephyr.exe
# output includes: uart connected to pseudotty: /dev/pts/3
picocom /dev/pts/3
```

Important notes:

- Use the exact PTY path printed by `zephyr.exe` (for example `/dev/pts/3`).
	Do not assume `/dev/pts/1`.
- Run `zephyr.exe` and your terminal tool in the same environment/namespace
	(same dev container/session), otherwise `/dev/pts/*` can refer to different
	devices.
- Keep `zephyr.exe` running while connected to the PTY. If it exits, the PTY
	is closed.

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
