function [xf,Pf] = updateLPS(x,y, P, T,R)
% The update for x y z 
%Input:
%   x           [12 x 1] Prior mean
%   P           [12 x 12] Prior covariance
%  T                           Sampling time
%  R            [6 x 6] Measurement noise
%Output:
%   x f          [12 x 1] Updated state mean
%   Pf           [12 x 12] Updated state covariance
%


R1 = sqrt((x(1)-s(1,1))^2+(x(2)-s(1,2))^2+(x(3)-s(1,3))^2);
R2 = sqrt((x(1)-s(2,1))^2+(x(2)-s(2,2))^2+(x(3)-s(2,3))^2);
R3 = sqrt((x(1)-s(3,1))^2+(x(2)-s(3,2))^2+(x(3)-s(3,3))^2);
R4 = sqrt((x(1)-s(4,1))^2+(x(2)-s(4,2))^2+(x(3)-s(4,3))^2);
R5 = sqrt((x(1)-s(5,1))^2+(x(2)-s(5,2))^2+(x(3)-s(5,3))^2);
R6 = sqrt((x(1)-s(6,1))^2+(x(2)-s(6,2))^2+(x(3)-s(6,3))^2);

hx=[R1;R2;R3;R4;R5;R6];

Hx=[(x(1)-s(1,1))/R1 (x(2)-s(1,2))/R1 (x(3)-s(1,3))/R1 ;
    (x(1)-s(2,1))/R2 (x(2)-s(2,2))/R2 (x(3)-s(2,3))/R2 ;
    (x(1)-s(3,1))/R3 (x(2)-s(3,2))/R3 (x(3)-s(3,3))/R3 ;
    (x(1)-s(4,1))/R4 (x(2)-s(4,2))/R4 (x(3)-s(4,3))/R4 ;
    (x(1)-s(5,1))/R5 (x(2)-s(5,2))/R5 (x(3)-s(5,3))/R5 ;
    (x(1)-s(6,1))/R6 (x(2)-s(6,2))/R6 (x(3)-s(6,3))/R6 ];

Sk=Hx*P(7:9,7:9)*Hx.' + R;                            % Innovation covariance
Kk=P(7:9,7:9)*Hx.'/Sk;                                 % The Kalman gain
vk=(y(7:9)-hx);                                 % The innovation
Ptemp=P(7:9,7:9)-Kk*Sk*Kk.';                               % Updated estimate covariance
xtemp=x+Kk*vk;                                    % Updated state estimate
 Pf=1;
 xf=1;






end

