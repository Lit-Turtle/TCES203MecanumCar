#ifndef MOTOR_H
#define MOTOR_H

#include <string>

class Motor {
private:
    std::string name;
    int speed;   // from -100 to +100
    bool enabled;

public:
    Motor();
    Motor(const std::string& motor);

    void setSpeed(int newSpeed);
    int getSpeed() const;

    void enable();
    void disable();
    bool isEnabled() const;

    std::string getName() const;
};

#endif