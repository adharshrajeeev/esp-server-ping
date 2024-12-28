const express = require('express');
const cors = require('cors');
const axios = require('axios');
require('dotenv').config();

const app = express();

const PORT = Number(process.env.PORT) || 3000;
const HOST = process.env.HOST || '0.0.0.0'; 
const ESP8266_IP = process.env.ESP8266_IP;

app.use(cors());

// Ping route
app.get('/ping', (req, res) => {
    console.log('Ping received!');
    res.json({ message: 'Pong!' });
});

// /right endpoint that will trigger the ESP8266 to turn on the LED
app.get('/on', async (req, res) => {
    console.log('turn on endpoint triggered!');
    try {
        if (!ESP8266_IP) {
            throw new Error("Esp ip required!")
        }
        const esp8266Response = await axios.get(`http://${ESP8266_IP}/trigger_led`); 
        res.json({ message: 'LED Triggered on ESP8266', esp8266_response: esp8266Response.data });
    } catch (error) {
        console.error('Error triggering ESP8266:', error);
        res.status(500).json({ message: 'Failed to trigger ESP8266 LED' });
    }
});

// /off endpoint that will turn off the LED
app.get('/off', async (req, res) => {
    console.log('Turn off endpoint triggered!');
    try {
        if (!ESP8266_IP) {
            throw new Error("Esp ip required!")
        }
        const esp8266Response = await axios.get(`http://${ESP8266_IP}/turnOff`);
        res.json({ message: 'LED Triggered off on ESP8266', esp8266_response: esp8266Response.data });
    } catch (error) {
        console.error('Error turning off ESP8266 LED:', error);
        res.status(500).json({ message: 'Failed to turn off ESP8266 LED' });
    }
});

app.listen(PORT, HOST, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
