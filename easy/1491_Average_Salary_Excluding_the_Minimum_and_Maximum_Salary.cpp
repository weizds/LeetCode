class Solution {
public:
    double average(vector<int>& salary) {
        int max_salary = salary[0];
        int min_salary = salary[0];
        int sum = salary[0];
        for(int i = 1; i < salary.size(); ++i) {
            max_salary = max(max_salary, salary[i]);
            min_salary = min(min_salary, salary[i]);
            sum += salary[i];
        }
        return 1. * (sum - max_salary - min_salary) / (salary.size() - 2);
    }
};