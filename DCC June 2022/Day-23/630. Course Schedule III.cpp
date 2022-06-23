class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int> &op1,
                const vector<int> &op2) { return op1[1] < op2[1]; }
        );
        priority_queue<int> max_heap;
        int start = 0;
        for (int idx = 0; idx < courses.size(); ++idx)
        {
            int len = courses[idx][0];
            max_heap.push(len);
            start += len;
            int end = courses[idx][1];
            if (start > end) {
                start -= max_heap.top();
                max_heap.pop();
            }
        }
        return (int)max_heap.size();
    }
};
