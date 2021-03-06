#include <bits/stdc++.h>

const int MAXK = 1000000;
long long p10[MAXK + 1];
long long dp[MAXK + 1];

int L;

long long con(int);

long long senza(int K) {
    return p10[K] - con(K);
}

long long con(int K) {
    if (K < L)
        return 0;

    long long &ans = dp[K];

    if (ans != -1)
        return ans;
    else
        ans = 0;

    for (int i = 0; i <= K - L; i++) {
        ans += senza(i) * senza(K - L - i);
    }

    return ans;
}

long long conteggio(int K, char S[]) {
    p10[0] = 1;
    for (int i = 1; i <= K; i++) {
        p10[i] = p10[i - 1] * 10;
    }

    L = strlen(S);
    memset(dp, -1, sizeof dp);
    return con(K);
}


#define MAXS 100
char S[MAXS + 2];

int main() {
    FILE *fr, *fw;
    int K;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d\n", &K));
    assert(NULL != fgets(S, sizeof S, fr));
    S[strlen(S) - 1] = '\0';

    fprintf(fw, "%lld\n", conteggio(K, S));
    fclose(fr);
    fclose(fw);
    return 0;
}
