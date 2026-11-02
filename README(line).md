# Line Follower Robot Mini Project

**Platform:** Arduino UNO  
**Sensors:** Two digital IR sensor modules  
**Motor driver:** L298N  
**Motors:** Two DC geared motors

## 1. Project overview
A line follower robot detects a dark line on a light surface using IR sensors. The Arduino reads the sensor outputs and controls the two DC motors through the L298N motor driver.

## 2. Files in this repository
- `main.ino` — Arduino program.
- `circuit_diagram.png` — illustrative wiring/block connection guide.
- `robot_layout.png` — illustrative component placement.
- `output_demo.png` — example of the expected line-following behaviour (illustration, not a photograph of a tested robot).

## 3. Components required
1. Arduino UNO
2. Two digital IR sensor modules
3. L298N motor driver
4. Two DC geared motors and wheels
5. Robot chassis and caster wheel
6. Battery suitable for the motors and driver
7. Jumper wires

## 4. Wiring guide

| Module pin | Arduino / connection |
|---|---|
| Left IR sensor OUT | D2 |
| Right IR sensor OUT | D3 |
| Both IR sensor VCC | 5V |
| Both IR sensor GND | GND |
| L298N ENA | D5 |
| L298N IN1 | D8 |
| L298N IN2 | D9 |
| L298N IN3 | D10 |
| L298N IN4 | D11 |
| L298N ENB | D6 |
| L298N OUT1/OUT2 | Left DC motor |
| L298N OUT3/OUT4 | Right DC motor |

Connect the motor battery to the L298N motor supply input according to the driver's rating. Connect Arduino GND and L298N GND together (common ground). Do not power the motors from the Arduino 5V pin.

If using the ENA/ENB jumpers, remove them when controlling enable pins from D5/D6. Use a suitable regulated 5V supply for the Arduino if required by your setup.

## 5. Upload and test
1. Install/open Arduino IDE.
2. Connect Arduino UNO to the computer with USB.
3. Open `main.ino`.
4. Select **Tools → Board → Arduino UNO**.
5. Select the correct **Tools → Port**.
6. Click **Verify**, then **Upload**.
7. Test the sensors over the actual black tape and white floor before running the robot.

## 6. Sensor calibration
Many digital IR modules output LOW on black and HIGH on white. Others may behave oppositely. In `main.ino`, change:
```cpp
const int BLACK = LOW;
```
to `HIGH` if your sensor gives HIGH on black. Confirm the output using the sensor indicator or Serial Monitor.

## 7. Basic logic
- Both sensors detect black: move forward.
- Left sensor detects black only: steer left.
- Right sensor detects black only: steer right.
- Both sensors detect white: stop.

This is a simple starting logic. Sensor placement, motor direction, track width, and sensor polarity may require adjustment. If a motor rotates in the wrong direction, swap its two motor wires or reverse its direction logic in the code.

## 8. Safety
- Lift the wheels off the ground during the first motor test.
- Check polarity and wiring before connecting the battery.
- Use a battery and motor driver within their rated voltage/current.
- Never short the battery terminals.
- Keep fingers, wires, and loose clothing away from moving wheels.

## 9. Expected result
After correct wiring and calibration, the robot should follow a black path on a light surface. The image `output_demo.png` is only an explanatory illustration; replace it with your own actual robot testing photos for the final college report.

## 10. Author details
Student Name: ____________________  
Roll No.: ____________________  
Batch: ____________________
