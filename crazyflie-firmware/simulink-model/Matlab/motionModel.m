function [f,F] = motionModel(x,T)
%x=[x, y, z, x_dot, y_dot, z_dot]
% TODO Implement zRanger and gyroscope
% x      [12 x 1] 
% f      [12 x 1]
% F      [12 x 12]

% phi, theta, psi, phidot, thetadot, psidot, x, y, z, xdot, ydot, zdot as states
%x(1)    phi        %
%x(2)    theta      %
%x(3)    psi        % Gyro data
%x(4)    phidot     %
%x(5)    thetadot   %
%x(6)    psidot     %
%x(7)    x                                                          %
%x(8)    y                                                          %
%x(9)    z <===== From zRange sensor / acc data?                    %Accdata
%x(10)   x velocity, xdot                                           %and zRange sensor
%x(11)   y velocity, ydot                                           %
%x(12)   z velocity, zdot <======= From zRange sensor / acc data?   %

%CV model
f=[ x(1);    %%%           %[ x(1)+x(4)*T;
    x(2);    %%%           %  x(2)+x(5)*T;
    x(3);    %%% From      %  x(3)+x(6)*T
    x(4)*T;  %%%  Gyr      %  x(4);
    x(5)*T;  %%%   Data    %  x(5);
    x(6)*T;  %%%           %  x(6);];
% Acc data to position and velocity:
    x(7);
    x(8);
    x(9);
    x(10);
    x(11);
    x(12)];

F=[ 1 0 0 T 0 0 0 0 0 0 0 0; %phi           %%%
    0 1 0 0 T 0 0 0 0 0 0 0; %theta         %%% gyr data
    0 0 1 0 0 T 0 0 0 0 0 0; %psi           %%%
         
    0 0 0 1 0 0 0 0 0 0 0 0; %phidot        %%%
    0 0 0 0 1 0 0 0 0 0 0 0; %thetadot      %%% gyr data
    0 0 0 0 0 1 0 0 0 0 0 0; %psidot        %%%
    
    0 0 0 0 0 0 1 0 0 T 0 0; %x - to be integrated   %%%
    0 0 0 0 0 0 0 1 0 0 T 0; %y - to be integrated   %%% Acc data
    0 0 0 0 0 0 0 0 1 0 0 T; %z - to be integrated   %%%
    
    0 0 0 0 0 0 0 0 0 1 0 0; %xdot - to be integrated   %%%
    0 0 0 0 0 0 0 0 0 0 1 0; %ydot - to be integrated   %%% Acc data
    0 0 0 0 0 0 0 0 0 0 0 1];%zdot - to be integrated  %%%
    
% Verify F matrix


end

