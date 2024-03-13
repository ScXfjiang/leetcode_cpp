#include <list>
#include <unordered_map>

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto it = cache_.find(key);
    if (it == cache_.end()) { return -1; }
    items_.splice(items_.begin(), items_, it->second);
    return it->second->second;
  }

  void put(int key, int value) {
    auto it = cache_.find(key);
    if (it != cache_.end()) {
      it->second->second = value;
      items_.splice(items_.begin(), items_, it->second);
      return;
    }
    if (items_.size() == capacity_) {
      auto last = items_.back();
      cache_.erase(last.first);
      items_.pop_back();
    }
    items_.emplace_front(key, value);
    cache_[key] = items_.begin();
  }

 private:
  int capacity_;
  std::list<std::pair<int, int>> items_;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_;
};
