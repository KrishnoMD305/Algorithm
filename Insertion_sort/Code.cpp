void insertion_sort(int arr[], int n){
    for(int i=1; i<n; i++){
        int current = arr[i], previous = i-1;
        while(previous>=0 && arr[previous]>current){
            arr[previous+1] = arr[previous];
            previous--;
        }
        arr[previous+1] = current;
    }
}
