# ESP8266 PS5 Web Exploit Cached Host

A lightweight web server for ESP8266 boards that hosts the [PlayStation 5 UMTX2 Jailbreak](https://github.com/idlesauce/umtx2) for firmware versions `1.xx–5.xx`, with minor modifications to enable caching.

It comes with the [etaHEN v2.1b payload](https://github.com/etaHEN/etaHEN/releases/tag/2.1B) preloaded by default. The exploit is served at `http://10.1.1.1/index.html`, and you can use the [ESP Host FPKG](https://www.mediafire.com/file/w4e6hiuwfoj8dnb/esphost.zip) to cache it for offline use.

The use of PROGMEM to store exploit files and `elfldr.elf` payload—preserving SPIFFS space for other payloads—was heavily inspired by [stooged's PS5-Server project](https://github.com/stooged/PS5-Server) and [0x1iii1ii's fork](https://github.com/0x1iii1ii/PS5-Server/).

## TODO

- Add ability to modify SSID, password, and payloads from the web interface.
