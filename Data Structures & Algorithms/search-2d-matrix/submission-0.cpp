class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size(), m = matrix.size();
        int up = 0, down = m-1;
        
        while(up < down){
            int mid = (up+down)/2;
            if (target == matrix[mid][n-1]){
                return true;
            } else if (target > matrix[mid][n-1]){
                up = mid+1;
            } else {
                down = mid;
            }
        }

        if (target == matrix[up][n-1]) return true;

        int l = 0, r = n-1;
        while(l < r){
            int mid = (l + r)/2;
            if (target == matrix[up][mid]) return true;
            else if (target > matrix[up][mid]) l = mid+1;
            else r = mid;
        }
        
        return matrix[up][l] == target ? true : false;
    }
};
