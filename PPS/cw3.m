p = [1 -3 2];
r = roots(p);
x = linspace(-1, 3);
plot(x, polyval(p, x));
hold on;
plot(r, zeros(size(r)), "marker", "x", "markersize", 21, "color", "red", "linestyle", "none")
hold on;
plot(x, zeros(size(x)), '.', 'color', 'red');
