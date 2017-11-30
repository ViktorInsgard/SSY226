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

x(1)=x(1)+T*measurement(1);
x(2)=x(2)+T*measurement(2);
x(3)=x(3)+T*measurement(3);
x(4)=measurement(1);
x(5)=measurement(2);
x(6)=measurement(3);
P(1:6,1:6)=F*P(1:6,1:6)*F.'+Q(1:6,1:6);





end

