Box 101
Version 4.0
By Nick Bartos

For those of you that asked for it, here it is:  A Windows 95/98/NT version of Box 101.  I took a little less time in designing this one than I took designing the original Windows 3.1 version, so please e-mail me if you find any bugs or have any suggestions.  I didn't right a help file for this one, and I probably won't in the future because I don't have as much time as I used to.  So here's the basics:

Enter the parameters as follows:
Name:  name of the driver
Fs:  frequency resonance of the driver (hertz)
Qes:  electrical Q of the driver
Qms:  mechanical Q of the driver
Vas:  volume acoustic suspension (cubic feet)
You may be able to use liters for vas and vb, because the calculations use only a ratio of the two, but I have not tested this.
Xmax:  one way linear excursion of the driver (inches), note that some manufacturers will give you the total, which is twice this value.  Be careful.
Diam:  commercial diameter of driver (inches), like 8, 10, 12, 15...
Pe:  maximum RMS power handling (watts)

The reference efficiency will be calculated if you entered fs, qes, and vas
If you don't know the qts, just enter qes and qms, and it will be calculated automatically

Here is a brief description and requirements of the graph functions:
Relative Response:  fs, qts, vas
Calculates output at 1W/1M + or - the reference frequency
Comparative Response:  fs, qes, qts, vas
Calculates output at 1W/1M, taking into account the reference frequency
Maximum SPL:  fs, qes, qts, vas, xmax, diam, pe
Calculates maximum output (freeair), taking into account displacement limits and thermal limits, I don't have the equations for the displacement limit for a single-reflex bandpass (e-mail them to me!)
Port Velocity:  fs, qes, qts, vas, xmax, diam, pe
Calculates maximum port velocity, not available for bandpass
Power:  fs, qes, qts, vas, xmax, diam, pe
Calculates maximum input power, also power required to reach maximum spl, not available for bandpass

The Boxes:
Vb, vr, vf:  net volume of box (excluding speaker displacement and ports)
Nd:  number of drivers in box
Dv:  diameter of vent (port)
Lv:  length of vent
Nv:  number of vents
Qtc:  in sealed, total q of box, in bandpass, total q of sealed side of enclosure (vr)
Pm:  maximum amplifier power, this will be equally divided among multiple drivers in a single box.  This is especially useful when you are comparing two drivers in a maximum SPL configuration with (example) a pe of 250, and a pe of 500, when you are only have a 250W amp.

If you enter 0 for most of these parameters, the program will calculate them for you.  There is no explicit max flat calc, but you can accomplish this by inserting 0 for most of the parameters.
