/**
 * Smart Home Automation using NodeMCU ESP8266 and Arduino IoT Cloud
 *
 * Controls two lights and two fans through a four-channel, active-LOW
 * relay module. The Arduino IoT Cloud properties can be operated from
 * the cloud dashboard or through a linked Google Home account.
 */

#include "thingProperties.h"

// NodeMCU pin labels and their appliance assignments.
constexpr uint8_t RELAY_LIGHT_2_PIN = D0;  // GPIO16
constexpr uint8_t RELAY_LIGHT_1_PIN = D1;  // GPIO5
constexpr uint8_t RELAY_FAN_1_PIN   = D2;  // GPIO4
constexpr uint8_t RELAY_FAN_2_PIN   = D5;  // GPIO14

// The relay board used in this project is active-LOW.
constexpr uint8_t RELAY_ON  = LOW;
constexpr uint8_t RELAY_OFF = HIGH;

void setRelay(uint8_t pin, bool enabled) {
  digitalWrite(pin, enabled ? RELAY_ON : RELAY_OFF);
}

void configureRelay(uint8_t pin) {
  pinMode(pin, OUTPUT);
  setRelay(pin, false);  // Keep the appliance OFF during startup.
}

void setup() {
  Serial.begin(115200);

  configureRelay(RELAY_LIGHT_1_PIN);
  configureRelay(RELAY_LIGHT_2_PIN);
  configureRelay(RELAY_FAN_1_PIN);
  configureRelay(RELAY_FAN_2_PIN);

  // Defined in thingProperties.h.
  initProperties();

  // Connect to Arduino IoT Cloud.
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // Debug level range: 0 (errors only) to 4 (most detailed).
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}

// Called whenever the Light 1 cloud switch changes.
void onLight1Change() {
  setRelay(RELAY_LIGHT_1_PIN, light1);
  Serial.println(light1 ? F("Light 1: ON") : F("Light 1: OFF"));
}

// Called whenever the Light 2 cloud switch changes.
void onLight2Change() {
  setRelay(RELAY_LIGHT_2_PIN, light2);
  Serial.println(light2 ? F("Light 2: ON") : F("Light 2: OFF"));
}

// Called whenever the Fan 1 cloud switch changes.
void onFan1Change() {
  setRelay(RELAY_FAN_1_PIN, fan1);
  Serial.println(fan1 ? F("Fan 1: ON") : F("Fan 1: OFF"));
}

// Called whenever the Fan 2 cloud switch changes.
void onFan2Change() {
  setRelay(RELAY_FAN_2_PIN, fan2);
  Serial.println(fan2 ? F("Fan 2: ON") : F("Fan 2: OFF"));
}
