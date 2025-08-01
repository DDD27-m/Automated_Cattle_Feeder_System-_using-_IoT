🐄🐟 Automated Cattle & Fish Feeder System

This project automates the **feeding and watering process** for cattle and fish using an Arduino, RTC module (DS3231), servo motor, 
and a relay-controlled water pump. The system is time-based, ensuring feed and water are dispensed at a preset hour daily with minimal human intervention.


🔧 Features

 ⏰ Time-controlled feeding using an RTC (Real-Time Clock)
 🥣 Servo motor-operated feed dispenser
 💧 Automatic water pump activation via relay
 🔁 Prevents multiple feeds in a day using a simple flag logic
 🔍 Serial monitor outputs current time for debugging and verification



⚙️ Hardware Components

| Component           | Purpose                          |
|---------------------|----------------------------------|
| Arduino UNO/Nano    | Microcontroller                  |
| DS3231 RTC Module   | Real-time clock for scheduling   |
| Servo Motor         | Dispenses feed                   |
| Relay Module        | Controls the water pump          |
| Water Pump (5V/12V) | Dispenses water                  |
| Jumper Wires        | Connections                      |
| External Power      | To power motor and pump safely   |



🧠 How It Works

1. Startup & Initialization:
   *  Arduino initializes RTC and checks for lost power.
   * If power was lost, the RTC is reset to the compile time.

2. Feeding Logic:
   *  At the set time (e.g., `7:00`), the servo dispenses feed.
   * The water pump is turned on using the relay.
   *  A flag (`Fed`) prevents multiple feedings within the same minute.

3. Reset Condition:
   * After 1 hour (`feedHour + 1`), the flag resets to allow feeding the next day.

4. Timing Control:
   *  The loop runs every 30 seconds to minimize delay and CPU usage.
   
🚀 Getting Started
* Wire the hardware according to your components.
* Upload the sketch to your Arduino board using Arduino IDE.
* Open Serial Monitor to verify time and behavior.
* Watch the system activate at the set time each day!

 Divyadharsini Dhanaraj
Electronics & Communication Engineering
