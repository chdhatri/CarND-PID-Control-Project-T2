# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program - PID Controller

---
## Introduction
The purpose of this project was to drive the car arouund the track in the simulator, by building a PID controller and tune the "P(propotional)", "I(Integral)" and "D(differential)" parameters by applying the general processing flow as described in the lessons. The simulator provides cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle.

---

## Reflection
#### Describe the effect each of the P, I, D components had in your implementation.
* Proportional (P) : Steer the car propotional to the distance from the lane center which is Cross track Error (CTE). Below is the video with just P term. [Link to only P](https://youtu.be/9tAOb5RTEls)
* Differential (D) : With Just propotional control, car can start oveshooting once it reaches center line. To avoid this we use the differntial control. It helps in approaching the target trajectory smoothly by setting a properly tuned D parameter. Below is the video with just D term. [Link to only D](https://youtu.be/y5nkP6BXiCg)
* Integral (I) : Environmental factors and mechinaical behaviour of the car (bias) can effect the nominal behaviour of the car. This can be corrected by using Intergral Control which sums up all the CTE ever observed. It counteracts a bias in the CTE which prevents P-D to reach center. [Link to only I](https://youtu.be/l2BR_SKRhHs)

Fianl Video [Link to complete PID Video](https://youtu.be/i0qiKZ9lopY)

#### Describe how the final hyperparameters were chosen.
PID parameters were chosen manually by trial and error.As a first step I set the 3 parametrs to zero but the car seems to go out of track immediately. To fix this problem, I added the proportional parameter. Initially with the  P term the car seems to drive properly but eventually started to overshoot and went out of the track. To fix it, I added the differential term to overcome the overshooting. As the car drove in simulator and there was no bias in the simulator, the  integral part stayed as zero. As the car drove in the track, the parameters were tuned to minimize the average cross-track error on a single track lap. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

