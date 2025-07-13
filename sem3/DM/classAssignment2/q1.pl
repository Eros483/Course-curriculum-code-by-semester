% Towers of Hanoi implementation in Prolog

% move/3 predicate to display the move
move(From, To) :-
    write('Move disk from '),
    write(From),
    write(' to '),
    write(To),
    nl.

% toh/4 predicate to solve the Towers of Hanoi problem
toh(0, _, _, _) :- !.
toh(N, Source, Target, Auxiliary) :-
    N > 0,
    M is N - 1,
    toh(M, Source, Auxiliary, Target),
    move(Source, Target),
    toh(M, Auxiliary, Target, Source).

% Example query to solve for 3 disks
% ?- toh(3, 'A', 'C', 'B').

% time complexity for the solution will be O(2^n)