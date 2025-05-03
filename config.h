#include <BearSSLHelpers.h>
#include <IPAddress.h>

namespace ServerConfig {
  const char* ssid = "PS5_WEB_AP";
  const char* password = "password";

  IPAddress ip(10,1,1,1);
  IPAddress gateway(10,1,1,1);
  IPAddress subnet(255,255,255,0);

  X509List cert("");
  PrivateKey key("");
}
