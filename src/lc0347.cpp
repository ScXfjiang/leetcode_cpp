#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> num2freq;
  for (int num : nums) { num2freq[num]++; }
  auto comp = [&num2freq](int n1, int n2) { return num2freq[n1] > num2freq[n2]; };
  std::priority_queue<int, std::vector<int>, decltype(comp)> heap(comp);
  for (auto& [num, freq] : num2freq) {
    heap.push(num);
    if (heap.size() > k) { heap.pop(); }
  }
  std::vector<int> top_k;
  while (!heap.empty()) {
    top_k.push_back(heap.top());
    heap.pop();
  }
  return top_k;
}
