# ESP8266 PS5 Web Exploit Cached Host

A lightweight web server for ESP8266 boards that hosts the [PlayStation 5 UMTX2 Jailbreak](https://github.com/idlesauce/umtx2) for firmware versions `1.xx–5.xx`, with minor modifications to enable caching.

It comes with [etaHEN v2.1b](https://github.com/etaHEN/etaHEN/releases/tag/2.1B) and [byepervisor](https://github.com/PS5Dev/Byepervisor) payloads preloaded by default. The exploit is served at `http://10.1.1.1/index.html`, and you can use the [ESP Host FPKG](https://www.mediafire.com/file/w4e6hiuwfoj8dnb/esphost.zip) to cache it for offline use.

The use of PROGMEM to store exploit files and `elfldr.elf` payload—preserving SPIFFS space for other payloads—was heavily inspired by [stooged's PS5-Server project](https://github.com/stooged/PS5-Server) and [0x1iii1ii's fork](https://github.com/0x1iii1ii/PS5-Server/).

A precompiled `.bin` file can be downloaded from the [releases page](https://github.com/vladimir-cucu/esp-ps5-server-lite/releases). One way of flashing the `.bin` file to your ESP8266 board is by using the [NodeMCU PyFlasher](https://github.com/marcelstoer/nodemcu-pyflasher).

## Access Point Details

```
SSID: PS5_WEB_AP
password: password
```

## Customization

### Changing SSID and password

To customize the WiFi access point, modify the `ssid` and `password` variables in the `esp-ps5-server-lite.ino` file.

### Adding or Removing Payloads

You can add or remove payloads to the `/data/payloads` folder. Additionally, you will need to update the contents of `/data/cache.appcache` and `/data/payload_map.js`. For example, in [this commit](https://github.com/vladimir-cucu/esp-ps5-server-lite/commit/3b84b714b6e35657c85a357fe4042fbb25a6943e), you can see the changes made to add the `byepervisor` payload and update the `etaHEN` payload.

### Flashing the ESP8266

To manually flash the ESP8266 after customization you can use [Arduino IDE 1.x](https://www.arduino.cc/en/software/) and [Arduino ESP8266 Filesystem Uploader](https://github.com/esp8266/arduino-esp8266fs-plugin). In the **Tools** menu, it is necessary to select the **Flash Size: "4MB (FS: 3MB OTA: ~512KB)"** option in order to have ~3MB for payloads.
