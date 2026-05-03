#include<iostream>
#include<stack>
using namespace std;

struct Frame{
    int n;
    int state;
    int res;
};

int fib(int n){
    stack<Frame> ss;
    int last = 0;
    ss.push({n,0,0});
    while(!ss.empty()){
        Frame &f = ss.top();

        if(f.n<=1){
            last = f.n;
            ss.pop();
        }else if(f.state==0){
            f.state = 1;
            ss.push({f.n-1,0,0});
        }else if(f.state==1){
            f.res = last;
            f.state = 2;
            ss.push({f.n-2,0,0});
        }else{
            last = f.res + last;
            ss.pop();
        }
    }
    return last;
}

int main(){
    int n;
    cout<<"Enter the last sequence: ";
    cin>>n;
    cout<<"\n\nThe fibonacchi sequence is : ";
    for(int i=1; i<=n; i++){
        int f = fib(i);
        cout<<f<<" ";
    }
    cout<<"\n\nFinished\n\n";
    return 0;
}
