class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(int i = 0; i < strs.size(); i++) {
            int count = strs[i].length();
            encoded_string += to_string(count) + "#" + strs[i];
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while(i < s.length()) {
            int j = i;

            while(s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, length);
            ans.push_back(word);

            i = j + 1 + length;
        }

        return ans;
    }
};