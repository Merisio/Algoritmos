#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int resto_rec (int x, int y){
    if (y == 0)
        return -1;

    else if (x < y)
        return x;

    else if (x == 0)
        return 0;

    else if (x == y)
        return 0;

    else
        return resto_rec(x - y, y);
}

int main() {
    int n, i, num, den;

    scanf ("%d", &n);

    for (i = 0; i < n; i++){
        scanf ("%d %d", &num, &den);
        printf ("%d\n", resto_rec(num, den));
    }

    return 0;
}
