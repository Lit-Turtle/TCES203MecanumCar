#ifndef SIMULATION_H
#define SIMULATION_H
#include "Car.h"

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