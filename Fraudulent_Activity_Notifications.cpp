#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int getMedian(const vector<int>& count, int d) {
    int sum = 0;
    if (d % 2 == 1) { // Odd case
        int median_idx = d / 2 + 1;
        for (int i = 0; i < 201; ++i) {
            sum += count[i];
            if (sum >= median_idx) return i;
        }
    } else { // Even case
        int first = -1, second = -1;
        int median_idx1 = d / 2;
        int median_idx2 = d / 2 + 1;
        for (int i = 0; i < 201; ++i) {
            sum += count[i];
            if (sum >= median_idx1 && first == -1) first = i;
            if (sum >= median_idx2) {
                second = i;
                break;
            }
        }
        return first + second;
    }
    return 0;
}

int activityNotifications(vector<int> expenditure, int d) {
    vector<int> count(201, 0);
    int notifications = 0;

    // Initialize count array with the first d days
    for (int i = 0; i < d; ++i) {
        count[expenditure[i]]++;
    }

    for (int i = d; i < expenditure.size(); ++i) {
        int median = getMedian(count, d);
        if (expenditure[i] >= (d % 2 == 0 ? median : median * 2)) {
            notifications++;
        }

        // Update the count array for next window
        count[expenditure[i - d]]--;
        count[expenditure[i]]++;
    }

    return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
