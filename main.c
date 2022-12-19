#include <stdlib.h>
#include <stdio.h>
#include "func.h"

int main() {
    int excerpt[16];
    int alphabet[256];
    int c;
    int cCount = 0;
    while ((c = getchar()) != '\n') {
        c = Rus(c);
        excerpt[cCount] = c;
        ++cCount;
    }
    for (int i = 0; i < 128; ++i) {
        alphabet[i] = cCount;
    }
    for (int i = cCount - 2; i >= 0; --i) {
        if (alphabet[excerpt[i]] == cCount) {
            alphabet[excerpt[i]] = cCount - i - 1;
        }
    }
    int* pattern = (int*)malloc(cCount * sizeof(int));
    for (int i = 0; i < cCount; ++i) {
        if ((c = getchar()) == EOF) {
            free(pattern);
            return 0;
        }
        c = Rus(c);
        pattern[i] = c;
    }
    int simCounter = 0;

    while ((c = getchar()) != EOF) {
        c = Rus(c);
        int movement = PatternEq(cCount, simCounter, excerpt, pattern, alphabet);
        pattern[simCounter % cCount] = c;
        ++simCounter;
        for (int i = 0; i < movement - 1; ++i) {
            if ((c = getchar()) == EOF) {
                free(pattern);
                return 0;
            }
            c = Rus(c);
            pattern[simCounter % cCount] = c;
            ++simCounter;
        }
    }
    PatternEq(cCount, simCounter, excerpt, pattern, alphabet);
    free(pattern);
    return 0;
}

