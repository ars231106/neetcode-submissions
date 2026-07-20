class Solution {
public:
    vector<string> ans;

    void solve(int n, int openused, int opennotclosed, string &curr){
        if(curr.size() == 2 * n){
            ans.push_back(curr);
            return;
        }

        if(openused < n){
            curr.push_back('(');
            solve(n, openused + 1, opennotclosed + 1, curr);
            curr.pop_back();
        }

        if(opennotclosed > 0){
            curr.push_back(')');
            solve(n, openused, opennotclosed - 1, curr);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr;
        solve(n, 0, 0, curr);
        return ans;
    }
};