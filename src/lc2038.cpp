#include <string>

bool winnerOfGame(std::string colors) {
  int alice_removals = 0;
  int bob_removals = 0;
  for (int i = 1; i < colors.size() - 1; ++i) {
    if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
      if (colors[i] == 'A')
        alice_removals++;
      else
        bob_removals++;
    }
  }
  return alice_removals > bob_removals;
}
