#include <libgeom/geometry.h>

#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CTEST(figure, triangle_s){
    double r = 3;
    
    double result = C_S(r);
    
    double expected = 28.274334;


    ASSERT_DBL_NEAR_TOL(expected, result, 1e-3);
}

CTEST(figure, triangle_p){
    double r = 3;
    
    double result = C_P(r);
    
    double expected = 18.84955592153876;


    ASSERT_DBL_NEAR_TOL(expected, result, 1e-3);
}


