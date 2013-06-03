x = y = linspace(0.2, 10, 100);
r = sqrt(x .^ 2 + y .^ 2);
[xx, yy] = meshgrid(x, y);
u = 1 ./ (r .^ 12) - 1 ./ (r .^ 6);
plot(r, u);
