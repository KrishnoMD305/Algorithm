/* The Dutch National Flag Algorithm is an algorithm proposed by Edsger Dijkstra to sort an array containing three distinct types of elements efficiently. 
It is primarily used to solve the "3-way partitioning problem", where the goal is to arrange elements of an array into three categories. 

Suppose, the problem is given an array containing three types of elements (e.g., {0, 1, 2}), sort them in-place so that all instances 
of the first type come first, followed by the second type, and then the third type.*/
// Approach (Three-Pointer Technique): 
   /* The algorithm maintains three pointers:
        low: Marks the boundary for elements less than the pivot.
        mid: Traverses the array and processes elements.
        high: Marks the boundary for elements greater than the pivot. 
        
   1.If arr[mid] == 0, swap arr[mid] and arr[low], then increment both low and mid.
   2.If arr[mid] == 1, it is in the correct position, so just increment mid.
   3.If arr[mid] == 2, swap arr[mid] and arr[high], then decrement high (do not increment mid because the swapped element must be checked).*/

// Time Complexity: O(n) 
// Space Complexity: O(1)

void dutchNationalFlag(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            mid++;
        } 
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
