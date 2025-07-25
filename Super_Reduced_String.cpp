#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    string reduced_s = "";

    for (char c : s) {
        if (!reduced_s.empty() && reduced_s.back() == c) {
            reduced_s.pop_back();
        } else {
            reduced_s.push_back(c);
        }
    }

    if (reduced_s.empty()) {
        return "Empty String";
    } else {
        return reduced_s;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
