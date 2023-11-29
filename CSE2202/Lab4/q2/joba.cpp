#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int profit;
    int deadline;
};

bool compareJobs(const Job &a, const Job &b)
{
    return a.profit > b.profit;
}

void jobSequence(int n, vector<int> profits, vector<int> deadlines)
{
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i)
    {
        jobs[i].profit = profits[i];
        jobs[i].deadline = deadlines[i];
    }
    sort(jobs.begin(), jobs.end(), compareJobs);
    vector<bool> slot(n, false);
    vector<int> result(n);
    int totalProfit = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; --j)
        {
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    cout << "Optimal solution: Job ";
    for (int i = 0; i < n; ++i)
    {
        if (slot[i])
            cout << result[i] + 1 << "--> ";
    }
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main()
{
    ifstream inputFile("jobsequence.txt");
    int n;
    while (inputFile >> n)
    {
        vector<int> profits(n);
        vector<int> deadlines(n);
        for (int i = 0; i < n; ++i)
            inputFile >> profits[i];
        for (int i = 0; i < n; ++i)
            inputFile >> deadlines[i];
        jobSequence(n, profits, deadlines);
    }
    inputFile.close();
}
