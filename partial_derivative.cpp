#include <iostream>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <functional>
#include <vector>

using namespace std;

double func(vector<double> x){
    return 2*x[0]*x[0]*x[1]+exp(x[2]+3);
}

double df(std::function<double(vector<double>)> f, vector<double> x, int xi){
    if(x.size() <= xi){
        std::cout << "Error: xi is too large." <<std::endl;
        exit;
    }
    double dx = FLT_EPSILON;
    vector<double> tasu_dx = x;
    vector<double> hiku_dx = x;
    tasu_dx[xi]+=dx;
    hiku_dx[xi]-=dx;        
    return ( f(tasu_dx) - f(hiku_dx) )/(2*dx);
}

int main() {
    int N=3;
    vector<double> x(N);
    x[0]=1.4;
    x[1]=2.0;
    x[2]=3.0;

    double f0 = exp(x[2]+3);

    double f3;
    f3 = df(func, x, 2);

    printf("中心差分 f3 = %f\n", f3);
    printf("正確な値 f0 = %f\n", f0);
}
