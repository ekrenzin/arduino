#include <ESP8266WiFi.h>
#include "Button.h"
#include "NetworkManager.h"


const char* ssid     = "E&S_2.4ghz";     // your network SSID (name of wifi network)
const char* password = "E&SAdmin0330"; // your network password

NetworkManager network(ssid, password);
Button myButton(5); // GPIO5/D1
 
void sendReq() {
  String response = network.sendRequest("https://192.168.0.177:3000/");
  Serial.println(response);
}

void warnOfError() {
  Serial.println("error with wifi");
  if (network.connect()) {
    Serial.println("Connected to Wi-Fi");
    myButton.setOnPressStartFunction(sendReq);
  } else {
    Serial.println("Failed to connect to Wi-Fi");
    myButton.setOnPressStartFunction(warnOfError);
  }
}

void setup() {
  Serial.println("SETUP");
  Serial.begin(115200);
  delay(1000);

  if (network.connect()) {
    Serial.println("Connected to Wi-Fi");
    myButton.setOnPressStartFunction(sendReq);
  } else {
    Serial.println("Failed to connect to Wi-Fi");
    myButton.setOnPressStartFunction(warnOfError);
  }
}

void loop() {
  myButton.checkButton();
  delay(50); // slight delay for debounce
}