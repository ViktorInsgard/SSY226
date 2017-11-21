function [xp,Pp] = predictionGyro(x, P, T,Q)
%
%Input:
%   x           [12 x 1] Prior mean
%   P           [12 x 12] Prior covariance
%   T           Sampling time
% Q
%Output:
%   x p          [12 x 1] predicted state mean
%   Pp           [12 x 12] predicted state covariance
%
R_x = [1 0 0; 0 cos(x(4)) -sin(x(4)); 0 sin(x(4)) cos(x(4))]; %Rotation matrix, Roll 
R_y = [cos(x(5)) 0 sin(x(5)); 0 1 0; -sin(x(5)) 0 cos(x(5))]; %Rotation matrix, Pitch
R_z = [cos(x(6)) -sin(x(6)) 0; sin(x(6)) cos(x(6)) 0; 0 0 1]; %Rotation matrix, Yaw
R = R_x*R_y*R_z;

F=eye(3)+0.5*T*R;    %F
G=T*0.5*x(4:6);       %f           

%Kalman prediction
xtemp=F*x(4:6);
xp=[x(1:3); xtemp; x(7:12)];
Ptemp=F*P(4:6,4:6)*F.'+G.'*Q(4:6,4:6)*G;
P(4:6,4:6)=Ptemp;
Pp=P;




end

