ViSession scopeHandle;
ViSession FGHandle;


viFindRsrs(defaultRM,"USB[0-9]::0x0699?*INSTR",....., description);
viOpen(defaultRM, description, ....., &scopeHandle);

viFindRsrs(defaultRM,"USB[0-9]::0x1AB1?*INSTR",....., description);
viOpen(defaultRM, description, ....., &FGHandle);

viWrite(scopeHandle, "*IDN?/n",6,....);

viWrite(FGHandle,"*IDN?/n",6,....);