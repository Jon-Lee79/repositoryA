#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include <string.h>
  
ViStatus set_voltage(ViSession handle, float volts)
{
	ViUInt32 resultCount;
	ViStatus status;
	char command[36];
	sprintf(command, "CH1:SCALE %E\n",volts);
	status = viWrite(handle,command,strlen(command),&resultCount);
	return status;

}   

ViStatus get_curve(ViSession handle, char * dataBuffer, int npoints)
{
       ViUInt32 resultCount;
       ViStatus status;

       char command[250];
       sprintf(command, "DATA:START 1\n");
       status = viWrite(handle,command,strlen(command),&resultCount);
       sprintf(command, "DATA:STOP %d\n", npoints);
       status = viWrite(handle,command,strlen(command),&resultCount);

       viWrite(handle,"CURV?\n",6,&resultCount);
	   status = viRead(handle,dataBuffer,npoints,&resultCount);
	   return status;
}

void main(int argc, char** argv)
{

	unsigned char resultBuffer[256];
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];
	float convertedValues[2500];

	int y; 
	float conversion;
	float target_volts = 5;
	float volts;

	float Amplitude;
	float max = -127;
	float min = 128;


	int lsb;
	int msb;

	status = viOpenDefaultRM(&defaultRM);


	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR",	&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&scopeHandle);

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);

				viWrite(scopeHandle,"DAT:SOU CH1\n",12,&resultCount);
			/*	viRead(scopeHandle,resultBuffer,256,&resultCount);

				printf("DATA SOURCE = %s",resultBuffer);*/

				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer);
                set_voltage(scopeHandle,target_volts);
				get_curve(scopeHandle, dataBuffer,2500);

				viWrite(scopeHandle,"CH1:SCA?\n",9,&resultCount);
				char ret[36];
				ret[8] = '\0';
				viRead(scopeHandle,ret,36,&resultCount);

				sscanf(ret,"%f",&volts);
				
				volts = atof(ret);
				conversion = volts*10.0/256; 

				printf("ret = %s Volts = %f Conversion factor = %f",ret,volts,conversion);

				for(int i = 0; i<128; i++)
				{
					y = dataBuffer[i];
					convertedValues[i] = y*conversion;

					if (max < convertedValues[i])
					{
						max=convertedValues[i];
					}

					if (min > convertedValues[i])
					{
						min=convertedValues[i];
					}

					Amplitude = (max-min)/2;

					//printf("\nRaw = %x,  Read = %d, Converted = %f",y,y,convertedValues[i]);
					printf("Converted = %f\n", convertedValues[i]);
					printf("Amplitude = %f\n", Amplitude);
			
				}

			}
			else
			{
				printf("\nFailed to open %s",description);
			}
		}
		else
		{
			printf("\nCouldn't find any instruments");
		}
	}
	else
	{
		printf("\nFailed to open defaultRM");
	}
}