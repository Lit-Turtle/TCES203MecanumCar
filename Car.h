#ifndef CAR_H
#define CAR_H

#include <string>
#include "Camera.h"
#include "Motor.h"

enum class MovementCommand {
    MoveForward,
    MoveBackward,
    TurnLeft,
    TurnRight,
    RotateLeft,
    RotateRight,
    Stop
};

struct MotorSnapshot {
    std::string name;
    int speedPercent;
    bool enabled;
};

struct CarSnapshot {
    double x;
    double y;
    double headingDeg;
    bool cameraStreaming;
    MotorSnapshot frontLeft;
    MotorSnapshot frontRight;
    MotorSnapshot rearLeft;
    MotorSnapshot rearRight;
};

class MecanumCar {
private:
    Motor frontLeft;
    Motor frontRight;
    Motor rearLeft;
    Motor rearRight;
    Camera camera;

    double x;
    double y;
    double headingDeg;

    void updatePose(double dx, double dy, double dThetaDeg);

public:
    MecanumCar();

    void moveForward(double distance);
    void moveBackward(double distance);
    void turnLeft(double distance);
    void turnRight(double distance);
    void rotateLeft(double angleDeg);
    void rotateRight(double angleDeg);

    void stopAllMotors();
    void cameraOn();
    void cameraOff();
    void captureFrame() const;

    double getX() const;
    double getY() const;
    double getHeadingDeg() const;

    Motor getFrontLeftMotor() const;
    Motor getFrontRightMotor() const;
    Motor getRearLeftMotor() const;
    Motor getRearRightMotor() const;

    void applyCommand(MovementCommand cmd, double value);

    CarSnapshot getSnapshot() const;
};

#endif