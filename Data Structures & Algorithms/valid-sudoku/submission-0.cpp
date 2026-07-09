class Solution {
public:
    bool issafe(vector<vector<char>>& board, int i, int j, int digit){
        for(int k = 0; k<9; k++){
            if(board[i][k] == digit){
                return false;
            }
        }

        for(int l = 0; l<9; l++){
            if(board[l][j] == digit){
                return false;
            }
        }

        int sr = (i/3) * 3;
        int sc = (j/3) * 3;

        for(int m = sr; m < sr + 3; m++){
            for(int n = sc; n < sc + 3; n++){
                if(board[m][n] == digit){
                    return false;
                }
            }
        }

        return true;
    }
    

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    continue;
                }

                char digit = board[i][j];
                board[i][j] = '.';

                if(!issafe(board, i, j, digit)){
                    board[i][j] = digit;
                    return false;
                }
                board[i][j] = digit;
            }
        }

        return true;
    }
};
