#include "stdio.h"


void foo(void) {
    a = a + 1; // acessa variavel global
}

void main(void) {
    int a = 0;
    int b = 0;
    while (b < 2) {
        foo();
        
        if (a < 5) {
            b = 1;
        }
    }
}
