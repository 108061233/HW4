Part1.
First, change the speed and the sleep time in code to make sure the car turn the same angle.
Second, determine the region, direct of the car, and the parallel and vertical distance to the center.
Third, cd HW4/Hw4_py and sudo python3 car_control.py /dev/ttyUSB0.
Fourth, enter the information about region, direct and parallel and vertical distance we get in second.
The result is that the car will turn first and then face to center, walk to center and park.

Part2.
First, change the speed and the sleep time in code to make sure the car turn the same angle.
Second, put a line on the ground and make sure there is no affrect on detecting by background.
Third, put the car on the line and it will start.
The result is that the car slowly walk along the line.

Part3.
First, change the speed and the sleep time in code to make sure the car turn the same angle.
Second, show AprilTag on screen or paper.
Third, put the car on the position that can detect the tag.
The result is that the car will turn right and left to make the car face to tag vertically.

Note.
Because my car is not perfect, there are some mistakes on calculating the speed.
bbcar_rpc_for_code1.cpp and bbcar_rpc_for_code1.h are just for read in github, these are RRC code for Part1 code.
part2.py and part3.py are the openMV code for Part2 and Part3.
