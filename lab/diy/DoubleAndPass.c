#include "Getter.h"
#include "Poster.h"
#include "DoubleAndPass.h"

void DoubleAndPass() {

    int v = GetNumber();
    int d = v * 2;
    if ( ((v >= 0) && (d >= v)) ||
         ((v <= 0) && (d <= v))  ) {
        PostNumber(d);
    }
}
