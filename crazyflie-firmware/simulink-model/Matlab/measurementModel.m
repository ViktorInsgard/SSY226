    function [hx,Hx] = measurementModel(x,s)
%%x = [x, y, z, x_dot, y_dot, z_dot]<==== integrating twice,once the acc?
%Input:
%   x           [12 x 1] [n x 1] State vector
%   s           [6 x 3] Positions of the each lps sensor 6 sensors and 3 positions(x,y,z)
%Output:
%   hx          [12 x 1] [n x 1] measurement model evaluated at state x
%   Hx          [12 x 12] [n x n] measurement model Jacobian evaluated at state x
%


% in case x,y,z and their velocities are states:
R1 = sqrt((x(1)-s(1,1))^2+(x(2)-s(1,2))^2+(x(3)-s(1,3))^2);
R2 = sqrt((x(1)-s(2,1))^2+(x(2)-s(2,2))^2+(x(3)-s(2,3))^2);
R3 = sqrt((x(1)-s(3,1))^2+(x(2)-s(3,2))^2+(x(3)-s(3,3))^2);
R4 = sqrt((x(1)-s(4,1))^2+(x(2)-s(4,2))^2+(x(3)-s(4,3))^2);
R5 = sqrt((x(1)-s(5,1))^2+(x(2)-s(5,2))^2+(x(3)-s(5,3))^2);
R6 = sqrt((x(1)-s(6,1))^2+(x(2)-s(6,2))^2+(x(3)-s(6,3))^2);

%hx=[R1;R2;R3;R4;R5;R6]; %Include acc
hx=[R1;R2;R3;R4;R5;R6];

Hx=[(x(1)-s(1,1))/R1 (x(2)-s(1,2))/R1 (x(3)-s(1,3))/R1 ;
    (x(1)-s(2,1))/R2 (x(2)-s(2,2))/R2 (x(3)-s(2,3))/R2 ;
    (x(1)-s(3,1))/R3 (x(2)-s(3,2))/R3 (x(3)-s(3,3))/R3 ;
    (x(1)-s(4,1))/R4 (x(2)-s(4,2))/R4 (x(3)-s(4,3))/R4 ;
    (x(1)-s(5,1))/R5 (x(2)-s(5,2))/R5 (x(3)-s(5,3))/R5 ;
    (x(1)-s(6,1))/R6 (x(2)-s(6,2))/R6 (x(3)-s(6,3))/R6 ];
% 
% Hx=[(x(1)-s(1,1))/R1 (x(2)-s(1,2))/R1 (x(3)-s(1,3))/R1 ;
%     (x(1)-s(2,1))/R2 (x(2)-s(2,2))/R2 (x(3)-s(2,3))/R2 ;
%     (x(1)-s(3,1))/R3 (x(2)-s(3,2))/R3 (x(3)-s(3,3))/R3 ;
%     (x(1)-s(4,1))/R4 (x(2)-s(4,2))/R4 (x(3)-s(4,3))/R4 ;
%     (x(1)-s(5,1))/R5 (x(2)-s(5,2))/R5 (x(3)-s(5,3))/R5 ;
%     (x(1)-s(6,1))/R6 (x(2)-s(6,2))/R6 (x(3)-s(6,3))/R6 ];




end

