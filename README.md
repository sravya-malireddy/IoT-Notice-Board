# IoT Notice Board

A wireless IoT-based notice board that allows messages to be updated remotely and displayed on an LCD using an ESP8266 Wi-Fi microcontroller.

## Overview

Traditional notice boards require messages to be physically printed or replaced. This project demonstrates a wireless alternative where notices can be sent remotely and displayed on an electronic LCD.

The system uses the Wi-Fi capability of the ESP8266 to receive messages and a display module to present the notice to users.

## System Architecture


              User
                |
                | Notice / Message
                v
          Web Interface
                |
                | Wi-Fi
                v
          ESP8266 NodeMCU
                |
                | I2C
                v
             LCD Display
                |
                v
          Displayed Notice
          
## Working Principle
The ESP8266 initializes and connects to the configured Wi-Fi network.
A user accesses the notice interface through the network.
The user enters a message to be displayed.
The ESP8266 receives the message.
The controller processes the received text.
The message is sent to the LCD.
The LCD displays the updated notice.

## Hardware
NodeMCU ESP8266
16×2 LCD
I2C LCD interface
Breadboard / prototype board
Connecting wires
USB power supply

## Software
Arduino IDE
Embedded C/C++
ESP8266 Wi-Fi library
LCD / I2C library
Web server functionality
Key Features
Wireless notice updates
Wi-Fi-based communication
ESP8266-based embedded controller
LCD message display
Remote message control
Simple and low-cost implementation
Applications

## Applications:

College and school notice boards
Office announcements
Laboratory information displays
Public information systems
Reception areas
Small organizations
Event announcements

## Advantages
Eliminates the need for manually replacing printed notices
Allows messages to be updated remotely
Uses the built-in Wi-Fi capability of the ESP8266
Simple hardware implementation
Easy to extend with additional IoT functionality
Limitations
The display size limits the amount of information visible at once.
Operation depends on Wi-Fi connectivity.
A web-based implementation requires the ESP8266 and user device to be on a suitable network.
Future Improvements

## Possible improvements include:

Mobile application control
Cloud-based message management
Multiple display units
Scrolling text
Scheduled notices
Message history
User authentication
Real-time notifications
Larger LED matrix display
MQTT-based communication

## Project information

| Category      | Details                |
| ------------- | ---------------------- |
| Project       | IoT Notice Board       |
| Domain        | Embedded Systems / IoT |
| Controller    | NodeMCU ESP8266        |
| Communication | Wi-Fi                  |
| Display       | 16×2 LCD               |
| Interface     | I2C                    |
| Programming   | Embedded C/C++         |
| Development   | Arduino IDE            |
| Project Type  | Academic IoT Project   |
