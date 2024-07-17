#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

std::pair<int, int> JobScheduling(std::vector<Job>& jobs, int n) {
    // Sort all jobs according to decreasing order of profit
    std::sort(jobs.begin(), jobs.end(), comparison);

    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }

    std::vector<int> slot(max_deadline + 1, -1);
    int countJobs = 0, totalProfit = 0;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return {countJobs, totalProfit};
}

int main() {
    int n;
    std::cout << "Enter the number of jobs: ";
    std::cin >> n;

    std::vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter job id, deadline, and profit for job " << i + 1 << ": ";
        std::cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    std::pair<int, int> result = JobScheduling(jobs, n);
    std::cout << "Number of jobs done: " << result.first << std::endl;
    std::cout << "Maximum profit: " << result.second << std::endl;

    return 0;
}
