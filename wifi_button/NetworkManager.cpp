#include "NetworkManager.h"

NetworkManager::NetworkManager(const char* ssid, const char* password) : ssid(ssid), password(password) {}

bool NetworkManager::connect() {
  WiFi.begin(ssid, password);
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - startTime > 5000) { // 5 seconds timeout
      return false; // failed to connect
    }
    delay(500);
  }
  return true; // connected
}

String NetworkManager::sendRequest(const char* url) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Not connected to WiFi.");
    return "Error - no wifi";
  } else {
    Serial.println(WiFi.localIP());
  }

  Serial.println("SEND REQ");
  
  HTTPClient httpClient;
  WiFiClientSecure wifiClient;

  //this is to trust my local ssl
  wifiClient.setInsecure(); 

  httpClient.begin(wifiClient, url);
  
  int httpCode = httpClient.GET();
  Serial.println("HTTP code: " + String(httpCode));

  if (httpCode == 200) {
    Serial.println("200 BACK");
    String response = httpClient.getString();
    Serial.println("Response: " + response);
    return response;
  } else {
    String errorMsg = "Error: " + String(httpCode);
    Serial.println(errorMsg);
    return errorMsg;
  }
}


