# ESP8266 LED Control Server

This project allows you to control an LED connected to an ESP8266 board using an Express server. The server provides two HTTP endpoints (`/on` and `/off`) to control the LED remotely through a simple web interface.

## Components:
- **ESP8266**: A microcontroller that controls the LED and connects to Wi-Fi.
- **Express**: A Node.js framework used to set up the server that communicates with the ESP8266.
- **Axios**: A promise-based HTTP client for the Express server to make requests to the ESP8266.


## Prerequisites

Before getting started, ensure you have the following:

- **Node.js** and **npm** installed on your local machine. You can download Node.js from [here](https://nodejs.org/).
- **ESP8266 Board** configured in your Arduino IDE. Instructions can be found [here](https://arduino-esp8266.readthedocs.io/en/latest/).
- **Wi-Fi Credentials**: Make sure to update the SSID and password for your Wi-Fi in the ESP8266 code.

### Installing ESP8266 Drivers

If you're using an ESP8266 development board (such as the NodeMCU or Wemos D1 mini), you may need to install the appropriate USB-to-serial drivers for your system.

- **For Windows**, download and install the [CP210x USB to UART Bridge VCP drivers](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) if you're using a CP2102 chipset.
- **For Mac OS X**, the drivers are typically included, but you can also get them from [Silicon Labs](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers).
- **For Linux**, the drivers should be available by default, but you may need to add the correct udev rules.

---

## Setup and Configuration

### 1. Clone the Repository

Clone the repository to your local machine:

```bash
git clone https://github.com/adharshrajeeev/esp-server-ping.git
cd esp-server-ping

2. Install Node.js Dependencies
In the server directory, install the required dependencies:

bash
Copy code
npm install
3. Set Up Environment Variables
Create a .env file in the root of the project and add the following content:

plaintext
Copy code
PORT=3000
HOST=0.0.0.0
ESP8266_IP=<your-esp8266-ip>  # Replace with your ESP8266 IP address
Make sure to replace <your-esp8266-ip> with the actual IP address of your ESP8266 device, which can be found in the serial monitor once it's connected to Wi-Fi.

4. Upload Code to ESP8266
Open the esp8266_code.ino file in Arduino IDE, configure the Wi-Fi credentials with your SSID and password, and upload the code to your ESP8266 board.

Running the Project
1. Start the Express Server
Run the Express server by executing the following command:

bash
Copy code
npm run start
The server will start running on the specified port (default 3000).

2. Interact with the ESP8266
You can now interact with the ESP8266 by visiting the following endpoints:

Turn on the LED:
Send a GET request to http://localhost:3000/on.

Turn off the LED:
Send a GET request to http://localhost:3000/off.

You can test these routes using a browser or any API testing tool like Postman.

