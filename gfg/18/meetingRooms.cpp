#include<bits/stdc++.h>
using namespace std;

// return true -> if you want a before b
// return false -> if you want b before a
bool customComp(pair<int, char> &a, pair<int, char> &b) {

    if (a.first == b.first) {
        // if (a.second == 's') {
        //     return true;
        // } else {
        //     return false;
        // }
        return a.second == 's';
    }

    // if (a.first < b.first) {
    //     return true;
    // } else {
    //     return false;
    // }
    return a.first < b.first;   
}

// TC: O(n*log(n))
// AS: O(n)
int numberOfMeetingRooms(vector<vector<int>> meetings) {

    // pair -> {int, char} -> {time, 's' or 'e'}
    vector<pair<int, char>> timeline;

    int n = meetings.size();
    for (int i = 0; i < n; i++) {
        timeline.push_back({meetings[i][0], 's'});
        timeline.push_back({meetings[i][1], 'e'});
    }

    sort(timeline.begin(), timeline.end(), customComp);

    for (int i = 0; i < timeline.size(); i++) {
        cout << timeline[i].first << " " << timeline[i].second << endl;
    }

    int currentMeetings = 0, result = 0;
    for (int i = 0; i < 2*n; i++) {
        if (timeline[i].second == 's') {
            currentMeetings++;
        } else {
            currentMeetings--;
        }

        result = max(result, currentMeetings);
    }

    return result;
}

int numberOfMeetingRoomsWithoutCustomComp(vector<vector<int>> meetings) {

    vector<pair<int, int>> timeline;

    int n = meetings.size();
    for (int i = 0; i < n; i++) {
        timeline.push_back({meetings[i][0], -1});
        timeline.push_back({meetings[i][1], +1});
    }

    sort(timeline.begin(), timeline.end());

    int currentMeetings = 0, result = 0;
    for (int i = 0; i < 2*n; i++) {
        if (timeline[i].second == -1) {
            currentMeetings++;
        } else {
            currentMeetings--;
        }

        result = max(result, currentMeetings);
    }

    return result;
}

int main() {

    // cout << numberOfMeetingRooms({{0, 30},
    //                               {5, 10},
    //                               {15, 20}}) << endl;

    cout << numberOfMeetingRoomsWithoutCustomComp({{1, 18},
                                  {18, 23},
                                  {15, 29},
                                  {4, 15},
                                  {2, 11},
                                  {5, 13}}) << endl;

    cout << numberOfMeetingRooms({{1, 18},
                                  {18, 23},
                                  {15, 29},
                                  {4, 15},
                                  {2, 11},
                                  {5, 13}}) << endl;
}