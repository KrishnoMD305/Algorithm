// Square matrix

//Principle diagonal
int sum = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==j){
                sum += mat[i][j];
            }
        }
    }

// Sub diagonal
for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(j==row-i-1){
                sum += mat[i][j];
            }
        }
    }
