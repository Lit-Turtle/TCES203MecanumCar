#How to Compile
Set-Location 'C:\TCESMecanumCar\TCES203MecanumCar'
g++ -Wall -Wextra -g3 main.cpp Car.cpp Motor.cpp Simulation.cpp -o output\main.exe
if ($LASTEXITCODE -eq 0) { .\output\main.exe }
#Class and File Description 

#Simulator and Menu Description

#3 Test Scenarios

#Reflection Paragraph