% 2D graph of sin(x+y) * cos(x-y)
% -2Pi : 2Pi

x = y = -2*pi : 0.2 : 2*pi;
[xx, yy] = meshgrid (x, y);
z = sin(xx + yy) .* cos(xx-yy);
surf(xx, yy, z);
