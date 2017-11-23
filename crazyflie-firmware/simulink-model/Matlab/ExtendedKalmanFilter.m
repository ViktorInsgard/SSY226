
function [xf, Pf] = ExtendedKalmanFilter(measurements, statePrior, priorCovariance, motionModel, samplingTime, processNoise, sensorPosition, measurementModel, measurementNoise)
%NONLINEARKALMANFILTER Filters measurement sequence Y using a 
% non-linear Kalman filter. 

%Input:
%   Y                       [m x N] Measurement sequence for times 1,...,N
%   statePrior        [n x 1] Prior mean for time 0
%   priorCovariance    [n x n] Prior covariance
%   motionModel                     Motion model function handle
%   samplingTime                    Sampling time
%   stateCovariance         [n x n] Process noise covariance
%   sensorPosition          [n x N] Sensor position vector sequence
%   measurementModel                Measurement model function handle
%   measurementCovariance   [n x n] Measurement noise covariance
%
%Output:
%   xf          [n x N]     Filtered estimates for times 1,...,N
%   Pf          [n x n x N] Filter error convariance

%


N = size(Y,2);
n = length(x_0);
xf = zeros(n,N);
Pf = zeros(n,n,N);
xp = zeros(n,N+1);
Pp = zeros(n,n,N+1);
[xp Pp]=nonLinKFprediction(x_0, P_0, f, T, Q) ; %Constant velocity prediction
[xp Pp]=predictionGyro(xp, Pp, T, Q);                %Pred Gyro

for k=1:N;
    [xf(:,k) Pf(:,:,k)]=nonLinKFupdate(xp(:,k), Pp(:,:,k), Y(:,k), S(:,k), h, R);
    %update ACC
    %update LPS
    %Update Zranger
    %PRed Gyro
    [xp(:,k+1) Pp(:,:,k+1)]=nonLinKFprediction(xf(:,k),Pf(:,:,k),f,T,Q);
    
end
xp(:,end)=[];
Pp(:,:,end)=[];
end

