#include "Simulation.h"

void MecanumCar::applyCommand(MovementCommand cmd, double value) {
    switch (cmd) {
        case MovementCommand::MoveForward:
            moveForward(value);
            break;
        case MovementCommand::MoveBackward:
            moveBackward(value);
            break;
        case MovementCommand::TurnLeft:
            turnLeft(value);
            break;
        case MovementCommand::TurnRight:
            turnRight(value);
            break;
        case MovementCommand::RotateLeft:
            rotateLeft(value);
            break;
        case MovementCommand::RotateRight:
            rotateRight(value);
            break;
        case MovementCommand::Stop:
        default:
            stopAllMotors();
            break;
    }
}