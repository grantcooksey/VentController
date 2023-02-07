#define PIN_SDA PB0
#define PIN_SCL PB2
#define PIN_ANALOG_HUMIDITY_SHUTOFF_LEVEL PB3
#define PIN_MOTOR_RELAY PB4

// 0-1023 (10 bit ADC) on ATTinys
#define ADC_MAX_RANGE 1023

void setup() {
    pinMode(PIN_MOTOR_RELAY, OUTPUT);
    pinMode(PIN_ANALOG_HUMIDITY_SHUTOFF_LEVEL, INPUT);
}

// the loop function runs over and over again forever
void loop() {
    // Read trimmer value
    int humidityShutoffLevel = readHumidityShutoffLevel();
    int currentHumidityLevel = readCurrentHumidityLevel();
    if (currentHumidityLevel > humidityShutoffLevel) {
        enableFan();
    } else {
        disableFan();
    }
}

void enableFan() {
    return;
}

void disableFan() {
    return;
}

int readCurrentHumidityLevel() {
    return 1;
}

int readHumidityShutoffLevel() {
    return 1;
}
