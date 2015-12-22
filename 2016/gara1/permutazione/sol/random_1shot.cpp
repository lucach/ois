#include <cstdio>
#include <cassert>
#include <algorithm>

void permuta(int K, char* P) {
    for (int i=0; i<26; i++) {
        P[i] = 'A' + i;
    }

    std::random_shuffle(P, P+26);
}


int main() {
    FILE *fr, *fw;
    int K;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &K));

    char P[27];
    permuta(K, P);
    P[26] = '\0';

    fprintf(fw, "%s\n", P);
    fclose(fr);
    fclose(fw);
    return 0;
}
