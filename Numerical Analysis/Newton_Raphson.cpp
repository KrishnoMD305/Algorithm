#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

double f(double x){
    double res = x*x*x - 6*x*x + 11*x - 6;
    return res;
}
double df(double x){
    double r = 3*x*x - 12*x + 11;
    return r;
}

double NR(double x0){
    if(abs(f(x0)) < 0.000001){
        return x0;
    }
    double root=NAN;
    while(true){
        double xn = x0 - (f(x0)/df(x0));
        if(abs(xn-x0) < 0.000001){
            root = xn;
            break;
        }
        x0 = xn;
    }
    return root;
}

bool checkNew(vector<double> &roots, double r){
    if(roots.empty()){
        return false;
    }
    for(auto i : roots){
        if(abs(i-r)<0.000001){
            return true;
        }
    }
    return false;
}

int main(){
    vector<double> roots; 

    double min_value = 0;
    double max_value = 4;

    for(double i=min_value; i<=max_value; i+=0.5){
        double rr = NR(i);
        if(!isnan(rr)){
            if(!checkNew(roots,rr)){
                roots.push_back(rr);
            }
        }
    }

    for(double i : roots){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}
