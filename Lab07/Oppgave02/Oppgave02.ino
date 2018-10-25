const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;
const int potPin = A0;

enum ColorState { Red, Green, Blue };
ColorState currentState = Blue;

struct RGBValue {
    int red;
    int green;
    int blue;
};

void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
    currentState = getState(currentState, analogRead(potPin));
    implementState(currentState);
}

void implementState(ColorState state)
{
    RGBValue rgbValue;
    rgbValue.red = rgbValue.green = rgbValue.blue = 0;
    switch (currentState) {
    case Red:
        rgbValue.red = 255;
        break;
    case Green:
        rgbValue.green = 255;
        break;
    case Blue:
        rgbValue.blue = 255;
        break;
    }
    analogWrite(redPin, rgbValue.red);
    analogWrite(greenPin, rgbValue.green);
    analogWrite(bluePin, rgbValue.blue);
}

ColorState getState(ColorState state, int potValue)
{
    switch (state) {
        case Red:
            if (potValue < 750)
                return Blue;
            break;
        case Blue:
            if (potValue < 250)
                return Green;
            if (potValue > 850)
                return Red;
            break;
        case Green:
            if (potValue > 300)
                return Blue;
            break;
    }
    return state;
}