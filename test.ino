#include <AccelStepper.h>

#define BASE_DIR_PIN 2
#define BASE_STEP_PIN 3

#define TOP_DIR_PIN 4
#define TOP_STEP_PIN 5

AccelStepper base(AccelStepper::DRIVER, BASE_STEP_PIN, BASE_DIR_PIN);
AccelStepper top(AccelStepper::DRIVER, TOP_STEP_PIN, TOP_DIR_PIN);

int16_t MOTOR_SPEED = 1000;
bool magnet = false;
void setup()
{
    Serial.begin(9600);
    base.setMaxSpeed(MOTOR_SPEED);
    top.setMaxSpeed(MOTOR_SPEED);
}

void loop()
{
    char val = 0;
    while (Serial.available() > 0)
        val = Serial.read();
    switch (val)
    {
    case '1':
        base.setSpeed(MOTOR_SPEED);
        top.setSpeed(MOTOR_SPEED);
        Serial.println("BASE CW");
        break;
    case '2':
        base.setSpeed(-MOTOR_SPEED);
        top.setSpeed(-MOTOR_SPEED);
        Serial.println("BASE CCW");
        break;
    case '3':
        base.setSpeed(0);
        top.setSpeed(MOTOR_SPEED);
        Serial.println("TOP CW");
        break;
    case '4':
        base.setSpeed(0);
        top.setSpeed(-MOTOR_SPEED);
        Serial.println("TOP CCW");
        break;
    case '5':
        base.setSpeed(0);
        top.setSpeed(0);
        Serial.println("STOP");
        break;
    case '6':
        magnet = !magnet;
        if (magnet)
            digitalWrite(6, HIGH);
        else
            digitalWrite(6, LOW);
        Serial.println(magnet);
        break;
    }
    base.runSpeed();
    top.runSpeed();
}
