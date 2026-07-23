class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& str : strs) {
            // Stores "length#string" (e.g., 5#hello)
            encoded += to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.length()) {
            // 1. Find where the '#' is to extract the length
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i)); // Length of word
            i = j + 1; // Move pointer past '#'
            // 2. Read 'len' characters directly
            ans.push_back(s.substr(i, len));
            // 3. Jump pointer past the word
            i += len;
        }
        return ans;
    }
};