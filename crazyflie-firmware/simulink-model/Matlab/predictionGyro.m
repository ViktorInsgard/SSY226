function [xp,Pp] = predictionGyro(x, measurement,P, T,Q)
%
%Input:
%   x           [12 x 1] Prior mean
% omega     [3 x 1] Gyro measurements
%   P           [12 x 12] Prior covariance
%   T           Sampling time
% Q
%Output:
%   x p          [12 x 1] predicted state mean
%   Pp           [12 x 12] predicted state covariance
%

F=[eye(3) T*eye(3); zeros(3) eye(3)];    %Constant velocity
     

%Kalman prediction
xtemp=[x(1:3) + T*measurement(1:3); measurement(1:3)];
xp=[ xtemp; x(7:12)]; 
Ptemp=F*P(1:6,1:6)*F.'+Q(1:6,1:6);
P(1:6,1:6)=Ptemp;
Pp=P;




end

