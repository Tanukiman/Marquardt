#include <iostream>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <functional>

double function(double x){
    return sin(0.7*x+0.4)*5+exp(cos(2*x+3));
}
void df(double x, std::function<double(double)> f, double dx, double& f3){
    f3 = ( f(x + dx) - f(x - dx) )/(2*dx);
}

int main() {
    double x = 3.4;
    double f0 = 0.7*cos(0.7*x+0.4)*5-2*sin(2*x+3)*exp(cos(2*x+3));

    double f3;
    df(x, function, FLT_EPSILON, f3);
    
    printf("中心差分 f3 = %f\n", f3);
    printf("正確な値 f0 = %f\n", f0);
}
