
// analog pins
const int analogPins[8] = {A0,A1,A2,A3,A4,A5,A6,A7};

// digital pins
const int digitalPins[10] = {2,3,4,5,6,7,8,9,10,11};

// sensor values
int sensorValues[80];

void setup() {

    // initialize serial communication at 9600 bps
    Serial.begin(9600);

    // initialize digital pins
    for (int digitalPin: digitalPins) {

        // configure output
        pinMode(digitalPin, OUTPUT);

        // disable column
        digitalWrite(digitalPin, LOW);
    }
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

            // T_ON (time to 99% of final voltage value)
            delayMicroseconds(30);

            // rows loop
            for (int analogPin: analogPins) {
                
                // read temperature sensor
                sensorValues[i] = analogRead(analogPin);
                i++;
            }

            // disable column
            digitalWrite(digitalPin, LOW);
        }

        // write sensor values as an array of bytes
        Serial.write( (byte*)sensorValues, sizeof(sensorValues) );
    }
}
