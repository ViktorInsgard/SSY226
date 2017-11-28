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
R_x = [1 0 0; 0 cos(measurement(1)) -sin(measurement(1)); 0 sin(measurement(1)) cos(measurement(1))]; %Rotation matrix, Roll 
R_y = [cos(measurement(2)) 0 sin(measurement(2)); 0 1 0; -sin(measurement(2)) 0 cos(measurement(2))]; %Rotation matrix, Pitch
R_z = [cos(measurement(3)) -sin(measurement(3)) 0; sin(measurement(3)) cos(measurement(3)) 0; 0 0 1]; %Rotation matrix, Yaw
R = R_x*R_y*R_z;

F=[eye(3) T*R; zeros(3) eye(3)];    %Constant velocity
     

%Kalman prediction
xtemp=F*x(1:6);
xp=[ xtemp; x(7:12)]; 
Ptemp=F*P(1:6,1:6)*F.'+Q(1:6,1:6);
P(1:6,1:6)=Ptemp;
Pp=P;




end

