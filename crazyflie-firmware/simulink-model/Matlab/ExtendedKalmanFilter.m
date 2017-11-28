
function [xf, Pf] = ExtendedKalmanFilter(measurements,statePrior,priorCovariance,T,Q_gyro,R_acc,R_LPS,sensor_position,u_thrust)
%NONLINEARKALMANFILTER Filters measurement sequence Y using a 
% non-linear Kalman filter. 
% TODO Implement Zranger
%Input:
%   Y                       [m x 1] Measurement sequence for times 1,...,N
%   statePrior        [n x 1] Prior mean for time 0
%   priorCovariance    [n x n] Prior covariance
%   motionModel                     Motion model function handle
%
%Output:
%   xf          [n x 1]     Filtered estimates for times 1,...,N
%   Pf          [n x n ] Filter error convariance
%

[xp Pp]=predictionGyro(statePrior, measurements,priorCovariance, T,Q_gyro); %Prediction With Gyro
[xp Pp]=predictionLPS(xp, Pp, T,R_LPS,u_thrust);                                                %Prediction With LPS
[xf Pf]=updateAcc(xp, measurements, Pp, T,R_acc);                                                 % Update With accelerometer
[xf Pf]=updateLPS(xf, measurements, sensor_position, Pf, T,R_LPS);                    % Update With LPS


end

