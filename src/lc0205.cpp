#include <unordered_map>
#include <string>
#include <unordered_set>

// Solution - Bijection
bool isIsomorphic(std::string s, std::string t) {
  std::unordered_map<char, char> s2t;
  std::unordered_map<char, char> t2s;
  for (int i = 0; i < s.size(); ++i) {
    // s -> t
    if (s2t.find(s[i]) != s2t.end() && s2t[s[i]] != t[i]) { return false; }
    s2t[s[i]] = t[i];
    // t -> s
    if (t2s.find(t[i]) != t2s.end() && t2s[t[i]] != s[i]) { return false; }
    t2s[t[i]] = s[i];
  }
  return true;
}
