function [xp,Pp]= predictionLPS(x, P, T,Q)
% The prediction for x y z 
%Input:
%   x           [12 x 1] Prior mean
%   P           [12 x 12] Prior covariance
%   T                           Sampling time
%  Q            [12 x 12] Process noise
%Output:
%   x p          [12 x 1] predicted state mean
%   Pp           [12 x 12] predicted state covariance
%


F=[eye(3) T*eye(3); zeros(3) eye(3)];    %F

xtemp=F*x(7:12);
xp=[ xtemp; x(7:12)]; 
Ptemp=F*P(7:12,7:12)*F.'+Q(7:12,7:12);
P(7:12,7:12)=Ptemp;
Pp=P;


end

