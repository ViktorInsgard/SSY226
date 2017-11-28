function [xf,Pf] = updateAcc(x,y, P, T, R_acc)
%
%Input:
%   y          [12 x 1] Prior mean
%   P           [12 x 12] Prior covariance
%   T           Sampling time
% Q
%Output:
%   x p          [12 x 1] predicted state mean
%   Pp           [12 x 12] predicted state covariance
%

% Measurement model, assuming the quadcopter is at rest (it is not)
Hx = [-cos(x(1)), zeros(1,11);
      cos(x(2))*cos(x(1)), -sin(x(2))*sin(x(1)), zeros(1,10);
      -cos(x(2))*sin(x(1)), -sin(x(2))*cos(x(1)), zeros(1,10);
      zeros(9,12)];    
hx = [-sin(x(2));
      cos(x(2))*sin(x(1));
      cos(x(2))*cos(x(1))];

% Update step for accelerometer
Sk=Hx(1:3,1:3)*P(1:3,1:3)*Hx(1:3,1:3).' + R_acc;                            % Innovation covariance
Kk=P(1:3,1:3)*Hx(1:3,1:3).'/Sk;                                 % The Kalman gain
vk=(y(1:3)-hx);                                 % The innovation
Ptemp=P(1:3,1:3)-Kk*Sk*Kk.';                               % Updated estimate covariance
xtemp=x(1:3)+Kk*vk;                                    % Updated state estimate
 
xf=[xtemp;x(4:12)];
P(1:3,1:3)=Ptemp;
Pf=P

end

