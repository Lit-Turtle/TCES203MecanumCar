#include <iostream>
#include "Car.h"

MecanumCar::MecanumCar()
    : frontLeft("front-left"),
      frontRight("front-right"),
      rearLeft("rear-left"),
      rearRight("rear-right"),
      x(0.0), y(0.0), headingDeg(0.0) {
}

void MecanumCar::updatePose(double dx, double dy, double dThetaDeg) {
    x += dx;
    y += dy;
    headingDeg += dThetaDeg;
    headingDeg = std::fmod(headingDeg, 360.0);
    if (headingDeg < 0.0) {
        headingDeg += 360.0;
    }
}

void MecanumCar::moveForward(double distance) {
    updatePose(0.0, distance, 0.0);
    frontLeft.setSpeed(50);
    frontRight.setSpeed(50);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::moveBackward(double distance) {
    updatePose(0.0, -distance, 0.0);
    frontLeft.setSpeed(-50);
    frontRight.setSpeed(-50);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(-50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::strafeLeft(double distance) {
    updatePose(-distance, 0.0, 0.0);
    frontLeft.setSpeed(-50);
    frontRight.setSpeed(50);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::strafeRight(double distance) {

    updatePose(distance, 0.0, 0.0);
    frontLeft.setSpeed(50);
    frontRight.setSpeed(-50);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(-50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::rotateLeft(double angleDeg) {

    updatePose(0.0, 0.0, angleDeg);
    frontLeft.setSpeed(-50);
    frontRight.setSpeed(50);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::rotateRight(double angleDeg) {
    updatePose(0.0, 0.0, -angleDeg);
    frontLeft.setSpeed(50);
    frontRight.setSpeed(-50);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(-50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::stopAllMotors() {
    frontLeft.setSpeed(0);
    frontRight.setSpeed(0);
    rearLeft.setSpeed(0);
    rearRight.setSpeed(0);

    frontLeft.disable();
    frontRight.disable();
    rearLeft.disable();
    rearRight.disable();
}

double MecanumCar::getX() const {
    return x;
}

double MecanumCar::getY() const {
    return y;
}

double MecanumCar::getHeadingDeg() const {
    return headingDeg;
}

Motor MecanumCar::getFrontLeftMotor() const {
    return frontLeft;
}

Motor MecanumCar::getFrontRightMotor() const {
    return frontRight;
}

Motor MecanumCar::getRearLeftMotor() const {
    return rearLeft;
}

Motor MecanumCar::getRearRightMotor() const {
    return rearRight;
}