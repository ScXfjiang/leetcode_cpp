#include <queue>

// Solution 1 - Two Queues
class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    q2.push(x);
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    std::swap(q1, q2);
  }

  int pop() {
    int top = q1.front();
    q1.pop();
    return top;
  }

  int top() { return q1.front(); }

  bool empty() { return q1.empty(); }

 private:
  std::queue<int> q1;
  std::queue<int> q2;
};

// Solution 2 - One Queue
class MyStack {
 public:
  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; ++i) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int top = q.front();
    q.pop();
    return top;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }

 private:
  std::queue<int> q;
};
