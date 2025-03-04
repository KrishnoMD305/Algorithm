/* In the loop, if the size is n, then the following is happenning---
n ---->  n/2  ---->  n/4  ---->  n/8  ---->   n/16  --- ---- ---- ---- ----   1
So we can write it - 
n/2^0  --->  n/2^1  --->  n/2^2  --->  n/2^3  --->   --- --- --- --- -----  n/2^k
So the operation is going to k. 
Time Complexity: O(k)  
n/2^k = 1 
=> n = 2^k
=> k = log(2) n 
Time Complexity: O(log n) */
