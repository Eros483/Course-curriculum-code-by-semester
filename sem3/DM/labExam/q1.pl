/*Set-B*/
/*1, 1, 2, 3, 5*/
name(arnab_mandal).
rollno(2310110428).

fibonacci(0, 0). % Base case: F(0) = 0
fibonacci(1, 1). % Base case: F(1) = 1

fibonacci(N, Result) :-
    N > 1, 
    N1 is N - 1,
    N2 is N - 2,
    fibonacci(N1, Result1), % Recursive call for F(N-1)
    fibonacci(N2, Result2), % Recursive call for F(N-2)
    Result is Result1 + Result2. 
