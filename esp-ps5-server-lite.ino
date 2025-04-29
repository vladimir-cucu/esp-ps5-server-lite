#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>

#include "exploit.h"

IPAddress local_IP(10,1,1,1);
IPAddress gateway(10,1,1,1);
IPAddress subnet(255,255,255,0);
const char* ssid = "PS5_WEB_AP";
const char* password = "password";
ESP8266WebServer server(80);

const char* payloadPaths[] = {
  "/payloads/byepervisor.elf.gz",
  "/payloads/etaHEN-2.1b.bin.gz"
};

String getContentType(const String path) {
  if(path.endsWith(".html") || path.endsWith("/")) return "text/html";
  else if(path.endsWith(".css")) return "text/css";
  else if(path.endsWith(".js")) return "application/javascript";
  else if (path.endsWith(".appcache")) return "text/cache-manifest";
  else if (path.endsWith(".elf") || path.endsWith(".bin")) return "application/octet-stream";
  else if (path.endsWith(".gz")) return "application/gzip";
  return "text/plain";
}

void handlePROGMEMRequest(const String path, const uint8_t* data, const uint32_t dataSize) {
  server.on(path, HTTP_GET, [path, data, dataSize](){
    server.sendHeader("Content-Encoding", "gzip");
    server.send(200, getContentType(path).c_str(), data, dataSize);
  });
}

void handleSPIFFSRequest(const String path) {
  server.on(path, HTTP_GET, [path]() {
    File file = SPIFFS.open(path, "r");
    server.streamFile(file, getContentType(path));
    file.close();
  });
}

