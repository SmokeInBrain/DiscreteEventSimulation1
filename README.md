Discrete event simulation
=================================================

This code is based in the resolution of scheduling processor problem. Within which a list of queues is possessed, running processes, making I/O and ending processes. This program was made ​​in C++ for the course discrete event simulation.


Scheduling Problem Processor
------------------

Just type `make simulation` then run it with './bin/planningProcessor.run'. This will execute the default instance of the problem: input/input Example.text which is the default parameter of the simulation.

Setting parameter in the simulation
------------------

To set the parameters of the simulation must modified `input.txt` file that it is in the folder `input`. Each word corresponds to a parameter, which may have different attributes that flare out.

	`numproc [number]`: total number of process to simulate
	`algorithm` [type] [quantum]: scheduling algorithm.
		type: FCFS, STF and RR
		quantum (optional): only RR
	`interarrival` [type] [number1] [number 2]: interarrival distribution
		type: uniform, exponential
		example: uniforme 1 10, exponential 100
	`service` [type] [number1] [number2]: service tiem distribution processes
		type: uniform, exponential
	`RP` [type] [number1] [number2]: bursts of processor distribution
		type: constant, uniform, normal, exponential
		example: constant 5, normal 8, 16
	`RIO` [type] [number1] [number2]: bursts of I/O distribution
		type: constant, uniform

Run simulation with custom parameter
------------------

To run the program with the modified parameters, we need to do a `make runSimulation` and are ready to simulate!


Bug tracking
------------

1. This simulation isn't in real-time.

Limitation simulation
------------
1. It has infinite I/O.
2. It has a CPU.
3. It don't simulate the process as such.