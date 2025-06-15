#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int left,int mid,int right){
    int n1 = (mid-left)+1, n2 = right - mid;
    int l[n1], R[n2];
    for(int i=0; i<n1; i++){
        l[i] = v[left+i]; 
    }
    for(int i=0; i<n2; i++){
        R[i] = v[mid+i+1];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        // Ascending
        if(l[i]<=R[j]){
            v[k] = l[i];
            k++; i++;
        }else{
            v[k] = R[j];
            k++; j++;
        }
    }
    while(i<n1){
        v[k] = l[i];
        k++; i++;
    }
    while(j<n2){
        v[k] = R[j];
        k++; j++;
    }
}

void merge_sort(vector<int> &v,int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        merge_sort(v,left,mid);
        merge_sort(v,mid+1,right);
        merge(v,left,mid,right);
    }

}

int main(){
    cout<<"Enter the number of elements: ";
    int n; cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<"The elements are: ";
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"After sorting: ";
    merge_sort(v,0,n);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
    cout<<"Sorting Algo: Merge Sort\nTime Complexity: O(n log(n))\nSpace Complexity: O(n)\n";
    return 0;
}