OCCRA-2012-Team43-Goll-Roll
===========================

This is OCCRA Team 43, the Holly/Grand Blanc Bronchos, robot code for the 2012 Oakland County Competitive Robotics Association game, Goal Roll. The Holly Bronchos graciously invited the EngiNERDs to participate in OCCRA with them this year.

OCCRA uses the IFI Vex Cortex microcontroller; our code was written for the EasyC V4 IDE for the Cortex. This code is nothing complicated in terms of an overarching structure: I hope it provides simple routines for OCCRA teams to take and use for the future.

A robot picture ("robot.jpg") and official 2012 OCCRA Rules (file "OCCRA2012.doc") are included.

Unfortunately, the EasyC project file is not up-to-date (until I regain access to a copy of the program).

Robot and code features:
---------------------------
### Drivetrain
* **Six wheel drive**, a center drop of roughly 1/8", middle and rear plaction wheels with FRC KoP front wheels, driven by four CIMs.
* **Arcade drive code**, inspired by FRC 254 and built upon FRC/VRC/OCCRA 33.
* Chassis was non-KoP, aluminum tubing H-style frame

### Goal Manipulation
* **Two hooks built with KoP c-channel** on the same axle to grab and manipulate roller goals, driven by a DeWalt drill motor.
* Two routines: one designed for forward and backward, the other for manual joystick control.

### Bonus Ball Arm
* A **single-pivot arm** driven by a PG71 through bevel gears and a custom gearbox
* Utilized a **gas shock** to keep pressure on the big ball at all points
* A string was tied to keep the arm in starting position. Raising the arm would release the string, sliding the top part of the arm into a picking-up position.
* A window motor drove a **wheel that took the ball in** and pushed the ball out.
* Tested numerous times outside of the field, the arm was never successfully used during an official match (failed to pick up a bonus ball one time, was then tweaked and picked up the bonus ball quickly as time expired)
* Could not handle smaller, 1-point balls

### Electrical Box Design
* The team went through three electrical boxes this season
* Finally settled on a large box that had room on the bottom for a large power distribution board, a raised platform for a Cortex, and seven Victors.
* We recommend using a soldering iron to melt holes into the electrical box to mount components (a U-bolt for fastening down wires, perhaps the main breaker, access to the Cortex's USB port
