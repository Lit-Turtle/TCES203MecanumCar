#ifndef CAR_MODEL_H
#define CAR_MODEL_H

#include <string>

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

    void stopAllMotors();

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