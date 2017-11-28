% The noises and Constants
g=9.81729;

R_LPS=    [0.0020   -0.0001    0.0002   -0.0007   -0.0000   -0.0001;
   -0.0001    0.0007   -0.0003    0.0000   -0.0000   -0.0000;
    0.0002   -0.0003    0.0132    0.0001    0.0003   -0.0000;
   -0.0007    0.0000    0.0001    0.0012    0.0001    0.0000;
   -0.0000   -0.0000    0.0003    0.0001    0.0098    0.0002;
   -0.0001   -0.0000   -0.0000    0.0000    0.0002    0.0008];

R_acc=   1.0e-03 * [0.0665    0.0011    0.0118; 0.0011    0.0620    0.0021; 0.0118    0.0021    0.1846];
Q_gyro=1.0e-05 *[ 0.1086    0.0041   -0.0027; 0.0041    0.1041   -0.0016; -0.0027   -0.0016    0.0999];
T=0.02;