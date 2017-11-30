function [y] = simulateLPSoutput(quadPosition, nodePositions)

m = size(nodePositions,1);
y = zeros(m,1);

for i=1:m
    y(i) = norm(quadPosition - nodePositions(i,:)');
end

end