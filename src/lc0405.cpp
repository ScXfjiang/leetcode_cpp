#include <string>

std::string toHex(int num) {
  if (num == 0) { return "0"; }
  std::string hex = "0123456789abcdef";
  std::string hex_str = "";
  // process the number for 32 bits, skip leading zeros
  for (int i = 0; num != 0 && i < 8; ++i) {
    int dec = num & 0xf;
    hex_str = hex[dec] + hex_str;
    num >>= 4;
  }
  return hex_str;
}
