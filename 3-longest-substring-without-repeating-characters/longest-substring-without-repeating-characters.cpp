class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maximumLength = 0;
        unordered_set<char> character;
        int left = 0;
        for (int right =0; right<n;right++){
            if(character.count(s[right]) == 0){
                character.insert(s[right]);
                maximumLength = max(maximumLength, right-left+1);
            }else{
                while(character.count(s[right])){
                    character.erase(s[left]);
                    left++;
                }
                character.insert(s[right]);
            }
        }
        return maximumLength;
    }
};