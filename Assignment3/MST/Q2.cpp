#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char task : tasks)
            freq[task - 'A']++;
        int maxFreq = 0, maxCount = 0;
        for (int count : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                maxCount = 1;
            }else if (count == maxFreq)
                maxCount++;
        }
        int intervals=(maxFreq-1)*(n+1)+maxCount;
        return max(intervals, static_cast<int>(tasks.size()));
    }

int main() {
    FAST;
    string inputTasks;
    int n;
    cout<<"Enter tasks (AACBB): ";
    cin>>inputTasks;
    cout<<"Enter interval n: ";
    cin>>n;
    vector<char> tasks(inputTasks.begin(), inputTasks.end());
    int result = leastInterval(tasks, n);
    cout<<"Minimum CPU intervals required: "<<result<<endl;

    return 0;
}
