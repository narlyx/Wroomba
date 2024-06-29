#include "Arduino.h"

// Motor class
class Motor {
    private:
        int positive;
        int negetive;
    public:
        Motor(int positivePin, int negetivePin) {
            positive = positivePin;
            negetive = negetivePin;
        }
        void init() {
            pinMode(positive, OUTPUT);
            pinMode(negetive, OUTPUT);
        }
        void setPower(int power) {
            if (power == 0) {
                digitalWrite(positive, 0);
                digitalWrite(negetive, 0);
            } else if (power > 0) {
                digitalWrite(positive, power);
                digitalWrite(negetive, 0);
            } else {
                digitalWrite(positive, 0);
                digitalWrite(negetive, power);
            }
        }
};

// Button Class
class Button {
    private:
        int input;
        int redLed;
        int blueLed;
        int orangeLed;
    public:
        Button(int inputPin, int redLedPin,
        int blueLedPin, int orangeLedPin) {
            input = inputPin;
            redLed = redLedPin;
            blueLed = blueLedPin;
            orangeLed = orangeLedPin;
        }
        void init() {
            pinMode(input, INPUT);
            pinMode(redLed, OUTPUT);
            pinMode(blueLed, OUTPUT);
            pinMode(orangeLed, OUTPUT);
        }
        int getInput() {
            return digitalRead(input);
        }
        void setLeds(int redValue, int blueValue, int orangeValue) {
            digitalWrite(redLed, redValue);
            digitalWrite(blueLed, blueValue);
            digitalWrite(orangeLed, orangeValue);
        }
};

// Defining Classes
Button button(21,18,5,19);
Motor leftMotor(25,26);
Motor rightMotor(32,33);

// Setup Runtime
void setup()
{
  // Init Pins
  button.init();
  leftMotor.init();
  rightMotor.init();

  // Setting "status" led
  button.setLeds(1,0,1);
}

// Loop Runtime
void loop()
{
    leftMotor.setPower(1);
    rightMotor.setPower(1);
    delay(1000);
    leftMotor.setPower(0);
    rightMotor.setPower(0);
    delay(1000);
    leftMotor.setPower(-1);
    rightMotor.setPower(-1);
    delay(1000);
    leftMotor.setPower(0);
    rightMotor.setPower(0);
    delay(1000);
}
