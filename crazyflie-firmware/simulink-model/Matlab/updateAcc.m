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

Hx = 
hx =

% Update step for accelerometer
Sk=Hx*P*Hx.' + R;                            % Innovation covariance
Kk=P(1:3,1:3)*Hx.'/Sk;                                 % The Kalman gain
vk=(y(1:3)-hx);                                 % The innovation
Ptemp=P(1:3,1:3)-Kk*Sk*Kk.';                               % Updated estimate covariance
xtemp=x+Kk*vk;                                    % Updated state estimate
 Pf=1;
 xf=1;


end

