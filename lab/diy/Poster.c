#include "Poster.h"

void PostNumber(int number) {

    /* The way PostNumber ACTUALLY works internally doesn't matter when we're testing DoubleAndPass.
       In fact, it's better that we DON'T rely on our knowledge of how PostNumber works internally
       when testing DoubleAndPass because that would make our test more brittle. When we're
       testing DoubleAndPass, this "real" PostNumber function isn't compiled or linked at all. Instead,
       we compile and link the Mock version of PostNumber, which serves to verify everything is working
       properly. Just to prove this file isn't considered at all when testing DoubleAndPass, we'll put
       and error here:
       */
#error "This is the REAL version of Poster and should not be linked during out test of DoubleAndPass"
}
