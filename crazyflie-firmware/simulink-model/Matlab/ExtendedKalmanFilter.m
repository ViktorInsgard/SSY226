
function [xf, Pf] = ExtendedKalmanFilter(measurements, statePrior, priorCovariance)
%NONLINEARKALMANFILTER Filters measurement sequence Y using a 
% non-linear Kalman filter. 

%Input:
%   Y                       [m x N] Measurement sequence for times 1,...,N
%   statePrior        [n x 1] Prior mean for time 0
%   priorCovariance    [n x n] Prior covariance
%   motionModel                     Motion model function handle
%
%Output:
%   xf          [n x N]     Filtered estimates for times 1,...,N
%   Pf          [n x n x N] Filter error convariance
%

% 
% N = size(Y,2);
% n = length(x_0);
% xf = zeros(n,N);
% Pf = zeros(n,n,N);
% xp = zeros(n,N+1);
% Pp = zeros(n,n,N+1);



[xp Pp]=predictionGyro(statePrior, priorCovariance, samplingTime,processNoise)  %Prediction With Gyro
[xp Pp]=predictionLPS(xp, Pp, samplingTime,processNoise)                                        %Prediction With LPS

%update ACC
%update LPS
%Update Zranger
    
xp(:,end)=[];
Pp(:,:,end)=[];
end

