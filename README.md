# Arduino program for Flight Sim Trim Wheel with Raspberry Pi Pico

I needed to create a trim wheel for my Logitech/Saitek throttle quadrant. 
I decided to use this [3D printable wheel](https://www.thingiverse.com/thing:5316737/files) but the coded needed to be changed for the following reasons:

* The board I had was a Raspberry Pi Pico (not Arduino leonardo/micro pro). 
* I wanted to use a "Joystick Wheel" axis, not simulating joystick buttons.

The code uses the [PicoGamepad library](https://gitlab.com/realrobots/PicoGamepad/).

Connect the CLK pin of a KY-040 encoder to pin 21, and DT to pin 20.

Once flashed, the Pico is recognized as a USB gamepad and can be mapped to trim wheel in FS2024.

# Acknowledgments

Thanks Jmikefr on Thingiverse for the STL design, Jake Wilkinson (RealRobots) for the PicoGamepad library and example code.