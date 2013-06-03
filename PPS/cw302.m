x = y = linspace(-360, 360, 26);
[xx, yy] = meshgrid (x, y);
z = sin(xx .* yy);
surf(xx, yy, z);
