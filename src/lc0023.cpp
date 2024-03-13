#include <algorithm>
#include <limits>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
  ListNode* head = new ListNode(-1);
  ListNode* tail = head;
  while (std::any_of(lists.begin(), lists.end(), [](ListNode* ptr) { return ptr != nullptr; })) {
    int min_val = std::numeric_limits<int>::max();
    ListNode* min_ptr = nullptr;
    ListNode** min_ptr_ptr = nullptr;
    for (auto cur_ptr : lists) {
      if (cur_ptr != nullptr && cur_ptr->val < min_val) {
        min_ptr = cur_ptr;
        min_val = cur_ptr->val;
        min_ptr_ptr = &min_ptr;
      }
    }
    tail = new ListNode(min_val);
    tail = tail->next;
    *min_ptr_ptr = (*min_ptr_ptr)->next;
  }

  return head->next;
}