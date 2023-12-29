class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, currlen = 0, size = s.size();
        if (size == 1) {
            return 1;
        }
        else if (size == 0) {
            return 0;
        }
        string sub = "";
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (find(sub, s[j])) {
                    
                    break;
                    //cout << "hit replica" << endl;
                }
                else {
                    sub += s[j];
                    //cout << "sub: " << sub << endl;
                    currlen++;
                }
            }
            if (currlen > maxlen) {
                maxlen = currlen;
            }
            currlen = 0;
            sub = "";
        }
        return maxlen;
    }

    bool find(string str, char f) {
        int i = 0;
        while (str[i] != '\0') {
            if (f == str[i]) {
                return true;
            }
            i++;
        }
        return false;
    }
};
