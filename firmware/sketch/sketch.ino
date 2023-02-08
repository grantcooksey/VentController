#include "AHT20.h"

#define PIN_SDA PB0
#define PIN_SCL PB2
#define PIN_ANALOG_HUMIDITY_SHUTOFF_LEVEL PB3
#define PIN_MOTOR_RELAY PB4

// 0-1023 (10 bit ADC) on ATTinys
#define ADC_MAX_RANGE 1023
#define ONE_SECOND 1000

AHT20 AHT;

void setup() {
    pinMode(PIN_MOTOR_RELAY, OUTPUT);
    pinMode(PIN_ANALOG_HUMIDITY_SHUTOFF_LEVEL, INPUT);
    setupHumiditySensor();
}

void loop() {
    int humidityShutoffLevel = readHumidityShutoffLevel();
    int currentHumidityLevel = readCurrentHumidityLevel();
    if (currentHumidityLevel < humidityShutoffLevel) {
        enableFan();
    } else {
        disableFan();
    }
    delay(ONE_SECOND);
}

void setupHumiditySensor() {
    delay(100);
    AHT.begin();
    delay(100);
}

void enableFan() {
    digitalWrite(PIN_MOTOR_RELAY, HIGH);
}

void disableFan() {
    digitalWrite(PIN_MOTOR_RELAY, LOW);
}

int readCurrentHumidityLevel() {
    float humidity;
    float temp;

    // should we add an error indicator?
    AHT.getSensor(&humidity, &temp);
    humidity *= ADC_MAX_RANGE;
    return (int)humidity;
}

int readHumidityShutoffLevel() {
    return analogRead(PIN_ANALOG_HUMIDITY_SHUTOFF_LEVEL);
}
