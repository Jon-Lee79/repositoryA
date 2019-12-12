#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<visa.h>

void main(in argc,char** )
{
	char inq[] = "*IDN?/n";
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;

	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];

	status = viOpenDefaultRM(&defaultRM);

if(status == VI_SUCCESS)
{
	status = viFindRsrc(defaultRM,"USB[0-9]::*INSTR",&resourceList,&num_inst,description);

	if(status == VI_SUCCESS)
	{
		viOpen(defaultRM, description, VI_NULL,VINULL,&scopeHandle);
	}

}
}