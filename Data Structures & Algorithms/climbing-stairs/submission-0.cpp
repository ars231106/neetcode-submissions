class Solution {
public:
    int climbStairs(int n) {
        if (n==1){
            return 1;
        }

        int way1 = 1;
        int way2 = 2;
        int new_way;

        for(int i = 3; i<=n; i++){
            new_way = way1 + way2;
            way1 = way2;
            way2 = new_way;
        }

        return way2;
    }
};