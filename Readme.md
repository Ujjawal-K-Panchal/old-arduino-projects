# Old Arduino Projects

# About
These are some old Arduino Uno projects I made back in highschool in ~2014.
Major props to Paul McWhorter from TopTechBoy.com whose tutorials served as foundation for all my high-school Arduino endeavors!

Post initial release, they were revamped in 2016 documenting some important details; during holidays when I had a lot of free time. I'm releasing it again in 2025! For a few friends who recently started working on Arduino.

Setup assumes access to breadboard. Additionally, I provide hardware descriptions below. Looking at the *.ino code, it should be obvious to you which wire to attach which pin at.

Along with these descriptions, there are also important text files/screenshots attached that should help one track the reasoning behind some intricacies within the code.

All code is written for Arduino Uno in Arduino C. 

Many times, the code is not present in respective folder, but some other project I made using that hardware. Whenever this happens, I mention it in this readme with where to look for, for that piece of code.

# Folder: Hardware required.
1. KEYPAD: A 4x4 Universal 16 Key Switch Keypad keyboard + Arduino.
2. LCD: Controlling an LCD with Arduino. You can look at Burglar project for INO code. My screenshot in the LCD folder provides the respective pins.
3. LED: Simple Serial LEDs controlled by Arduino.
4. SERVO: Simple servo motor (SG90 9G) or similar. Look at SUNFLOWER for controlling it.
5. TCS3200: This is a simple color sensor.
6. LM35: This is a simple temperature sensor. I created a simple digital thermometer with this.
7. RGBLED: An LED capable of producing vividly different colors by controlling RGB components.
8. HCSR04: Sonar based Distance sensor. Using speed of sound in air, and the time it takes to catch back the thrown sound, we calculate the distance of object.
9. BURGALARM: This was a code-controlled door-lock I put on my room's door. Whenever someone entered my door without entering the correct password, a loudd buzzer rang. This was a cause of a lot of chaos at home & was eventually removed by mom :(. But hey! that freed up the hardware and chip for some other weird projects! 
10. LED-brightness-Controller: Control the brightness of an LED using the output from a potentiometer. Potentiometer btw is similar to what is used in those circular spindles on switchboards that control speed of fans.
11. SUNFLOWER: (Collab. w. Arth Modi, a very old friend). Basically, use Servo + small Solar Panel + LDRs. Using LDR's on each side of the panel, we can check which direction to tilt till we reach a state where both LDRs (L,R) show same resistance. This maximizes the amount of sunlight touching the panel by aligning correctly to the state of the sun currently. This is inspired from how a sunflower tracks the relative position of the sun to consume maximum sunlight directly.