void serveExploit() {
  handlePROGMEMRequest("/", umtx2_index_html, sizeof(umtx2_index_html));
  handlePROGMEMRequest("/index.html", umtx2_index_html, sizeof(umtx2_index_html));
  handleSPIFFSRequest("/cache.appcache");
  handlePROGMEMRequest("/custom_host_stuff.js", umtx2_custom_host_stuff_js, sizeof(umtx2_custom_host_stuff_js));
  handlePROGMEMRequest("/int64.js", umtx2_int64_js, sizeof(umtx2_int64_js));
  handlePROGMEMRequest("/main.css", umtx2_main_css, sizeof(umtx2_main_css));
  handlePROGMEMRequest("/main.js", umtx2_main_js, sizeof(umtx2_main_js));
  handleSPIFFSRequest("/payload_map.js");
  handlePROGMEMRequest("/rop.js", umtx2_rop_js, sizeof(umtx2_rop_js));
  handlePROGMEMRequest("/rop_slave.js", umtx2_rop_slave_js, sizeof(umtx2_rop_slave_js));
  handlePROGMEMRequest("/syscalls.js", umtx2_syscalls_js, sizeof(umtx2_syscalls_js));
  handlePROGMEMRequest("/umtx2.js", umtx2_umtx2_js, sizeof(umtx2_umtx2_js));
  handlePROGMEMRequest("/offsets/1.00.js", offsets_1_00_js, sizeof(offsets_1_00_js));
  handlePROGMEMRequest("/offsets/1.01.js", offsets_1_01_js, sizeof(offsets_1_01_js));
  handlePROGMEMRequest("/offsets/1.02.js", offsets_1_02_js, sizeof(offsets_1_02_js));
  handlePROGMEMRequest("/offsets/1.05.js", offsets_1_05_js, sizeof(offsets_1_05_js));
  handlePROGMEMRequest("/offsets/1.10.js", offsets_1_10_js, sizeof(offsets_1_10_js));
  handlePROGMEMRequest("/offsets/1.11.js", offsets_1_11_js, sizeof(offsets_1_11_js));
  handlePROGMEMRequest("/offsets/1.12.js", offsets_1_12_js, sizeof(offsets_1_12_js));
  handlePROGMEMRequest("/offsets/1.13.js", offsets_1_13_js, sizeof(offsets_1_13_js));
  handlePROGMEMRequest("/offsets/1.14.js", offsets_1_14_js, sizeof(offsets_1_14_js));
  handlePROGMEMRequest("/offsets/2.00.js", offsets_2_00_js, sizeof(offsets_2_00_js));
  handlePROGMEMRequest("/offsets/2.20.js", offsets_2_20_js, sizeof(offsets_2_20_js));
  handlePROGMEMRequest("/offsets/2.25.js", offsets_2_25_js, sizeof(offsets_2_25_js));
  handlePROGMEMRequest("/offsets/2.26.js", offsets_2_26_js, sizeof(offsets_2_26_js));
  handlePROGMEMRequest("/offsets/2.30.js", offsets_2_30_js, sizeof(offsets_2_30_js));
  handlePROGMEMRequest("/offsets/2.50.js", offsets_2_50_js, sizeof(offsets_2_50_js));
  handlePROGMEMRequest("/offsets/2.70.js", offsets_2_70_js, sizeof(offsets_2_70_js));
  handlePROGMEMRequest("/offsets/3.00.js", offsets_3_00_js, sizeof(offsets_3_00_js));
  handlePROGMEMRequest("/offsets/3.10.js", offsets_3_10_js, sizeof(offsets_3_10_js));
  handlePROGMEMRequest("/offsets/3.20.js", offsets_3_20_js, sizeof(offsets_3_20_js));
  handlePROGMEMRequest("/offsets/3.21.js", offsets_3_21_js, sizeof(offsets_3_21_js));
  handlePROGMEMRequest("/offsets/4.00.js", offsets_4_00_js, sizeof(offsets_4_00_js));
  handlePROGMEMRequest("/offsets/4.02.js", offsets_4_02_js, sizeof(offsets_4_02_js));
  handlePROGMEMRequest("/offsets/4.03.js", offsets_4_03_js, sizeof(offsets_4_03_js));
  handlePROGMEMRequest("/offsets/4.50.js", offsets_4_50_js, sizeof(offsets_4_50_js));
  handlePROGMEMRequest("/offsets/4.51.js", offsets_4_51_js, sizeof(offsets_4_51_js));
  handlePROGMEMRequest("/offsets/5.00.js", offsets_5_00_js, sizeof(offsets_5_00_js));
  handlePROGMEMRequest("/offsets/5.02.js", offsets_5_02_js, sizeof(offsets_5_02_js));
  handlePROGMEMRequest("/offsets/5.10.js", offsets_5_10_js, sizeof(offsets_5_10_js));
  handlePROGMEMRequest("/offsets/5.50.js", offsets_5_50_js, sizeof(offsets_5_50_js));
  handlePROGMEMRequest("/psfree/alert.js", psfree_alert_js, sizeof(psfree_alert_js));
  handlePROGMEMRequest("/psfree/config.js", psfree_config_js, sizeof(psfree_config_js));
  handlePROGMEMRequest("/psfree/psfree.js", psfree_psfree_js, sizeof(psfree_psfree_js));
  handlePROGMEMRequest("/psfree/module/chain.js", psfree_module_chain_js, sizeof(psfree_module_chain_js));
  handlePROGMEMRequest("/psfree/module/int64.js", psfree_module_int64_js, sizeof(psfree_module_int64_js));
  handlePROGMEMRequest("/psfree/module/mem.js", psfree_module_mem_js, sizeof(psfree_module_mem_js));
  handlePROGMEMRequest("/psfree/module/memtools.js", psfree_module_memtools_js, sizeof(psfree_module_memtools_js));
  handlePROGMEMRequest("/psfree/module/offset.js", psfree_module_offset_js, sizeof(psfree_module_offset_js));
  handlePROGMEMRequest("/psfree/module/rw.js", psfree_module_rw_js, sizeof(psfree_module_rw_js));
  handlePROGMEMRequest("/psfree/module/utils.js", psfree_module_utils_js, sizeof(psfree_module_utils_js));
}

void servePayloads() {
  handlePROGMEMRequest("/payloads/elfldr.elf", payloads_elfldr_elf, sizeof(payloads_elfldr_elf));
  for (int i = 0; i < sizeof(payloadPaths) / sizeof(payloadPaths[0]); i++) {
    handleSPIFFSRequest(payloadPaths[i]);
  }
}

void setup() {
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);
  SPIFFS.begin();

  serveExploit();
  servePayloads();

  server.begin();
}

void loop() {
  server.handleClient();
}
