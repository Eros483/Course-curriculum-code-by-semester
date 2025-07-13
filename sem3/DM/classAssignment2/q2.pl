% Define natural numbers
natural_number(0).
natural_number(s(X)) :- natural_number(X).

% Define addition
plus(0, X, X) :- natural_number(X).
plus(s(X), Y, s(Z)) :- plus(X, Y, Z).

% Define multiplication as repeated addition
mult(0, _, 0).
mult(s(X), Y, Z) :- mult(X, Y, W), plus(W, Y, Z).

% Define exponentiation as repeated multiplication
exp(_, 0, s(0)).
exp(X, s(Y), Z) :- exp(X, Y, W), mult(X, W, Z).