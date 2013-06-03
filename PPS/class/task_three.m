% y = x^3 + 8x^2 - 18x + 4
clear all
x = linspace(-11, 3);
pol = [1 8 -18 4];
pol_roots = roots(pol)
y = polyval(pol, x);
plot(x, y);
hold on
plot(x, zeros(size(x)));
hold on
plot(pol_roots(1), 0, 'gs', "markersize", 10)
hold on
plot(pol_roots(2), 0, 'gs', "markersize", 10)
hold on
plot(pol_roots(3), 0, 'gs', "markersize", 10)
