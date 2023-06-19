#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

class NetworkManager {
  private:
    const char* ssid;
    const char* password;
    WiFiClientSecure wifiClient;

  public:
    NetworkManager(const char* ssid, const char* password);
    bool connect();
    String sendRequest(const char* url);
};
