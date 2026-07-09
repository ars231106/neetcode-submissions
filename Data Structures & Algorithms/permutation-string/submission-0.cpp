class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char, int> freq;
       int left = 0;

       for(char c : s1){
           freq[c]++;
       }

       unordered_map<char, int> window;

       for(int right = 0; right < s2.length(); right++){
           window[s2[right]]++;

           // cond_1 : if current window length > string s1 length
           if (right - left + 1 > s1.length()){
               window[s2[left]]--;

               if(window[s2[left]] == 0){
                   window.erase(s2[left]);
               }

               left++;
           }
           
           //cond_1 : if current window length = string s1 length
           if (right - left + 1 == s1.length()){
               /*cond_2 : if freq of chars within the window match the freq of chars
                          within in s1
               */
               if(freq == window){
                  return true;
               }
           }
       }
       return false; 
    }
};
