/* The Array or data structure need to be sorted. 
   1. Find the middle. middle = (start + end)/2
   2. If target > middle then start = middle + 1   middle = (start + end)/2
      If target < middle then end = middle -1     middle = (start + end)/2
      If target = middle then return middle
   3. Repeat this untill a valid answer is found or else return -1.  */

// Time Complexity: O (log n) 

int start = 0;
int end = arr.size() -1 ;
    
while(start <= end){
    int mid = (start + end)/2;
    if(arr[mid] < t){
        start = mid + 1;
    }else if(arr[mid] > t){
        end = mid - 1;
    }else{
        return mid;
    }
}
return -1;
