#include <stdlib.h>
#include <stdio.h>
#include "func.h"

const char RUS_BYTE = 92;
const char RUS_BYTE_E = 80;
const char RUS_BYTE_F = 96;
const char ISE = 69;

int PatternEq(int cCount, int simCounter, int* excerpt, int* pattern, int* alphabet) {
    for (int i = cCount - 1; i >= 0; --i) {
        printf("%d ", i + 1 + simCounter);
        int truePatern = pattern[(i + simCounter % cCount) % cCount];
        //printf("%d %d \n", truePatern, excerpt[i]);
        if (truePatern != excerpt[i]) {
            return alphabet[pattern[(cCount - 1 + simCounter % cCount) % cCount]];
        } 
    }
    return cCount;
}


int Rus(int c) {
    if (c == RUS_BYTE) {
        int rusAlf = 0;
        if (getchar() == -1) {
            return 0;
        }
        rusAlf = getchar();
        c = (int)getchar();
        if (rusAlf == ISE) {
            c += RUS_BYTE_E;
        }
        else {
            c += RUS_BYTE_F;
        }
        
    }
    return c;
}

