#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// REF : https://leetcode.com/problems/task-scheduler/
// NOTES :
//      MaxHeap to keep the count of the each element.
//      Queue to cycle through the different elements which stores
//      (count, idle time) idle time means when this element can be
//      scheduled for job. Whose idle time matches with the current time,
//      pop that element from the Queue and put it in MaxHeap.
//      Take out from Queue ---> Put into MaxHeap

// T: O(n * c * log 26) ~ O(n)
// S: O(1), bcz Queue and maxHeap size can go upto 26 distinct elements

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;
        for (auto &ch : tasks)
            freq[ch]++;

        priority_queue<int> maxHeap;
        for (auto &i : freq)
            maxHeap.push(i.second);

        deque<pair<int, int>> q;
        int time = 0;
        
        while ( (!maxHeap.empty()) || (!q.empty()) ) {
            time++;
            if (!maxHeap.empty()) {

                int cnt = maxHeap.top(); maxHeap.pop();

                cnt--;          // It's not python, we can have MaxHeap
                if (cnt != 0)
                    q.push_back(make_pair(cnt, time + n));

            }

            if ( (!q.empty()) && (q.front().second == time) ) {
                int new_freq = q.front().first; q.pop_front();
                maxHeap.push(new_freq);
            }
        }
        return time;
    }
};

class Solution2 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (auto &i : tasks)
            freq[i]++;

        priority_queue<int> maxHeap;
        for (auto &i : freq)
            maxHeap.push(i.second);

        int time = 0;
        queue<pair<int, int>> q;
        
        while ((!maxHeap.empty()) || (!q.empty())) {
            time++;
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top(); maxHeap.pop();
                cnt--;

                if (cnt)
                    q.push({cnt, time + n});
            }

            if ((!q.empty()) && (q.front().second == time)) {
                int new_freq = q.front().first; q.pop();
                maxHeap.push(new_freq);
            }
        }
        return time;
    }
};

int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << "output : " << Solution().leastInterval(tasks, n) << endl;
    return 0;
}