function [xf,Pf] = updateAcc(x,y, P, T, R)
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
      -cos(x(2))*sin(x(1)), -sin(x(2))*cos(x(1)), zeros(1,10)];
hx = [-sin(x(2));
      cos(x(2))*sin(x(1));
      cos(x(2))*cos(x(1))];

% Update step for accelerometer
Sk=Hx*P*Hx.' + R;                            % Innovation covariance
Kk=P(1:3,1:3)*Hx.'/Sk;                                 % The Kalman gain
vk=(y(1:3)-hx);                                 % The innovation
Ptemp=P(1:3,1:3)-Kk*Sk*Kk.';                               % Updated estimate covariance
xtemp=x+Kk*vk;                                    % Updated state estimate
 Pf=1;
 xf=1;


end

