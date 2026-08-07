class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(s, 0, curr);
        return res;
    }

    void dfs(const string& s, int start, vector<string>& curr) {
        if (start == s.length()) {
            res.push_back(curr);
            return;
        }
        for(int i=start;i<s.size();i++){
            if (isPalindrome(s, start, i)) {
                curr.push_back(s.substr(start, i - start + 1));//end-start+1
                dfs(s, i + 1, curr); 
                curr.pop_back();    
            }
        }
    }

    bool isPalindrome(const string & s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
