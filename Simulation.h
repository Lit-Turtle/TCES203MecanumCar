#ifndef SIMULATION_H
#define SIMULATION_H
#include <iostream>
#include "Car.h"

enum class MovementCommand {
    MoveForward,
    MoveBackward,
    TurnLeft,
    TurnRight,
    RotateLeft,
    RotateRight,
    Stop
};

class MecanumCar {
public:
    void applyCommand(MovementCommand cmd, double value);

    void moveForward(double value);
    void moveBackward(double value);
    void turnLeft(double value);
    void turnRight(double value);
    void rotateLeft(double value);
    void rotateRight(double value);
    void stopAllMotors();
};

class Simulator {
private:
    int x;
    int y;
    int direction;
    int gridSize;
    int** grid;

public:
    Simulator(int size);
    ~Simulator();

    void updatePosition(MovementCommand cmd, int distance);
    void printState() const;
    void turnDirection(int amount);
};


#endif