# Halloween Animation

My love of Halloween and my love of tinkering came together again last year. I was inspired to finally teach myself the basics of microcontrollers and breadboarding with a new project: a programable Halloween animation.

I've always had an interest in creating an animation like this but never knew where to start. I wanted to push myself with this project and build the mechanism to be fully programmable. I didn’t want to just attach a motor to an armature that would move the prop back and forth. I really wanted to make the thing as believable as possible.

I decided on building a 3-axis head mechanism. This would give me three directions of head movement: rotate, pan, and tilt. Each of those directions would be independently controllable. I constructed the mechanism using a few resources I found online. Measuring, cutting, drilling, sanding—I took great care to construct the armature with precision; any discrepancies could result in unwanted movement.

Once the armature was complete, I attached servo motors in the appropriate positions.

<br>
<p float="left">
<img src="https://user-images.githubusercontent.com/33403525/189650058-efb511c9-deda-443b-82d8-efe080e1daf1.jpeg" width="350" />
<img src="https://user-images.githubusercontent.com/33403525/189651456-ae07a8db-1a69-45f2-83b6-5cad43c91a52.jpeg" width="350" />
</p>
<br>

Then began the programming and testing...

I opted to use an Arduino Uno microcontroller. Its versatility and accessibility made it perfect for this project. With minimal overhead and a custom IDE, the Arduino Uno made setup and programming a breeze. Getting familiar with the Arduino gave me the confidence to start exploring other microcontrollers, like the Raspberry Pi. 

To generate servo motion that was fluid and believable, I made use of a fantastic <a href=“https://github.com/ArminJo/ServoEasing”>servo easing library</a> that allowed me to fine-tune the servo motion. The servos were able to smoothly accelerate and decelerate, emulating different sine functions. The library also enabled synchronized servo movements between multiple servos. The results were great.

<br>
<p float="left">
<img src="https://user-images.githubusercontent.com/33403525/213960881-4f0b0fce-f70b-44d2-99de-8437eaee53eb.gif" width="300" />
<img src="https://user-images.githubusercontent.com/33403525/213961897-21ea64d1-c5cc-484b-9ba8-0b2fe51a2b31.gif" width="300" />
<img src="https://user-images.githubusercontent.com/33403525/213962433-ab8d1ffe-8784-49a4-92d6-033b27667f53.gif" width="300" />
</p>
<br>


