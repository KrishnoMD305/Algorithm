#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top=0,bot=matrix.size()-1,l=0,r=matrix[0].size()-1;
        while(top<=bot && l<=r){
            for(int i=l; i<=r; i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top; i<=bot; i++){
                result.push_back(matrix[i][r]);
            }
            r--;
            if(top<=bot){
                for(int i=r; i>=l; i--){
                    result.push_back(matrix[bot][i]);
                }
                bot--;
            }
            if(l<=r){
                for(int i=bot; i>=top; i--){
                    result.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return result;
    }

int main(){
    
    return 0;
}