#include <iostream>
#include <cmath>
#include "Car.h"

MecanumCar::MecanumCar()
    : frontLeft("front-left"),
    frontRight("front-right"),
    rearLeft("rear-left"),
    rearRight("rear-right"),
    camera(),
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

void MecanumCar::turnLeft(double distance) {
    updatePose(-distance, 0.0, 0.0);
    frontLeft.setSpeed(-50);
    frontRight.setSpeed(50);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(-50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::turnright(double distance) {

    updatePose(-distance, 0.0, 0.0);
    frontLeft.setSpeed(50);
    frontRight.setSpeed(-50);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::rotateLeft(double angleDeg) {

    updatePose(0.0, 0.0, angleDeg);
    frontLeft.setSpeed(50);
    frontRight.setSpeed(-50);
    rearLeft.setSpeed(50);
    rearRight.setSpeed(-50);

    frontLeft.enable();
    frontRight.enable();
    rearLeft.enable();
    rearRight.enable();
}

void MecanumCar::rotateRight(double angleDeg) {
    updatePose(0.0, 0.0, -angleDeg);
    frontLeft.setSpeed(-50);
    frontRight.setSpeed(50);
    rearLeft.setSpeed(-50);
    rearRight.setSpeed(50);

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

void MecanumCar::cameraOn() {
    camera.startStreaming();
}

void MecanumCar::cameraOff() {
    camera.stopStreaming();
}

void MecanumCar::captureFrame() const {
    camera.captureFrame(x, y);
}

CarSnapshot MecanumCar::getSnapshot() const {
    CarSnapshot snapshot;
    snapshot.x = x;
    snapshot.y = y;
    snapshot.headingDeg = headingDeg;
    snapshot.cameraStreaming = camera.isStreaming();

    snapshot.frontLeft = {frontLeft.getName(), frontLeft.getSpeed(), frontLeft.isEnabled()};
    snapshot.frontRight = {frontRight.getName(), frontRight.getSpeed(), frontRight.isEnabled()};
    snapshot.rearLeft = {rearLeft.getName(), rearLeft.getSpeed(), rearLeft.isEnabled()};
    snapshot.rearRight = {rearRight.getName(), rearRight.getSpeed(), rearRight.isEnabled()};

    return snapshot;
}

Camera::Camera() : streaming(false)
{

}

void Camera::startStreaming() {
    streaming = true;
}

void Camera::stopStreaming() {
    streaming = false;
}

bool Camera::isStreaming() const {
    return streaming;
}

void Camera::captureFrame(double x, double y) const {
    std::cout << "[Camera] Capturing frame at (" << x << ", " << y << ")" << std::endl;
}