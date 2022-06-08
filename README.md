# My_radar
In this project, you are asked to render a 2D visualization panel showing a simulatation of air traffic (AT).  
The air traffic is a complex system with very strict rules to manage a large number of aircrafts.
  
For this first version of the simulation, you have to consider 2 types of entity :  
• aircrafts  
• control towers  

The basic rules for the my_radar are as follows :  
• aircrafts fly from given places to other ones  
• aircrafts appear on the simulation panel when they take off  
• aircrafts disappear from the simulation panel when they land on  
• aircrafts move in a straight line at given constant speeds  
• aircrafts colliding with another one is destroyed and disappear from the simulation panel  
• control areas allow aircrafts to collide with each other without being destroyed and they can continue
on their way  
• control towers don’t move and have control areas on the map  
• control towers appear on the simulation panel at launch  
## Requirements
### Must
• The program must take exactly one parameter.  
• The program must accept any filepath as argument. It corresponds to the file containing the script for
the simulation containing characters and integers.  
• The program must displayed an error message if the script is not found or incorrect.  
• Your window must be 1920x1080 pixels.  
• The window must be closed using events.  
• The program must display aircrafts’ hitbox and control towers’ areas.  
• The program must manage as many displayed entities as possible.  
• Aircrafts must have 20x20 square shaped hitboxes.  
• Aircrafts’ hitbox and sprite must be axis-aligned.  
• Control towers must have circled shaped control areas.
### Should
• The program should display and update a timer in seconds at the top-right corner of the window.  
• The program should stop once all aircrafts have landed on or have been destroyed.  
• Aircrafts should be able to take off after a given delay.  
• Aircrafts and control towers should be displayed using sprites.  
• The program should accept the “-h” option, then display the usage.  
• The program should be able to switch visibility of hitboxes and areas by pressing the key ‘L’.  
• The program should be able to switch visibility of entities’ sprites by pressing the key ‘S’.  
• Possible user interactions should be explicitly displayed in the usage.  
### Could
• Aircrafts’ hitbox and size could be in a 3D space.  
• Aircrafts could cross any side of a screen and appear on the opposite one.  
• Aircrafts’ hitbox and sprite could rotate depending on the aircrafts’ direction.  
• Aircrafts’ hitbox could follow the sprite boundary.  
• Aircrafts’ hitbox could have different sizes.  
• Control towers’ areas could cross any side of the screen and affect the opposite one.  
• The program could manage floating numbers coming from the script  
![example](https://github.com/iMeaNz/my_radar/blob/main/example.png?raw=true)  
## Script
The script file contains all the information about the simulation and the entities.  
Below is a example of a script file. You are free to use any kind of script formatting as long it’s described in a .legend file.  
Aircrafts are described by :  
• The letter ‘A’  
• Two integers corresponding to the departure x- and y-coordinates  
• Two integers corresponding to the arrival x- and y-coordinates  
• One integer corresponding to the aircraft’s speed (in pixels per second)  
• One integer corresponding to the delay (in seconds) before the aircraft takes off  
Control towers are described by :  
• The letter ‘T’  
• Two integers corresponding to the control tower x- and y-coordinates  
• One integer corresponding to the radius of the tower’s control area (in percentage of the greatest side
of the screen)  
Entities are separated by a ‘\n’.  
The pieces of information are separated by tabs or spaces.  
![example2](https://github.com/iMeaNz/my_radar/blob/main/script.png?raw=true)
## Usage
![example3](https://github.com/iMeaNz/my_radar/blob/main/usage.png?raw=true)