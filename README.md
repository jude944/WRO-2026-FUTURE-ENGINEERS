# WRO-2026-FUTURE-ENGINEERS
 # OWLEX - WRO Future Engineers 2026

## Team Information

Team Name: OWLEX

Competition: World Robot Olympiad (WRO) Future Engineers 2026

Project Type: Autonomous Self-Driving Robot

## Project Overview

OLEX is an autonomous robotic vehicle developed for the WRO Future Engineers 2026 competition. The main goal of this project is to design and build a self-driving robot capable of navigating through an environment, detecting obstacles, making decisions independently, and moving safely without human control.

The robot was designed according to the Future Engineers challenge requirements, focusing on autonomous navigation, sensor-based decision making, and reliable movement. The system combines mechanical design, electronic components, sensors, and software programming to create a robot that can understand its surroundings and react to different situations.

Our robot uses an Arduino microcontroller as the main control unit. The Arduino receives information from multiple sensors, processes the data using programmed algorithms, and sends commands to the motors and steering system. The programming language used for controlling the robot is C++.

The project focuses on creating a simple but effective autonomous driving system. Instead of following a fixed path, the robot continuously analyzes the surrounding environment using distance sensors and color detection sensors. Based on the collected information, it adjusts its direction and speed to avoid collisions and continue moving efficiently.

## Hardware Components

### Arduino Microcontroller

The Arduino board is the brain of the robot. It controls all connected components and executes the programmed logic. It receives input signals from sensors, processes the information, and controls the DC motors and servo motor according to the required movement.

Arduino was selected because it is reliable, easy to program, and suitable for robotics applications. It provides enough input and output pins to connect different sensors and actuators required for this project.

### DC Motors

The robot uses DC motors as the main driving system. These motors provide the movement power needed for the vehicle. The Arduino controls the motors through a motor driver, allowing the robot to move forward, backward, and adjust its movement according to the environment.

The DC motors were selected because they provide good speed control and enough torque for the robot structure.

### Servo Motor

A servo motor is used for the steering mechanism. It allows the robot to change its direction by controlling the angle of the wheels. The servo receives signals from the Arduino and adjusts the steering angle depending on sensor readings and the robot's current situation.

The steering system helps the robot make accurate turns and avoid obstacles while maintaining stable movement.

## Sensors

### Distance Sensors

The robot uses three front distance sensors positioned on the front, right, and left sides. These sensors measure the distance between the robot and nearby objects.

The information collected from these sensors allows the robot to understand the surrounding space and decide the best movement direction.

For example:
- If the robot detects that it is too close to the left side, it adjusts its steering direction toward the right side.
- If the robot detects that it is too close to the right side, it changes direction toward the left side.
- If an obstacle is detected very close in front of the robot, it moves backward to avoid collision.

This system allows the robot to react automatically without any external control.

### Ultrasonic Sensor

An ultrasonic sensor is used for obstacle detection. It measures the distance between the robot and objects in front of it by sending ultrasonic waves and calculating the returning signal.

The ultrasonic sensor improves safety by helping the robot detect obstacles early and take appropriate actions before collision.

### Light/Color Sensor

The robot also uses a color sensor to detect specific colors such as red and green. These colors are used as indicators during navigation.

When the robot detects a specific color in front of it, the system recognizes that there is an object or a special area that requires a different action. The robot then changes its movement strategy and avoids the detected area.

## Software Design

The robot software was developed using C++. The program is responsible for reading sensor values, analyzing the environment, and controlling the movement system.

The main algorithm follows a continuous decision-making process:

1. Read data from all sensors.
2. Analyze the distances around the robot.
3. Detect possible obstacles or special colors.
4. Decide the required movement.
5. Send commands to motors and steering system.
6. Repeat the process continuously.

The robot operates autonomously, meaning that no manual control is needed after starting the program.

## Navigation Algorithm

The navigation system is based on real-time sensor feedback. The robot does not follow a predefined line or path. Instead, it uses environmental information to decide how to move.

The distance sensors help the robot maintain a safe position between surrounding objects. The robot compares the distances measured from the left and right sides and adjusts its direction.

Examples of decisions:

- When the left side is closer than the right side, the robot turns slightly right to increase the distance from the left obstacle.
- When the right side is closer, the robot turns left.
- When an obstacle is detected directly ahead, the robot stops or moves backward to avoid impact.
- When a specific color is detected, the robot changes its path to bypass the detected object.

This approach allows the robot to adapt to changing conditions instead of depending on a fixed route.

## Mechanical Design

The mechanical structure was designed to support all electronic components while maintaining stability and efficient movement.

The robot includes:
- A stable chassis structure.
- DC motors for movement.
- Servo-based steering system.
- Arduino mounting area.
- Sensor placement locations for accurate measurements.

The placement of sensors was carefully considered to provide a wider understanding of the environment. The front sensors allow the robot to detect nearby obstacles, while the side sensors help maintain balanced movement.

## Testing and Development Process

During development, the robot went through several testing stages. Each component was tested separately before integrating the complete system.

Testing included:

- Testing DC motor movement.
- Testing servo steering angles.
- Checking sensor accuracy.
- Adjusting sensor positions.
- Improving movement decisions.
- Testing obstacle avoidance behavior.

Multiple software adjustments were made to improve the robot's reactions and make movement smoother.

The testing process helped identify problems such as incorrect turning directions, inaccurate distance readings, and delayed reactions. These problems were solved by modifying the program logic and improving the hardware arrangement.
### Switches

The robot includes two switches that are used for controlling and managing the electrical system.

The switches provide a simple way to turn the robot on and off and control the power connection safely. They help protect the electronic components by allowing the power supply to be disconnected when needed, especially during testing, maintenance, and transportation.

Using switches improves the reliability and safety of the robot system by giving the team better control over the electrical circuit.

## Challenges and Solutions

Building an autonomous robot created several challenges.

One challenge was achieving accurate movement decisions using sensor data. Sensors sometimes provide changing values depending on the environment, so the program needed filtering and logical conditions to make stable decisions.

Another challenge was balancing the relationship between speed and accuracy. Higher speed can make the robot react slower, while lower speed improves control. The final program was adjusted to provide a balance between both.

The steering system was also adjusted many times to achieve smoother turns and better navigation.

Through continuous testing and improvements, the robot became more reliable and capable of autonomous operation.

## Future Improvements

Although the current version of the robot achieves autonomous navigation, there are several possible improvements for future development.

Possible improvements include:
- Adding more advanced sensors.
- Improving the obstacle detection algorithm.
- Using more accurate distance measurements.
- Optimizing movement speed.
- Improving the mechanical structure.
- Adding camera-based recognition systems.

These improvements could make the robot faster, more accurate, and better prepared for complex environments.

## Project Media

### Robot Images

Robot images are available in the photos folder of this repository.

### Demonstration Video

The robot demonstration video is available through the following YouTube link:
##video 
https://youtube.com/shorts/DfPdfl8Hiz0?si=BSAbJ4D4_I9i60CX


## Conclusion

The OLEX team developed an autonomous robot for the WRO Future Engineers 2026 competition using Arduino, DC motors, servo steering, and multiple sensors. The robot demonstrates autonomous decision-making by analyzing distances, detecting obstacles, and responding to environmental changes.

This project helped us develop important skills in robotics, programming, electronics, mechanical design, and problem solving. Through teamwork and continuous testing, we created a functional autonomous vehicle capable of navigating independently and adapting to different situations.
 Team Members

-Jude Salah 
-Deema 
- Sadeel Al-Rimawi 



WRO 2026 Future Engineers

