# MATLAB Phidget Wheatstone Bridge Function
For whatever reason Phidgets dropped MATLAB support with Phidget22. This is a s simple little C code that you can compile with MEX and use the Phidget drivers to get the result into MATLAB.

This really is just an example of what can be done to get Phidget data into MATLAB. You can use the (Code Samples)[https://www.phidgets.com/?view=code_samples&lang=C] provided by Phidgets to get an idea of what else you can do. Just make sure you (download)[https://www.phidgets.com/docs/Operating_System_Support] the drivers from Phidgets for your Operating System.

The command you will enter in MATLAB (after creating the symbolic link):
```
mex -R2018a -I"/Library/Frameworks/Phidget22.framework/Headers" -L. -lphidget phidgetBridge.c
```

You will notice that I am including the header library with the -I command, but getting the "-lphidget" part to work takes a bit more effort. On Mac (and Linux I suppose) you need to make a symbolic link to the Phidget framework.

It's really quite simple, but I am not sure (and unable to test) how this would work on Windows.
```
ln -s /Library/Frameworks/Phidget22.framework phidget.dylib
```

If anyone is able to test and get this working on Windows, please let me know and I will update the documentation.


![Screenshot of MATLAB PhidgetBridge](https://raw.githubusercontent.com/haynieresearch/matlab-phidgetbridge-mex/master/img/matlab_screenshot.png)
