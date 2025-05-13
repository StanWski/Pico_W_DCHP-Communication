# AP_DHCP

A minimal Wi-Fi Access Point and DHCP server for the Raspberry Pi Pico W, featuring a simple web interface for input and result display.

## Overview

**AP_DHCP** turns your Raspberry Pi Pico W into a standalone Wi-Fi access point with a built-in DHCP server. It also runs a lightweight HTTP server that serves a plain text API for user input and displays computed results. This project is ideal for embedded applications, IoT demonstrations, or educational purposes where a self-contained wireless network and web interface are required.

## Features

- **Wi-Fi Access Point**: Pico W acts as a wireless AP with configurable SSID and password.
- **DHCP Server**: Assigns IP addresses to clients connecting to the AP.
- **Web Server**: Serves a plain text API for user input and result retrieval.
- **LED Control**: Example endpoint to toggle the onboard LED via the web interface.
- **C++ Implementation**: Uses lwIP, Pico SDK, and CYW43 driver for networking.

## Directory Structure

```
AP_DHCP/
├── CMakeLists.txt
├── main.cpp
├── dhcpserver/
│   ├── dhcpserver.cpp
│   └── dhcpserver.h
├── serverlogic/
│   ├── serverlogic.cpp
│   └── serverlogic.h
└── README.md
```

## Requirements

- Raspberry Pi Pico W
- [Pico SDK](https://github.com/raspberrypi/pico-sdk)
- CMake 3.13+
- GCC toolchain for ARM (e.g., `arm-none-eabi-gcc`)
- lwIP and CYW43 driver (provided by Pico SDK)

## Building

1. **Clone the repository** and initialize submodules if needed.
2. **Set up the Pico SDK**:
   ```sh
   git clone https://github.com/raspberrypi/pico-sdk.git
   cd pico-sdk
   git submodule update --init
   ```
3. **Configure and build the project**:
   ```sh
   cd /path/to/AP_DHCP
   mkdir build
   cd build
   cmake ..
   make
   ```
   The output will be a UF2 file (e.g., `AP_DHCP.uf2`).

## Flashing

1. Hold the BOOTSEL button on your Pico W and connect it via USB.
2. Copy the generated `.uf2` file to the mounted drive.

## Usage

1. After flashing, the Pico W will start as a Wi-Fi access point (default SSID: `picow_test`, password: `9998888999`).
2. Connect your device to this Wi-Fi network.
3. Use a web browser or HTTP client to access [http://192.168.4.1/](http://192.168.4.1/).
4. To compute a result, send a GET request to the root endpoint with `input1` and `input2` as query parameters, e.g.:
   ```
   http://192.168.4.1/?input1=5&input2=10
   ```
   The server will respond with the result as plain text.
5. The `/ledtest` endpoint allows toggling the onboard LED and still serves a minimal HTML page.

## Customization

- **SSID and Password**: Change the `ap_name` and `password` variables in `main.cpp`.
- **DHCP Range**: Adjust `DHCPS_BASE_IP` and `DHCPS_MAX_IP` in `dhcpserver.h`.
- **Web Logic**: Modify `serverlogic/serverlogic.cpp` and the plain text API in `main.cpp` as needed.

## License

This project is licensed under the MIT License. See the source files for details.

## Credits

- Based on the MicroPython project's DHCP server implementation.
- Uses Raspberry Pi Pico SDK and CYW43 driver.

## Troubleshooting

- Ensure your Pico W is running the latest firmware.
- Check your firewall or network settings if you cannot connect to the AP.
- Use a serial terminal to view debug output if needed.

---
