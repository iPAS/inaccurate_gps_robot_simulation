# Learning to Control a Robot with the GPS Inaccuracy via Simulation

This simulation is aimed at studying the inaccuracy of GPS equipped in robotic system.
The robot which reads the incorrect position will try to walk to each of provided target locations.
Its decision output is in the form of tuple -- the combination between the direction and the walking step.
The robot will walk to the target point-by-point until no destination left.


## Quick Start

* Pull the code.
* `make` 
* `make run`


## Unittest

* `make test`


## Output Example

```bash
--- Start the Simulation ---
Target:(0, 0) GPS:(0, 0) Err:0.00 Walk:_,0 

----------
Target:(10, 10)

>> GPS Drift:(-3, -1)
#1 Target:(10, 10) GPS:(-3, -1) Err:17.03 Walk:E,10 

>> GPS Drift:(3, 8)
#2 Target:(10, 10) GPS:(10, 7) Err:3.00 Walk:N,3 

----------
Target:(-50, 60)

>> GPS Drift:(0, 2)
#1 Target:(-50, 60) GPS:(10, 12) Err:76.84 Walk:W,10 

>> GPS Drift:(-6, 8)
#2 Target:(-50, 60) GPS:(-6, 20) Err:59.46 Walk:W,10 

>> GPS Drift:(-7, -1)
#3 Target:(-50, 60) GPS:(-23, 19) Err:49.09 Walk:N,10 

>> GPS Drift:(-10, -5)
#4 Target:(-50, 60) GPS:(-33, 24) Err:39.81 Walk:N,10 

>> GPS Drift:(2, -8)
#5 Target:(-50, 60) GPS:(-31, 26) Err:38.95 Walk:N,10 

>> GPS Drift:(-3, -7)
#6 Target:(-50, 60) GPS:(-34, 29) Err:34.89 Walk:N,10 

>> GPS Drift:(-3, -1)
#7 Target:(-50, 60) GPS:(-37, 38) Err:25.55 Walk:N,10 

>> GPS Drift:(-10, 2)
#8 Target:(-50, 60) GPS:(-47, 50) Err:10.44 Walk:N,10 

>> GPS Drift:(-7, -1)
#9 Target:(-50, 60) GPS:(-54, 59) Err:4.12 Walk:E,4 

----------
Target:(-20, -30)

>> GPS Drift:(-1, 7)
#1 Target:(-20, -30) GPS:(-51, 66) Err:100.88 Walk:S,10 

>> GPS Drift:(-10, 3)
#2 Target:(-20, -30) GPS:(-61, 59) Err:97.99 Walk:S,10 

>> GPS Drift:(9, 8)
#3 Target:(-20, -30) GPS:(-52, 57) Err:92.70 Walk:S,10 

>> GPS Drift:(6, 5)
#4 Target:(-20, -30) GPS:(-46, 52) Err:86.02 Walk:S,10 

>> GPS Drift:(7, -4)
#5 Target:(-20, -30) GPS:(-39, 38) Err:70.60 Walk:S,10 

>> GPS Drift:(2, -3)
#6 Target:(-20, -30) GPS:(-37, 25) Err:57.57 Walk:S,10 

>> GPS Drift:(0, 3)
#7 Target:(-20, -30) GPS:(-37, 18) Err:50.92 Walk:S,10 

>> GPS Drift:(9, -1)
#8 Target:(-20, -30) GPS:(-28, 7) Err:37.85 Walk:S,10 

>> GPS Drift:(9, -9)
#9 Target:(-20, -30) GPS:(-19, -12) Err:18.03 Walk:S,10 

>> GPS Drift:(-3, 2)
#10 Target:(-20, -30) GPS:(-22, -20) Err:10.20 Walk:S,10 

>> GPS Drift:(3, 6)
#11 Target:(-20, -30) GPS:(-19, -24) Err:6.08 Walk:S,6 

----------
Target:(20, -10)

>> GPS Drift:(-5, -5)
#1 Target:(20, -10) GPS:(-24, -35) Err:50.61 Walk:E,10 

>> GPS Drift:(-2, 1)
#2 Target:(20, -10) GPS:(-16, -34) Err:43.27 Walk:E,10 

>> GPS Drift:(4, 7)
#3 Target:(20, -10) GPS:(-2, -27) Err:27.80 Walk:E,10 

>> GPS Drift:(-9, 3)
#4 Target:(20, -10) GPS:(-1, -24) Err:25.24 Walk:E,10 

>> GPS Drift:(-2, -6)
#5 Target:(20, -10) GPS:(7, -30) Err:23.85 Walk:N,10 

>> GPS Drift:(-2, 0)
#6 Target:(20, -10) GPS:(5, -20) Err:18.03 Walk:E,10 

>> GPS Drift:(-6, 6)
#7 Target:(20, -10) GPS:(9, -14) Err:11.70 Walk:E,10 

>> GPS Drift:(0, -7)
#8 Target:(20, -10) GPS:(19, -21) Err:11.05 Walk:N,10 

>> GPS Drift:(-8, -4)
#9 Target:(20, -10) GPS:(11, -15) Err:10.30 Walk:E,9 

>> GPS Drift:(-1, -6)
#10 Target:(20, -10) GPS:(19, -21) Err:11.05 Walk:N,10 

>> GPS Drift:(-9, 3)
#11 Target:(20, -10) GPS:(10, -8) Err:10.20 Walk:E,10 

>> GPS Drift:(7, -2)
#12 Target:(20, -10) GPS:(27, -10) Err:7.00 Walk:W,7 
```


## Note

* https://stackoverflow.com/questions/2744181/how-to-call-c-function-from-c