function [x,P]= predictionLPS(x, P, T,Q,u_thrust)
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

F=[eye(3) T*eye(3); zeros(3) eye(3)];    % Constant velocity

x(7) = x(7) + T*x(10);
x(8) = x(8) + T*x(11);
x(9) = x(9) + T*x(12);

x(10) = x(10);% - sin(x(2))*T*u_thrust;
x(11) = x(11);% + cos(x(2))*sin(x(1))*T*u_thrust;
x(12) = x(12);% + cos(x(2))*cos(x(1))*T*u_thrust - 9.82*T;
 
P(7:12,7:12)=F*P(7:12,7:12)*F.'+Q(7:12,7:12);

end

