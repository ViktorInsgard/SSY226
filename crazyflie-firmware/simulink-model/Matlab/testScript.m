% Testscript
x=ones(12,1);
P=ones(12);
u_thrust=0;

%%
[x P]=predictionLPS(x, P, T,Q,u_thrust);