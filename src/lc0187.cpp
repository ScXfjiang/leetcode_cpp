#include <vector>
#include <unordered_map>
#include <string>

std::vector<std::string> findRepeatedDnaSequences(std::string s) {
  std::vector<std::string> repeated_seqs;
  if (s.size() < 10) { return repeated_seqs; }
  std::unordered_map<std::string, int> seq2cnt;
  for (int i = 0; i <= s.size() - 10; ++i) {
    std::string seq = s.substr(i, 10);
    ++seq2cnt[seq];
  }
  for (auto& pair : seq2cnt) {
    if (pair.second > 1) { repeated_seqs.push_back(pair.first); }
  }
  return repeated_seqs;
}
