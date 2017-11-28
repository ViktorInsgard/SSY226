function [xp,Pp]= predictionLPS(x, u_thrust, P, T,Q)
% The prediction for x y z 
%Input:
%   x            [12 x 1] Prior mean
%   u_thrust     Total amount of thrust
%   P            [12 x 12] Prior covariance
%   T            Sampling time
%   Q            [12 x 12] Process noise
%Output:
%   x p          [12 x 1] predicted state mean
%   Pp           [12 x 12] predicted state covariance
%
R_x = [1 0 0; 0 cos(x(4)) -sin(x(4)); 0 sin(x(4)) cos(x(4))]; %Rotation matrix, Roll 
R_y = [cos(x(5)) 0 sin(x(5)); 0 1 0; -sin(x(5)) 0 cos(x(5))]; %Rotation matrix, Pitch
R_z = [cos(x(6)) -sin(x(6)) 0; sin(x(6)) cos(x(6)) 0; 0 0 1]; %Rotation matrix, Yaw
R = R_x*R_y*R_z;

F=[eye(3) T*eye(3); zeros(3) eye(3)];    % Constant velocity

xtemp=F*x(7:12) + [0; 0; 0; R*[0; 0; u_thrust]] - [0; 0; 0; 0; 0; -9.82];
xp=[ xtemp; x(7:12)]; 
Ptemp=F*P(7:12,7:12)*F.'+Q(7:12,7:12);
P(7:12,7:12)=Ptemp;
Pp=P;


end

