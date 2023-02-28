#https://arduino.github.io/arduino-cli/0.31/getting-started/
arduino-cli compile --fqbn arduino:avr:mega arduino_code.ino
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:mega arduino_code.ino
