#include<iostream>
using namespace std;

void hanoi(int n, char source, char auxiliary, char destination){
    if(n==1){
        cout<<"Move disk 1 from "<<source<<" to "<<destination<<"\n";
        return;
    }
    hanoi(n-1,source,destination,auxiliary);
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<"\n";
    hanoi(n-1,auxiliary,source,destination);
}

int main(){
    int n = 5;
    hanoi(n,'A','B','C');
    return 0;
}
