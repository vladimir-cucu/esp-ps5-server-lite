# ESP8266 PlayStation 5 Web Exploit Server

Lightweight web server for ESP8266 boards that hosts the [PlayStation 5 UMTX2 Jailbreak](https://github.com/idlesauce/umtx2) for firmware versions 1.00–5.50, with minor modifications to enable caching. The following payloads are preloaded: [etaHEN v2.1b](https://github.com/etaHEN/etaHEN/releases/tag/2.1B), [byepervisor](https://github.com/PS5Dev/Byepervisor) and [elfldr](https://github.com/ps5-payload-dev/elfldr).

## Quick Setup Guide

### Access Point Details

- SSID: `PS5_WEB_AP`
- Password: `password`

### Accessing the Exploit Page from ESP Host FPKG

The exploit is served at `http://10.1.1.1/index.html`. You can use [ESP Host FPKG](https://www.mediafire.com/file/w4e6hiuwfoj8dnb/esphost.zip) to access the exploit page directly. Once the page is cached, you can disconnect from internet and jailbreak your PS5 offline in the future.

### Accessing the Exploit Page from User's Guide

You will need to use `v1.10` of the precompiled `.bin` file. Starting from `v1.11`, the User's Guide no longer redirects to the exploit page. This is because additional DNS and HTTPS Servers are required for this feature to work, which makes the ESP8266 slow to provide the initial connection to your PS5 and WiFi connectivity issues can occur when using an FTP server.

I recommend you download and install [ESP Host FPKG](https://www.mediafire.com/file/w4e6hiuwfoj8dnb/esphost.zip) after successfully jailbreaking your console.

### Flashing Ready-To-Use `.bin` File

A ready-to-use `.bin` file can be downloaded from the [releases page](https://github.com/vladimir-cucu/esp-ps5-exploit-server/releases). One way to flash the `.bin` file to your ESP8266 board is by using the [NodeMCU PyFlasher](https://github.com/marcelstoer/nodemcu-pyflasher).

## Configuration and Customization

### Changing SSID, Password and/or Payloads

Access `http://10.1.1.1/admin.html` to customize the Access Point credentials and/or update the payloads.

When updating payloads, make sure that a valid `payload_map.js` and `cache.appcache` are provided, and that the total size of the uploaded payloads does not exceed 2.5MB.

### Manually flashing `.ino` File using Arduino IDE 2.x

To manually flash the `.ino` file after customization, you can use [Arduino IDE 2.x](https://www.arduino.cc/en/software/) and [Arduino LittleFS Upload](https://github.com/earlephilhower/arduino-littlefs-upload). It is recommended to select the **Flash Size: "4MB (FS: 3MB OTA: ~512KB)"** option in the **Tools** tab in order to have ~2.5MB available for payloads.

**Note:** To continue redirecting **User's Guide** to the exploit page after flashing the `.ino` file, valid self-signed TLS certificate `ServerConfig::cert` and private key `ServerConfig::key` should be provided in `config.h` file. For instance, you could use the certificate and key from [frwololo's PS4_PS5-ESP8266-Server project](https://github.com/frwololo/PS4_PS5-ESP8266-Server).

## Credits

This project uses PROGMEM to store exploit files and necessary payloads, preserving SPIFFS for additional payloads. This approach was inspired by [stooged's PS5-Server project](https://github.com/stooged/PS5-Server) and [0x1iii1ii's fork](https://github.com/0x1iii1ii/PS5-Server/).
