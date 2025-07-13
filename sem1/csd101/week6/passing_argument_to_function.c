#include <stdio.h>

void modify(int x) {
    x *= 3;
    printf("a=%d, inside modify\n", x);
}

int main() {
    int a = 2;
    printf("a=%d, before calling\n", a);
    modify(a);
    printf("a=%d, after calling\n", a);

    return 0;
}
