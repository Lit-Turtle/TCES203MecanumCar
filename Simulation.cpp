#include <iostream>
#include "Simulation.h"

Simulator::Simulator(int size) {
    x = 0;
    y = 0;
    direction = 0;
    gridSize = size;

    grid = new int*[gridSize];

    for (int i = 0; i < gridSize; i++) {
        grid[i] = new int[gridSize];

        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = 0;
        }
    }

    grid[y][x] = 1;
}

Simulator::~Simulator() {
    for (int i = 0; i < gridSize; i++) {
        delete[] grid[i];
    }

    delete[] grid;
}

void Simulator::updatePosition(MovementCommand cmd, int distance) {
    grid[y][x] = 0;

    switch (cmd) {
        case MovementCommand::MoveForward:
            if (direction == 0)
                y -= distance;
            else if (direction == 1)
                x += distance;
            else if (direction == 2)
                y += distance;
            else if (direction == 3)
                x -= distance;
            break;

        case MovementCommand::MoveBackward:
            if (direction == 0)
                y += distance;
            else if (direction == 1)
                x -= distance;
            else if (direction == 2)
                y -= distance;
            else if (direction == 3)
                x += distance;
            break;

        case MovementCommand::TurnLeft:
        case MovementCommand::RotateLeft:
            turnDirection(-1);
            break;

        case MovementCommand::TurnRight:
        case MovementCommand::RotateRight:
            turnDirection(1);
            break;

        case MovementCommand::Stop:
            break;
    }

    if (x < 0) x = 0;
    if (x >= gridSize) x = gridSize - 1;
    if (y < 0) y = 0;
    if (y >= gridSize) y = gridSize - 1;

    grid[y][x] = 1;

    printState();
}

void Simulator::turnDirection(int amount) {
    direction += amount;

    if (direction < 0)
        direction = 3;

    if (direction > 3)
        direction = 0;
}

void Simulator::printState() const {




    std::cout << "Car Position: (" << x << ", " << y << ")" << std::endl;

    std::cout << "Car Direction: ";

    if (direction == 0)
        std::cout << "North";
    else if (direction == 1)
        std::cout << "East";
    else if (direction == 2)
        std::cout << "South";
    else
        std::cout << "West";

    std::cout << std::endl;

    std::cout << "\nGrid Map:\n";

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            std::cout << grid[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

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