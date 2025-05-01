# ESP8266 PlayStation 5 Web Exploit Server

Lightweight web server for ESP8266 boards that hosts the [PlayStation 5 UMTX2 Jailbreak](https://github.com/idlesauce/umtx2) for firmware versions 1.00–5.50, with minor modifications to enable caching. The following payloads are currently preloaded: [etaHEN v2.1b](https://github.com/etaHEN/etaHEN/releases/tag/2.1B), [byepervisor](https://github.com/PS5Dev/Byepervisor) and [elfldr](https://github.com/ps5-payload-dev/elfldr).

## Quick Setup Guide

### Access Point Details

- SSID: `PS5_WEB_AP`
- Password: `password`

### Accessing the Exploit Page

The exploit is served at `http://10.1.1.1/index.html`.

To access the exploit page for the first time, from your PS5 console's home screen, go to **Settings > User's Guide, Health and Safety, and Other Information**.

After successfully jailbreaking your PS5, you can install the [ESP Host FPKG](https://www.mediafire.com/file/w4e6hiuwfoj8dnb/esphost.zip) to open the cached exploit page for offline use in the future.

### Flashing Ready-To-Use `.bin` File

A ready-to-use `.bin` file can be downloaded from the [releases page](https://github.com/vladimir-cucu/esp-ps5-exploit-server/releases). One way to flash the `.bin` file to your ESP8266 board is by using the [NodeMCU PyFlasher](https://github.com/marcelstoer/nodemcu-pyflasher).

## Configuration and Customization

### Changing SSID and Password

To customize the WiFi access point, modify `ServerConfig::ssid` and `ServerConfig::password` in `config.h` file.

### Changing Payloads

You can change the payloads in `/data/payloads` folder. Only `.elf` and `.bin` payload formats are supported.

Additionally, you will need to update the contents of `/data/cache.appcache` file, `/data/payload_map.js` file and `PayloadConfig::paths` in `config.h` file.

### Flashing `.ino` File

To manually flash the `.ino` file after customization, you can use [Arduino IDE 1.x](https://www.arduino.cc/en/software/) and the [Arduino ESP8266 Filesystem Uploader](https://github.com/esp8266/arduino-esp8266fs-plugin). It is recommended to select the **Flash Size: "4MB (FS: 3MB OTA: ~512KB)"** option in the **Tools** tab in order to have ~2.5MB available for payloads.

**Note:** To continue redirecting **User's Guide** to the exploit page after flashing the `.ino` file, valid self-signed TLS certificate `ServerConfig::cert` and private key `ServerConfig::key` should be provided in `config.h` file.

## Credits

This project uses PROGMEM to store exploit files and necessary payloads, preserving SPIFFS for additional payloads. This approach was inspired by [stooged's PS5-Server project](https://github.com/stooged/PS5-Server) and [0x1iii1ii's fork](https://github.com/0x1iii1ii/PS5-Server/).
