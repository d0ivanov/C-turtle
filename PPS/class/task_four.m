clear all
x = y = -2*pi : 0.2 : 2*pi;
[xx, yy] = meshgrid (x, y);
% z = 1./(xx.^2+ yy.^2) .* sin(xx.*yy);
% surf(xx, yy, z)

z = 1./(xx.^2+ yy.^2) .* cos(xx.*yy);
surf(xx, yy, z)
zlim([-1 1])
