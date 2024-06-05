#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int maxMeetings(vector<pair<int, int>>& meetings) {
    sort(meetings.begin(), meetings.end(), compare);

    int count = 1;
    int end = meetings[0].second;

    for (int i = 1; i < meetings.size(); ++i) {
        if (meetings[i].first >= end) {
            count++;
            end = meetings[i].second;
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> meetings;
    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        meetings.push_back({start, end});
    }

    int result = maxMeetings(meetings);
    
    cout << result << endl;

    return 0;
}