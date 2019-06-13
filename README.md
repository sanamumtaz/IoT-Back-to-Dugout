# IoT-Back-to-Dugout
Cricket is a sport that is loved by many people. Each decision made by umpires is crucial. The third umpire decision is the most nail biting.
Here provided is an IoT based solution on smaller scale for easy detection of a run-out.
## Implementation
-	The system consists of two sensors that feed their output to NodeMCU.
-	We have to detect both the batsman when he crosses the line and also the moment the wicket bails are hit by the ball.
-	The end of the bat and shoes of batsmen are of a unique color. We install a color sensor that senses that specific color and, hence, detects only the batsman.
-	A sensor has to detect only when the ball touches the bails. Hence, we use a touch sensor.
-	When either color sensor detects that specific color or touch sensor gives positive output, the results are fed to the NodeMCU where condition are checked to determine whether it was a runout or not.
-	Result is displayed to the 3rd umpire, on OLED  screen, who then makes the announcement.

**NodeMCU**

**TCS3200 color sensor**

**TTP223b touch sensor**

**OLED**

![image](https://user-images.githubusercontent.com/35191030/59454168-f1528b00-8e2a-11e9-8ad7-6f9533db3ef8.png)
## Future Upgrades:
-	This is a prototype over a small scale.
-	A motion detector can also be added to the implementation for best accurate results.
-	In real-time implementation, the hardware usage may vary.
