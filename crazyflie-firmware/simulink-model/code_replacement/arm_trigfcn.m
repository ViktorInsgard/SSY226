function hLib = arm_trigfcn


hLib = RTW.TflTable;
%---------- entry: cos ----------- 
hEnt = createCRLEntry(hLib, ...
    'double y1 = cos( double u1 )', ...
    'double y1 = arm_cos_f32( double u1 )');
hEnt.setTflCFunctionEntryParameters( ...
          'Priority', 100, ...
          'ImplementationHeaderFile', 'arm_math.h');

hEnt.EntryInfo.Algorithm = 'RTW_UNSPECIFIED';


hLib.addEntry( hEnt ); 

%---------- entry: sin ----------- 
hEnt = createCRLEntry(hLib, ...
    'double y1 = sin( double u1 )', ...
    'double y1 = arm_sin_f32( double u1 )');
hEnt.setTflCFunctionEntryParameters( ...
          'Priority', 100, ...
          'ImplementationHeaderFile', 'arm_math.h');

hEnt.EntryInfo.Algorithm = 'RTW_UNSPECIFIED';


hLib.addEntry( hEnt ); 

