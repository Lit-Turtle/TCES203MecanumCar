#include <limits>
#include <iostream>
using namespace std;

#include "Car.h"

// Interactive control mode: the user controls the car using simple commands.
void keyboardControl(MecanumCar& car)
{
    char cmd = ' ';
    double value = 0.0;

    while (true) {

        std::cout << "Commands:\n";
        std::cout << "  w d  : move forward   by d units\n";
        std::cout << "  s d  : move backward  by d units\n";
        std::cout << "  a d  : turn left    by d units\n";
        std::cout << "  d d  : turn right   by d units\n";
        std::cout << "  q a  : rotate left    by a degrees\n";
        std::cout << "  e a  : rotate right   by a degrees\n";
        std::cout << "  c    : toggle camera on/off\n";
        std::cout << "  x    : stop all motors\n";
        std::cout << "  z    : quit\n\n";

        std::cout << "Enter command: ";
        std::cin >> cmd;

        if (!std::cin) {
            car.stopAllMotors();
            return;
        }

        if (cmd == 'z') {
            car.stopAllMotors();
            break;
        }

        if (cmd == 'c') {
            if (car.getSnapshot().cameraStreaming) {
                car.cameraOff();
            } else {
                car.cameraOn();
            }
            continue;
        }

        if (cmd == 'x') {
            car.stopAllMotors();
            continue;
        }

        if (cmd != 'w' && cmd != 's' && cmd != 'a' &&
            cmd != 'd' && cmd != 'q' && cmd != 'e') {
            std::cout << "Unknown command.\n";
            continue;
        }

        std::cout << "Enter value: ";
        bool validValue = false;
        do {
            if (std::cin >> value) {
                validValue = true;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a number: ";
            }
        } while (!validValue);

        switch (cmd) {
        case 'w':
            car.moveForward(value);
            break;
        case 's':
            car.moveBackward(value);
            break;
        case 'a':
            car.turnLeft(value);
            break;
        case 'd':
            car.turnRight(value);
            break;
        case 'q':
            car.rotateLeft(value);
            break;
        case 'e':
            car.rotateRight(value);
            break;
        default:
            std::cout << "Unknown command.\n";
            break;
        }
    }
}

int main() {
    MecanumCar car;

    int choice;
    bool validInput;

    while(true) {
        validInput = false;
        do {
            cout << "=== Mecanum Car Menu ===" << endl;
            cout << "1) Move Forward" << endl;
            cout << "2) Move Backward" << endl;
            cout << "3) Turn Left" << endl;
            cout << "4) Turn Right" << endl;
            cout << "5) Rotate Left" << endl;
            cout << "6) Rotate Right" << endl;
            cout << "7) Stop" << endl;
            cout << "8) Wired Keyboard Control" << endl; //Need to be implemented
            cout << "9) WiFi Control" << endl; //Needs to be implemented
            cout << "10) Autonomous Loop Around Desk" << endl; //Needs to be implemented
            cout << "11) Quit" << endl;
            cout << "Choice #: ";

            if (cin >> choice) {
                if (choice < 1 || choice > 11) {
                    cout << "Invalid choice. Enter an integer from the given options." << endl;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    validInput = true;
                }
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter an integer." << endl;
            }
        } while (!validInput);

        switch(choice) {
            case 1: { //Move Forward
                double distanceForward;
                bool valid = false;
                do {
                    cout << "Distance to move forward: ";
                    if (cin >> distanceForward) {
                        valid = true;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a number." << endl;
                    }
                } while (!valid);
                car.moveForward(distanceForward);
                break;
            }
            case 2: { //Move Backward
                double distanceBack;
                bool valid = false;
                do {
                    cout << "Distance to move backward: ";
                    if (cin >> distanceBack) {
                        valid = true;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a number." << endl;
                    }
                } while (!valid);
                car.moveBackward(distanceBack);
                break;
            }
            case 3: { //Turn Left
                double distanceSL;
                bool valid = false;
                do {
                    cout << "Distance to turn left: ";
                    if (cin >> distanceSL) {
                        valid = true;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a number." << endl;
                    }
                } while (!valid);
                car.turnLeft(distanceSL);
                break;
            }
            case 4: { //Turn Right
                double distanceSR;
                bool valid = false;
                do {
                    cout << "Distance to turn right: ";
                    if (cin >> distanceSR) {
                        valid = true;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a number." << endl;
                    }
                } while (!valid);
                car.turnRight(distanceSR);
                break;
            }
            case 5: { //Rotate Left
                double degreeRL;
                bool valid = false;
                do {
                    cout << "Angle to rotate left: ";
                    if (cin >> degreeRL) {
                        valid = true;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a number." << endl;
                    }
                } while (!valid);
                car.rotateLeft(degreeRL);
                break;
            }
            case 6: { //Rotate Right
                double degreeRR;
                bool valid = false;
                do {
                    cout << "Angle to rotate right: ";
                    if (cin >> degreeRR) {
                        valid = true;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a number." << endl;
                    }
                } while (!valid);
                car.rotateRight(degreeRR);
                break;
            }
            case 7: //Stop
                car.stopAllMotors();
                break;
            case 8: //Keyboard control
                keyboardControl(car);
                break;
            case 9: //Wifi Control
                break;
            case 10: //Autonomous Desk Movement
                car.moveForward(500);
                car.rotateLeft(90.0);
                car.moveForward(200);
                car.rotateLeft(90.0);
                car.moveForward(600);
                car.rotateLeft(90.0);
                car.moveForward(200);
                car.rotateLeft(90.0);
                car.moveForward(50);
                break;
            default: //Quit
                return 0;
        }
    }
}