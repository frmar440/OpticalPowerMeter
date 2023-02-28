
// analog pins
const int analogPins[8] = {A7,A6,A5,A4,A3,A2,A1,A0};

// digital pins
const int digitalPins[10] = {11,10,9,8,7,6,5,4,3,2};

// sensor values
int sensorValues[80];

void setup() {

    // initialize serial communication at 9600 bps
    Serial.begin(9600);

    // disable columns
    for (int digitalPin: digitalPins) {
        pinMode(digitalPin, OUTPUT);
        digitalWrite(digitalPin, LOW);
    }

    Serial.println("Start")
}

void loop() {

    // send data only when available
    if (Serial.available() > 0) {

        // empty serial receive buffer
        Serial.read();

        // sensorValues index
        int i = 0;

        // columns loop
        for (int digitalPin: digitalPins) {

            // enable column
            digitalWrite(digitalPin, HIGH);

            // rows loop
            for (int analogPin: analogPins) {
                
                // read temperature sensor
                sensorValues[i] = analogRead(analogPin);
                i++;

            }

            // disable column
            digitalWrite(digitalPin, LOW);

        }

        // write sensor values
        Serial.write(bite(sensorValues), 160);
    }
}
