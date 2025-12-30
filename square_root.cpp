#include<iostream>

double sqrt(int a){
    double low=0, high=a;
    double mid;
    double precision = 0.000001;

    while((high-low) > precision){
        mid = (high+low)/2;
        if(mid*mid < a){
            low = mid;
        }else{
            high = mid;
        }
    }
    return (low+high)/2;
}



double sqrt(double a){
    double low=0, high=a;
    double mid;
    double precision = 0.000001;

    while((high-low) > precision){
        mid = (high+low)/2;
        if(mid*mid < a){
            low = mid;
        }else{
            high = mid;
        }
    }
    return (low+high)/2;
}

double sqrt(int a, int precision){
    int intPart = sqrt(a);
    double ans = intPart;
    double step = 0.1;
    for(int i=0; i<precision; i++){
        while((ans+step)*(ans+step) <= a){
            ans += step;
        }
        step /= 10;
    }
    return ans;
}

int main(){
    return 0;
}