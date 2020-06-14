#include "mex.h"

#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#include "C:\Program Files\Phidgets\Phidget22\phidget22.h"
#else
#include <phidget22.h>
#endif

double output;

void onVoltageRatioChange(PhidgetVoltageRatioInputHandle ch, void * ctx, double voltageRatio) {
	output = voltageRatio;
}

int phidgetBridge() {
  PhidgetVoltageRatioInputHandle voltageRatioInput0;
	PhidgetVoltageRatioInput_create(&voltageRatioInput0);
	PhidgetVoltageRatioInput_setOnVoltageRatioChangeHandler(voltageRatioInput0, onVoltageRatioChange, NULL);
	Phidget_openWaitForAttachment((PhidgetHandle)voltageRatioInput0, 5000);
	Phidget_close((PhidgetHandle)voltageRatioInput0);
	PhidgetVoltageRatioInput_delete(&voltageRatioInput0);
}

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
  phidgetBridge();
  plhs[0] = mxCreateDoubleScalar(output);
}
