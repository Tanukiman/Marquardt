#include <stdio.h>
#include <math.h>
#include <float.h>

double f(double x){
    return sin(0.7*x+0.4)*5+exp(cos(2*x+3));
}

int main() {
    double x, x1, x2, dx, f0, f1, f2, f3;

    x=3.0; 
    
    dx = FLT_EPSILON;
    x1 = x - dx;
    x2 = x + dx;

    f1 = ( f(x2) - f(x) )/dx;
    f2 = ( f(x) - f(x1) )/dx;
    f3 = ( f(x2) - f(x1) )/(2*dx);
    f0 = 0.7*cos(0.7*x+0.4)*5-2*sin(2*x+3)*exp(cos(2*x+3));

    printf("前進差分 f1 = %f\n", f1);
    printf("後退差分 f2 = %f\n", f2);
    printf("中心差分 f3 = %f\n", f3);
    printf("正確な値 f0 = %f\n", f0);
}
