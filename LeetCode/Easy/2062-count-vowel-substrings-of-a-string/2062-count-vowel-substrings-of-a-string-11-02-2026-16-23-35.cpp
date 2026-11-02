class Solution {
private:
    bool isvalid(string& str, int i, int j) {
        while (i <= j) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u') {
                i++;
            } else
                return false;
        }
        return true;
    }

public:
    int countVowelSubstrings(string word) {

        int n = word.size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            int vowel = 0;
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                if (word[j] == 'a')
                    st.insert(word[j]);
                if (word[j] == 'e')
                    st.insert(word[j]);
                if (word[j] == 'i')
                    st.insert(word[j]);
                if (word[j] == 'o')
                    st.insert(word[j]);
                if (word[j] == 'u')
                    st.insert(word[j]);

                if (st.size() == 5 && isvalid(word, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};