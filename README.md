# ESP8266 PlayStation 5 Web Exploit Server

Lightweight web server for ESP8266 boards that hosts the [PlayStation 5 UMTX2 Jailbreak](https://github.com/idlesauce/umtx2) for firmware versions 1.00–5.50, with minor modifications to enable caching.

It comes with [etaHEN v2.1b](https://github.com/etaHEN/etaHEN/releases/tag/2.1B) and [byepervisor](https://github.com/PS5Dev/Byepervisor) payloads preloaded. The exploit is served at `http://10.1.1.1/index.html`, and you can use the [ESP Host FPKG](https://www.mediafire.com/file/w4e6hiuwfoj8dnb/esphost.zip) to cache it for offline use.

The use of PROGMEM to store exploit files and `elfldr.elf` payload—preserving SPIFFS space for other payloads—was heavily inspired by [stooged's PS5-Server project](https://github.com/stooged/PS5-Server) and [0x1iii1ii's fork](https://github.com/0x1iii1ii/PS5-Server/).

## Quick Setup Guide

### Access Point Details

- SSID: `PS5_WEB_AP`
- Password: `password`

### Flashing Ready-To-Use `.bin` File

A ready-to-use `.bin` file can be downloaded from the [releases page](https://github.com/vladimir-cucu/esp-ps5-exploit-server/releases). One way to flash the `.bin` file to your ESP8266 board is by using the [NodeMCU PyFlasher](https://github.com/marcelstoer/nodemcu-pyflasher).

## Configuration and Customization

### Changing SSID and Password

To customize the WiFi access point, modify the `ssid` and `password` variables in the `esp-ps5-exploit-server.ino` file.

### Changing Payloads

You can change the payloads in the `/data/payloads` folder. Accepted payload file formats are: `.elf`, `.bin`, `.elf.gz`, and `.bin.gz`.

Additionally, you will need to update the contents of `/data/cache.appcache` and `/data/payload_map.js`. For example, in [this commit](https://github.com/vladimir-cucu/esp-ps5-exploit-server/commit/3b84b714b6e35657c85a357fe4042fbb25a6943e), you can see the changes made to add the `byepervisor` payload and update the `etaHEN` payload.

### Flashing `.ino` File

To manually flash the `.ino` file after customization, you can use [Arduino IDE 1.x](https://www.arduino.cc/en/software/) and the [Arduino ESP8266 Filesystem Uploader](https://github.com/esp8266/arduino-esp8266fs-plugin). It is recommended to select the **Flash Size: "4MB (FS: 3MB OTA: ~512KB)"** option in the **Tools** tab in order to have ~2.5MB available for payloads.
