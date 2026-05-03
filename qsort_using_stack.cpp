#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int partition(int arr[],int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void Qsort(int arr[], int n){
    stack<pair<int,int>> st;
    st.push({0,n-1});

    while(!st.empty()){
        int low = st.top().first;
        int high = st.top().second;
        st.pop();
        int pivotIndex = partition(arr,low,high);
        if(low < high){
            if(pivotIndex-1 > low){
                st.push({low,pivotIndex-1});
            }
            if(pivotIndex+1 < high){
                st.push({pivotIndex+1,high});
            }
        }
    }
}

int main(){
    int arr[] = {5,3,2,6,1,4};
    int n = sizeof(arr)/sizeof(int);
    Qsort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
