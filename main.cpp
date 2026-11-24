#include <limits>
#include <iostream>
using namespace std;

#include "Car.h"

// Interactive control mode: the user controls the car using simple commands.
void interactiveMode()
{
    MecanumCar car;
    car.cameraOn(); // just to show that camera can be turned on/off

    char cmd = ' ';
    double value = 0.0;

    while (true) {

        std::cout << "Commands:\n";
        std::cout << "  w d  : move forward   by d units\n";
        std::cout << "  s d  : move backward  by d units\n";
        std::cout << "  a d  : strafe left    by d units\n";
        std::cout << "  d d  : strafe right   by d units\n";
        std::cout << "  q a  : rotate left    by a degrees\n";
        std::cout << "  e a  : rotate right   by a degrees\n";
        std::cout << "  c    : toggle camera on/off\n";
        std::cout << "  x    : stop all motors\n";
        std::cout << "  z    : quit\n\n";

        std::cout << "Enter command: ";
        std::cin >> cmd;

        if (!std::cin) {
            return;
        }

        if (cmd == 'z') {
            break;
        }

        if (cmd == 'c') {
            // Toggle camera.
            // We cannot directly read camera state,
            // but we know startStream()/stopStream() exist.
            // For simplicity, just call start or stop alternatively.
            static bool cameraOnFlag = true;
            if (cameraOnFlag) {
                car.cameraOff();
                cameraOnFlag = false;
            } else {
                car.cameraOn();
                cameraOnFlag = true;
            }
            continue;
        }

        if (cmd == 'x') {
            car.stopAllMotors();
            continue;
        }

        std::cout << "Enter value: ";
        std::cin >> value;
        if (!std::cin) {
            return;
        }

        switch (cmd) {
        case 'w':
            car.moveForward(value);
            break;
        case 's':
            car.moveBackward(value);
            break;
        case 'a':
            car.strafeLeft(value);
            break;
        case 'd':
            car.strafeRight(value);
            break;
        case 'q':
            car.rotateLeft(value);
            break;
        case 'e':
            car.rotateRight(value);
            break;
        
        case ' ':
            car.stopAllMotors();
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
            cout << "3) Strafe Left" << endl;
            cout << "4) Strafe Right" << endl;
            cout << "5) Rotate Left" << endl;
            cout << "6) Rotate Right" << endl;
            cout << "7) Stop" << endl;
            cout << "8) Loop Around Desk" << endl;
            cout << "9) Quit" << endl;
            cout << "Choice #: ";

            if (cin >> choice) {
                if (choice < 1 || choice > 9) {
                    cout << "Invalid choice. Enter a intger from given options." << endl;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please enter an integer." << endl;
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
            case 3: { //Strafe Left
                double distanceSL;
                bool valid = false;
                do {
                    cout << "Distance to strafe left: ";
                    if (cin >> distanceSL) {
                        valid = true;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a number." << endl;
                    }
                } while (!valid);
                car.strafeLeft(distanceSL);
                break;
            }
            case 4: { //Strafe Right
                double distanceSR;
                bool valid = false;
                do {
                    cout << "Distance to strafe right: ";
                    if (cin >> distanceSR) {
                        valid = true;
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please enter a number." << endl;
                    }
                } while (!valid);
                car.strafeRight(distanceSR);
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
            case 8: //Loop Around Desk
                break;
            default: //Quit
                return 0;
        }
    }
}