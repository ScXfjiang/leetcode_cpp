#include <vector>
#include <stack>

bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
  std::stack<int> dfs;                             // Stack to hold keys/rooms to visit.
  dfs.push(0);                                     // Start with room 0.
  std::vector<bool> visited(rooms.size(), false);  // Keep track of visited rooms.
  visited[0] = true;                               // Mark room 0 as visited.

  while (!dfs.empty()) {
    int currentRoom = dfs.top();
    dfs.pop();
    for (int key : rooms[currentRoom]) {
      if (!visited[key]) {    // If we haven't visited this room yet.
        visited[key] = true;  // Mark as visited.
        dfs.push(key);        // Add the room to the stack.
      }
    }
  }

  // Check if all rooms have been visited.
  for (bool room : visited) {
    if (!room) return false;
  }
  return true;
}
