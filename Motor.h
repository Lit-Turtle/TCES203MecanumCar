#ifndef CAR_MODEL_H
#define CAR_MODEL_H

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

enum class MovementCommand {
    MoveForward,
    MoveBackward,
    StrafeLeft,
    StrafeRight,
    RotateLeft,
    RotateRight,
    Stop
};

class MecanumCar {
private:
    Motor frontLeft;
    Motor frontRight;
    Motor rearLeft;
    Motor rearRight;

    double x;
    double y;
    double headingDeg;

    void updatePose(double dx, double dy, double dThetaDeg);

public:
    MecanumCar();

    void moveForward(double distance);
    void moveBackward(double distance);
    void strafeLeft(double distance);
    void strafeRight(double distance);
    void rotateLeft(double angleDeg);
    void rotateRight(double angleDeg);

    void stopMotors();

    double getX() const;
    double getY() const;
    double getHeadingDeg() const;

    Motor getFrontLeftMotor() const;
    Motor getFrontRightMotor() const;
    Motor getRearLeftMotor() const;
    Motor getRearRightMotor() const;

    void useCommand(MovementCommand cmd, double value);

};

#endif