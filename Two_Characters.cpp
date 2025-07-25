#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) {
    int max_len = 0;
    
    // 1. Get all unique characters from the string
    set<char> unique_chars_set(s.begin(), s.end());
    vector<char> unique_chars(unique_chars_set.begin(), unique_chars_set.end());
    
    // If there are less than 2 unique characters, no alternating string can be formed
    if (unique_chars.size() < 2) {
        return 0;
    }

    // 2. Iterate through all possible pairs of unique characters
    for (size_t i = 0; i < unique_chars.size(); ++i) {
        for (size_t j = i + 1; j < unique_chars.size(); ++j) {
            char char1 = unique_chars[i];
            char char2 = unique_chars[j];
            
            string current_t = "";
            
            // 3. Build a temporary string using only char1 and char2
            for (char c : s) {
                if (c == char1 || c == char2) {
                    current_t += c;
                }
            }
            
            // 4. Validate if current_t is an alternating string
            bool is_alternating = true;
            if (current_t.length() > 1) {
                for (size_t k = 0; k < current_t.length() - 1; ++k) {
                    if (current_t[k] == current_t[k+1]) {
                        is_alternating = false;
                        break;
                    }
                }
            } else if (current_t.length() <= 1) { // A string of length 0 or 1 is considered alternating
                is_alternating = true; 
            }
            
            // 5. Update max_len if valid and longer
            if (is_alternating) {
                max_len = max(max_len, (int)current_t.length());
            }
        }
    }
    
    return max_len;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
