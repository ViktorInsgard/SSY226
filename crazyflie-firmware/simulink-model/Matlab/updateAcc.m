function [xf,Pf] = updateAcc(x,y, P, T, R_acc)
%
%Input:
%  x           [12 x 1]    States
%   y          [12 x 1]    Measurement
%   P          [12 x 12] Covariance
%   T          [1 x 1]    Sampling time
%  R_acc   [3 x 3]    Measurement noise
%Output:
%   x p          [12 x 1] predicted state mean
%   Pp           [12 x 12] predicted state covariance
%

% Measurement model, assuming the quadcopter is at rest (it is not)

Hx = [0, -cos(x(2)),0;
      cos(x(2))*cos(x(1)), -sin(x(2))*sin(x(1)), 0;
      -cos(x(2))*sin(x(1)), -sin(x(2))*cos(x(1)), 0];    
  
hx = [-sin(x(2));
           cos(x(2))*sin(x(1));
           cos(x(2))*cos(x(1))];

% Update step for accelerometer
Sk=Hx*P(1:3,1:3)*Hx.' + R_acc;                           % Innovation covariance
Kk=P(1:3,1:3)*Hx.'/Sk;                                           % The Kalman gain
vk=(y(4:6)-hx);                                                           % The innovation
Ptemp=P(1:3,1:3)-Kk*Sk*Kk.';                               % Updated estimate covariance
xtemp=x(1:3)+Kk*vk;                                              % Updated state estimate
 
xf=[xtemp;x(4:12)];
P(1:3,1:3)=Ptemp;
Pf=P

end

