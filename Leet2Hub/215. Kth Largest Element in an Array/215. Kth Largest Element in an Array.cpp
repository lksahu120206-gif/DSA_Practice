1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4
5        priority_queue<int, vector<int>, greater<int>> pq;
6
7        for(int x : nums){
8
9            pq.push(x);
10
11            if(pq.size()>k)
12                pq.pop();
13        }
14
15        return pq.top();
16    }
17};