#include<bits/stdc++.h>
using namespace std;

class Job {
public:
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool profitsComp(Job* &a, Job* &b) {

    if (a->profit == b->profit) {
        return a->deadline > b->deadline;
    }

    return a->profit > b->profit;
}

// TC: O(n*log(n) + n*min(n, maxx))
// AS: O(maxx)
// where maxx is the max deadline
pair<int, int> jobSequencing(vector<Job*> jobs) {

    sort(jobs.begin(), jobs.end(), profitsComp);
    
    int n = jobs.size();

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i]->deadline);
    }

    vector<int> slots(maxDeadline, -1);

    int jobsDone = 0, maxProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i]->deadline - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i]->id;
                jobsDone++;
                maxProfit += jobs[i]->profit;
                break;
            }
        }
    }

    return {jobsDone, maxProfit};
}

int main() {

    vector<Job*> jobs = {new Job(1, 2, 100),
                         new Job(2, 1, 19),
                         new Job(3, 2, 27),
                         new Job(4, 1, 25),
                         new Job(5, 1, 15)};

    pair<int, int> res = jobSequencing(jobs);
    cout << res.first << " " << res.second << endl;
}