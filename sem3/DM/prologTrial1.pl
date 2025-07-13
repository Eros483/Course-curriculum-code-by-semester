girl(shreya).
girl(shringarika).
girl(pankhuri).
girl(vasundhara).
girl(shruti).
girl(vanshika).

boy(arnab).
boy(suryansh).
boy(anish).
boy(shresth).
boy(yash).

love(shreya, arnab).
love(shreya, arnab) :- happy(arnab).

crush(shruti, shresth).
crush(vasundhara, anish).
crush(vanshika, yash).

friend(shreya, pankhuri).
friend(anish, shresth).
friend(arnab, suryansh).

annoyed(arnab) :- friend(shreya, pankhuri).


