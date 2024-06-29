// Motor
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

// Button
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
