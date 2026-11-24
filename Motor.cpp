#include <iostream>
#include "Motor.h"
#include <cmath>


Motor::Motor() : name("unnamed"), speed(0), enabled(false) {
}

Motor::Motor(const std::string& motor) : name(motor), speed(0), enabled(false) {
}

void Motor::setSpeed(int newSpeed) {
    if (newSpeed > 100) {
        speed = 100;
    } else if (newSpeed < -100) {
        speed = -100;
    } else {
        speed = newSpeed;
    }
}
int Motor::getSpeed() const {
    return speed;
}

void Motor::enable() {
    enabled = true;
}

void Motor::disable() {
    enabled = false;
    speed = 0;
}

bool Motor::isEnabled() const {
    return enabled;
}

std::string Motor::getName() const {
    return name;
}

void setDirection() {

}