#include<iostream>
#include<chrono>
using namespace std;
const int inf = 1e8;
int main(){
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<inf; i++){

    }
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(end-start);
    cout<<dur.count()<<endl;
    return 0;
}
