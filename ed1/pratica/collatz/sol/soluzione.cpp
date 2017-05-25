/**
 *  Soluzione di collatz.
 *
 *  Autore: Luca Versari
 *
 *  Descrizione: Banale.
 */
#include <stdio.h>
int main() {
#ifndef USE_STDIN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N;
    scanf("%d", &N);
    int cnt = 1;
    while (N != 1) {
        cnt++;
        N = (N%2) ? (3*N+1) : (N/2);
    }
    printf("%d\n", cnt);
    return 0;
}

