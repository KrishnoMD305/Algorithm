#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// ============= PERMUTATIONS =============

// Method 1: STL next_permutation (Most Optimized)
void findPermutationsSTL(vector<int>& arr) {
    cout << "\n=== Permutations using STL next_permutation ===\n";
    sort(arr.begin(), arr.end()); // Important: sort first
    
    do {
        for(int x : arr) cout << x << " ";
        cout << "\n";
    } while(next_permutation(arr.begin(), arr.end()));
}

// Method 2: Recursive Backtracking (Optimized)
void permuteRecursive(vector<int>& arr, int start, vector<vector<int>>& result) {
    if(start == arr.size()) {
        result.push_back(arr);
        return;
    }
    
    for(int i = start; i < arr.size(); i++) {
        swap(arr[start], arr[i]);
        permuteRecursive(arr, start + 1, result);
        swap(arr[start], arr[i]); // backtrack
    }
}

void findPermutationsRecursive(vector<int> arr) {
    cout << "\n=== Permutations using Recursive Backtracking ===\n";
    vector<vector<int>> result;
    permuteRecursive(arr, 0, result);
    
    for(auto& perm : result) {
        for(int x : perm) cout << x << " ";
        cout << "\n";
    }
}

// Method 3: Brute Force using Recursion with visited array
void permuteBruteForce(vector<int>& arr, vector<bool>& visited, 
                      vector<int>& current, vector<vector<int>>& result) {
    if(current.size() == arr.size()) {
        result.push_back(current);
        return;
    }
    
    for(int i = 0; i < arr.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            current.push_back(arr[i]);
            permuteBruteForce(arr, visited, current, result);
            current.pop_back(); // backtrack
            visited[i] = false;
        }
    }
}

void findPermutationsBruteForce(vector<int> arr) {
    cout << "\n=== Permutations using Brute Force ===\n";
    vector<vector<int>> result;
    vector<bool> visited(arr.size(), false);
    vector<int> current;
    
    permuteBruteForce(arr, visited, current, result);
    
    for(auto& perm : result) {
        for(int x : perm) cout << x << " ";
        cout << "\n";
    }
}

// ============= COMBINATIONS =============

// Method 1: Recursive Backtracking (Optimized)
void combineRecursive(vector<int>& arr, int start, int k, 
                     vector<int>& current, vector<vector<int>>& result) {
    if(current.size() == k) {
        result.push_back(current);
        return;
    }
    
    // Optimization: pruning - if we can't form k elements, return
    if(current.size() + (arr.size() - start) < k) return;
    
    for(int i = start; i < arr.size(); i++) {
        current.push_back(arr[i]);
        combineRecursive(arr, i + 1, k, current, result);
        current.pop_back(); // backtrack
    }
}

void findCombinations(vector<int> arr, int k) {
    cout << "\n=== Combinations of size " << k << " using Recursion ===\n";
    vector<vector<int>> result;
    vector<int> current;
    
    combineRecursive(arr, 0, k, current, result);
    
    for(auto& comb : result) {
        for(int x : comb) cout << x << " ";
        cout << "\n";
    }
}

// Method 2: Iterative using bitmask (Good for small arrays)
void findCombinationsBitmask(vector<int> arr, int k) {
    cout << "\n=== Combinations of size " << k << " using Bitmask ===\n";
    int n = arr.size();
    
    // Generate all possible bitmasks
    for(int mask = 0; mask < (1 << n); mask++) {
        if(__builtin_popcount(mask) == k) { // count set bits
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    cout << arr[i] << " ";
                }
            }
            cout << "\n";
        }
    }
}

// Method 3: All combinations (all possible subsets) - Power Set
void findAllCombinations(vector<int> arr) {
    cout << "\n=== All Combinations (Power Set) ===\n";
    int n = arr.size();
    
    for(int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                cout << arr[i] << " ";
            }
        }
        cout << "}\n";
    }
}

