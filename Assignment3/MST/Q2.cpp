#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;
        int maxCount = 0;
        for (int count : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                maxCount = 1;
            } else if (count == maxFreq) {
                maxCount++;
            }
        }

        int intervals = (maxFreq - 1) * (n + 1) + maxCount;

        return max(intervals, static_cast<int>(tasks.size()));
    }
};

int main() {
    string inputTasks;
    int n;

    cout << "Enter tasks (as a string, e.g., 'AACBB'): ";
    cin >> inputTasks;
    cout << "Enter cooling interval n: ";
    cin >> n;

    vector<char> tasks(inputTasks.begin(), inputTasks.end());

    Solution solution;

    int result = solution.leastInterval(tasks, n);
    cout << "Minimum CPU intervals required: " << result << endl;

    return 0;
}
