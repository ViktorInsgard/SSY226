% Setup figure
fig = figure(1);
quad = generateQuad([1 0 0]);
p = plot3(quad(1,:), quad(2,:), quad(3,:));
grid on; 
axis([-5 5 -5 5 -5 5]);

% Create timer object
t = timer;
global index;
index = 1;

% Set timer callback functions
t.StartFcn = @(~, thisEvent)updatePlot(simout, p, fig);
t.TimerFcn = @(~, thisEvent)updatePlot(simout, p, fig);
t.StopFcn = @(~, thisEvent)updatePlot(simout, p, fig);

% Set timer settings and then start timer
t.Period = T;
t.TasksToExecute = length(simout.Time);
t.executionMode = 'fixedRate';
start(t);


% Update plot function
function [] = updatePlot(source, p, fig)
    global index;

    data = source.data(index,:)';
    index = index + 1;
    
    newQuad = generateQuad(data(4:6)') + data(1:3);
    p.XData = newQuad(1,:);
    p.YData = newQuad(2,:);
    p.ZData = newQuad(3,:);
    
    refresh(fig)
end


% Generate rotated 3D-representation of a quadcopter
function [coords] = generateQuad(angle)
    armLength = 0.05;
    rotorRadius = 0.02;

    l = linspace(0, 2*pi, 20); 
    circleCoords = rotorRadius*[cos(l); sin(l); zeros(1,20)];
    
    d = armLength/sqrt(2);
    coords = [circleCoords + [ d;  d; 0], [NaN; NaN; NaN] ...
              circleCoords + [-d;  d; 0], [NaN; NaN; NaN] ...
              circleCoords + [-d; -d; 0], [NaN; NaN; NaN] ...
              circleCoords + [ d; -d; 0], [NaN; NaN; NaN] ...
              [d; d; 0], [-d; -d; 0], [NaN; NaN; NaN], ...
              [d; -d; 0], [-d; d; 0]];

    R = eul2rotm(angle, 'XYZ');

    for i=1:size(coords,2)
        coords(:,i) = R*coords(:,i);
    end
end