// Method 4: Brute Force Combinations using nested loops (for fixed k)
void findCombinationsBruteForce(vector<int> arr) {
    cout << "\n=== Combinations of size 3 using Brute Force (Triple nested loops) ===\n";
    int n = arr.size();
    
    // Example for combinations of size 3
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
            }
        }
    }
}

// Method 5: STL for combinations using next_permutation on boolean array
void findCombinationsSTL(vector<int> arr, int k) {
    cout << "\n=== Combinations of size " << k << " using STL ===\n";
    int n = arr.size();
    vector<bool> selector(n, false);
    
    // Set first k elements to true
    fill(selector.begin(), selector.begin() + k, true);
    
    do {
        for(int i = 0; i < n; i++) {
            if(selector[i]) {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    } while(prev_permutation(selector.begin(), selector.end()));
}

// ============= ADVANCED METHODS =============

// Heap's Algorithm for Permutations (Very Efficient)
void heapPermute(vector<int>& arr, int size, vector<vector<int>>& result) {
    if(size == 1) {
        result.push_back(arr);
        return;
    }
    
    for(int i = 0; i < size; i++) {
        heapPermute(arr, size - 1, result);
        
        if(size % 2 == 1) {
            swap(arr[0], arr[size - 1]);
        } else {
            swap(arr[i], arr[size - 1]);
        }
    }
}

void findPermutationsHeap(vector<int> arr) {
    cout << "\n=== Permutations using Heap's Algorithm ===\n";
    vector<vector<int>> result;
    heapPermute(arr, arr.size(), result);
    
    for(auto& perm : result) {
        for(int x : perm) cout << x << " ";
        cout << "\n";
    }
}

// For arrays with duplicates - unique permutations
void findUniquePermutations(vector<int> arr) {
    cout << "\n=== Unique Permutations (handling duplicates) ===\n";
    sort(arr.begin(), arr.end());
    set<vector<int>> uniquePerms;
    
    do {
        uniquePerms.insert(arr);
    } while(next_permutation(arr.begin(), arr.end()));
    
    for(auto& perm : uniquePerms) {
        for(int x : perm) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    
    cout << "Original Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\n";
    
    // PERMUTATIONS
    findPermutationsSTL(arr);           // Most optimized
    findPermutationsRecursive(arr);     // Good balance
    findPermutationsBruteForce(arr);    // Brute force
    findPermutationsHeap(arr);          // Heap's algorithm
    
    // COMBINATIONS
    findCombinations(arr, 2);           // Optimized recursive
    findCombinationsBitmask(arr, 2);    // Bitmask method
    findCombinationsSTL(arr, 2);        // STL method
    findAllCombinations(arr);           // Power set
    findCombinationsBruteForce(arr);    // Brute force
    
    // HANDLING DUPLICATES
    vector<int> arrWithDups = {1, 2, 2, 3};
    findUniquePermutations(arrWithDups);
    
    return 0;
}

/*
COMPLEXITY ANALYSIS:

PERMUTATIONS:
1. STL next_permutation: O(n! × n) time, O(1) extra space
2. Recursive backtracking: O(n! × n) time, O(n) space
3. Brute force with visited: O(n! × n) time, O(n) space
4. Heap's algorithm: O(n!) time, O(n) space

COMBINATIONS:
1. Recursive: O(C(n,k) × k) time, O(k) space
2. Bitmask: O(2^n × n) time, O(1) extra space
3. STL: O(C(n,k) × n) time, O(n) space
4. Brute force nested loops: O(n^k) time, O(1) space

RECOMMENDATIONS:
- For permutations: Use STL next_permutation (most optimized)
- For combinations: Use recursive backtracking with pruning
- For small arrays: Bitmask method works well
- For duplicates: Sort first and use set or proper duplicate handling

OPTIMIZATION TECHNIQUES:
1. Pruning in recursive calls
2. Early termination conditions
3. In-place swapping instead of creating new arrays
4. Using iterative methods when possible
5. Proper handling of duplicates to avoid redundant work
*/