#include <iostream>
#include "Simulation.h"

void MecanumCar::applyCommand(MovementCommand cmd, double value) {
    // For MovementCommand::Stop you can simply call stopAllMotors().
    if (cmd == MovementCommand::MoveForward) {
        moveForward(value);
    } else if (cmd == MovementCommand::MoveBackward) {
        moveBackward(value);
    } else if (cmd == MovementCommand::StrafeLeft) {
        strafeLeft(value);
    } else if (cmd == MovementCommand::StrafeRight) {
        strafeRight(value);
    } else if (cmd == MovementCommand::RotateLeft) {
        rotateLeft(value);
    } else if (cmd == MovementCommand::RotateRight) {
        rotateRight(value);
    } else {
        stopAllMotors();
    }
}