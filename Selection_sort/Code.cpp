// Time Complexity: O (n^2)
/* Here, 1st we select a element as the smallest. Then we compare the next each element with the selected smallest. If the loop find another smallest then swap the element. */

void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int small = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[small]){
                small = j;
            }
        }
        swap(arr[i],arr[small]);
    }
}
