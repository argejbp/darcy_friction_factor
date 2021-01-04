# darcy_friction_factor
C++ code to calculate Pipe friction factor (Darcy - Weisbach)

The program works with the Coolebrok Equation, which must be iterate until reach the right friction factor value
A function with the Haaland equation is also provided, but not included in the calculations

The variables are:

- Volumetric Flowrate (m^3/s) or Fluid Velocity (m/s)
- Inner diameter of the pipe (mm)
- Kinematic Viscocity (m^2/s) of the fluid
- Pipe's material 

In function of the pipe's material, a relative rugosity will be chosen (From Çengel Fluid Mechanics Fundamentals and Applications)
