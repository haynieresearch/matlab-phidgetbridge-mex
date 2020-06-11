#include "mex.h"
#include <phidget22.h>
#include <stdio.h>

double output;

void onVoltageRatioChange(PhidgetVoltageRatioInputHandle ch, void * ctx, double voltageRatio) {
	output = voltageRatio;
}

void phidgetBridge() {
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
