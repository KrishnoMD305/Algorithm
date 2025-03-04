/* when we calculate middle the previous formula was middle = (start + end)/2
start and end are indexes which are integer numbers. In the worst case, the start and end can be INT_MAX. If it happens then start+end will case integer overflow.
For avoiding such a situation, we change the formula to mid = start + (end - start)/2. If start and end are equal to INT_MAX, then end - start will decrease the value which is storable
in INT limit. And also then next plus will also not cause overflow.       */


while(start <= end){
      int mid = start + (end - start)/2 ;
      if(arr[mid] < t){
          start = mid + 1;
      }else if(arr[mid] > t){
          end = mid - 1;
      }else{
          
          return mid;
      }
  }
return -1;
  
