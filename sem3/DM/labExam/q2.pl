/*Set-B*/
name(arnab_mandal).
rollno(2310110428).

male(james).
male(arthur).
male(harry).
male(fred).
male(george).
male(albusSeverus).
male(jamesSirius).
male(ron).
male(hugo).

female(lily).
female(molly).
female(ginny).
female(angelina).
female(rose).
female(hermionie).

/*wife=(wifeName, husbandName)*/
wife(lily, james).
wife(molly, arthur).
wife(ginny, harry).
wife(angelina, george).
wife(hermionie, ron).

/*parents=(child, father, mother)*/
parents(harry, james, lily).
parents(ginny, arthur, molly).
parents(ron, arthur, molly).
parents(fred, arthur, molly).
parents(george, arthur, molly).
parents(albusSeverus, harry, ginny).
parents(jamesSirius, harry, ginny).
parents(rose, ron, hermionie).
parents(hugo, ron, hermionie).

/*sister(sisterName, brotherName)*/
sister(X, Y) :-
    female(X),           % X must be female
    parents(X, Father, Mother), % X and Y must have the same parents
    parents(Y, Father, Mother),
    X \= Y.              % X and Y must be different

/*maternalUncle(uncleName, maleOrFemale)*/
maternalUncle(X, Y) :-
    male(X),
    parents(Y, _, Mother),       % Y's mother
    parents(Mother, Grandfather, Grandmother),
    parents(X, Grandfather, Grandmother),
    X \= Mother.                 % X is not Y's mother


