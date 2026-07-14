1class MedianFinder {
2
3    priority_queue<int> leftHeap;
4
5    priority_queue<int, vector<int>, greater<int>> rightHeap;
6
7public:
8    MedianFinder() {
9
10    }
11
12    void addNum(int num) {
13
14        if (leftHeap.empty() || num <= leftHeap.top())
15            leftHeap.push(num);
16        else
17            rightHeap.push(num);
18
19        if (leftHeap.size() > rightHeap.size() + 1) {
20            rightHeap.push(leftHeap.top());
21            leftHeap.pop();
22        }
23
24        else if (rightHeap.size() > leftHeap.size()) {
25            leftHeap.push(rightHeap.top());
26            rightHeap.pop();
27        }
28    }
29
30    double findMedian() {
31
32        if (leftHeap.size() == rightHeap.size())
33            return (leftHeap.top() + rightHeap.top()) / 2.0;
34
35        return leftHeap.top();
36    }
37};
38
39/**
40 * Your MedianFinder object will be instantiated and called as such:
41 * MedianFinder* obj = new MedianFinder();
42 * obj->addNum(num);
43 * double param_2 = obj->findMedian();
44 */