/* Facts */
male(shyam). % means shyam is a male
male(ravi).
male(raj).
male(guru).
% code here

female(anita).
female(smita).
female(sudha).
%code here -2 

parent(guru , sudha). % means guru is a parent of sudha
parent(smita , sudha).
parent(ravi , smita).
parent(anita , smita).
parent(anita , raj).
parent(shyam , raj).
% code here -3


/* Rules start here */
father(X,Y):- parent(X,Y),male(X).
mother(X,Y):- parent(X,Y),female(X).
stepsibling(X,Y):- father(Z,X),father(Z,Y),mother(W,X), mother(V,Y),W\=V, X\=Y.
stepsibling(X,Y):- mother(Z,X),mother(Z,Y),father(W,X),father(V,Y),W\=V,X\=Y.
stepbrother(X,Y):- stepsibling(X,Y),male(X).
stepsister(X,Y):- stepsibling(X,Y),female(X).
grandparent(X,Z):-parent(X,Y),parent(Y,Z).
grandfather(X,Y):-grandparent(X,Y),male(X).
grandmother(X,Y):-grandparent(X,Y),female(X).
% code here -4

