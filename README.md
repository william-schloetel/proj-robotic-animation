# Halloween Animatronic

My love of Halloween and my love of tinkering came together again last year. I was inspired to finally teach myself the basics of microcontrollers and breadboarding with a new project: a programable Halloween animatronic.

I've always been interested in creating an animation like this, but never knew where to start. I wanted to push myself with this project and build the mechanism to be fully programmable. I didn’t want to just attach a motor to an armature that would move the prop back and forth, or what not. I really wanted to make the prop as believable as possible.

I decided on building a 3-axis head mechanism. This would give me three directions of head movement: rotate, pan, and tilt. Each of those directions would be independently controllable. I constructed the mechanism using resources I found online.  Measuring, cutting, drilling, sanding—I took great care to construct the armature with precision; any discrepancies could result in unwanted movement.

Once the armature was complete, I attached servo motors in the appropriate positions.

<br>
<p float="left">
  <img src="https://user-images.githubusercontent.com/33403525/189650058-efb511c9-deda-443b-82d8-efe080e1daf1.jpeg" width="400" />
  <img src="https://user-images.githubusercontent.com/33403525/189651456-ae07a8db-1a69-45f2-83b6-5cad43c91a52.jpeg" width="400" />
</p>
<br>

Then began the programming and testing...

I opted to use an Arduino

https://user-images.githubusercontent.com/33403525/211177449-1a4bd954-7dec-45aa-9746-0b9d2ae49f10.mov

 Uno microcontroller. Its versatility and accessibility made it perfect for this project. With minimal overhead and a custom IDE, the Arduino Uno made setup and programming a breeze. 

Getting familiar with the Arduino gave me the confidence to begin exploring more advanced microcontrollers, like the Raspberry Pi. 

To generate servo motion that was fluid and believable, I made use of a fantastic <a href=“https://github.com/ArminJo/ServoEasing”>servo easing library</a> that allowed me to fine tune the servo motion. This library enabled synchronized servo movements between multiple servos using a clock timer. The results were great.

