#include<bits/stdc++.h>
using namespace std;
const double E = 0.001;
double fun(int a,int b,int c,int d,int e,double x){
    double result = a*x*x*x*x + b*x*x*x + c*x*x + d*x + e;
    return result;
}

double xmax(int a,int b,int c){
    double re = sqrt((b/a)*(b/a) - 2.0*(c/a));
    return re;
}

double bisection(double a, double b, double c, double d, double e,double left, double right,int &cnt){
    while ((right - left) > E){
        double mid = (left + right) / 2.0;
        if (fun(a, b, c, d, e, left) * fun(a, b, c, d, e, mid) <= 0){
            right = mid;
        }else{
            left = mid;
        }
        cnt += 1;
    }
    return (left + right) / 2.0;
}

int main(){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;

    double xx = xmax(a,b,c);
    double x1 = -xx;
    double x2 = xx;
    double step = 0.05;
    for(double i=x1+step; i<=x2; i+=step){
        double f1 = fun(a,b,c,d,e,x1);
        double f2 = fun(a,b,c,d,e,i);
        if(f1*f2 < 0){
            int cnt=0;
            double r = bisection(a,b,c,d,e,x1,i,cnt);
            cout<<"First root : "<<r<<endl;
            cout<<"Search interval = ["<<x1<<", "<<i<<"]";
            cout<<"Iteration needed = "<<cnt<<endl;
        }
        x1 = i;
    }

    return 0;
}
