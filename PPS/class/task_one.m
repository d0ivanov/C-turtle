% y = -5x^2 + 8x + 4
% 1) roots
% 2) graph -> x
% 3) roots on graph

x = linspace(-0.6, 2.2);
pol = [-5 8 4];
pol_roots = roots(pol)
y = polyval(pol, x);
plot(x, y);
hold on
plot(x, zeros(size(x)));
hold on
plot(pol_roots(1), 0, 'gs', "markersize", 10)
hold on
plot(pol_roots(2), 0, 'gs', "markersize", 10)
