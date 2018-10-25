const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;
const int potPin = A0;
const double growthFactor = 0.0007;

enum class ColorState { Red, Green, Blue };

struct RGBValue
{
    RGBValue() : red(0.0), green(0.0), blue(0.0) {};
    double red;
    double green;
    double blue;
};

void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    Serial.begin(57600);
}

void loop()
{
    RGBValue targetValue, currentValue;
    ColorState currentState = ColorState::Blue;
    while (true) {
        updateState(currentState, analogRead(potPin));
        implementState(targetValue, currentValue, currentState);
    }
}

void calculateCurrentValue(double& currentValue, double targetValue)
{
    if (currentValue < targetValue) currentValue += growthFactor;
        else if (currentValue > targetValue) currentValue -= growthFactor;
    if (currentValue > 1) currentValue = 1;
    if (currentValue < 0) currentValue = 0;
}

void implementState(RGBValue& currentValue, RGBValue& targetValue, ColorState state)
{
    switch (state)
    {
    case ColorState::Red:
        targetValue.red = 1.0;
        targetValue.green = targetValue.blue = 0.0;
        break;
    case ColorState::Green:
        targetValue.green = 1.0;
        targetValue.red = targetValue.blue = 0.0;
        break;
    case ColorState::Blue:
        targetValue.blue = 1.0;
        targetValue.red = targetValue.green = 0.0;
        break;
    }
    calculateCurrentValue(currentValue.red, targetValue.red);
    calculateCurrentValue(currentValue.green, targetValue.green);
    calculateCurrentValue(currentValue.blue, targetValue.blue);
    analogWrite(redPin, (int)(currentValue.red * 255));
    analogWrite(greenPin, (int)(currentValue.green * 255));
    analogWrite(bluePin, (int)(currentValue.blue * 255));
}

void updateState(ColorState& state, int potValue)
{
    switch (state)
    {
    case ColorState::Red:
        if (potValue < 750)
            state = ColorState::Blue;
        break;
    case ColorState::Blue:
        if (potValue < 250)
            state = ColorState::Green;
        if (potValue > 850)
            state = ColorState::Red;
        break;
    case ColorState::Green:
        if (potValue > 300)
            state = ColorState::Blue;
        break;
    }
}