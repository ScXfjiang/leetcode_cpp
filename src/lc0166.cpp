#include <string>
#include <unordered_map>

std::string fractionToDecimal(int numerator, int denominator) {
  if (numerator == 0) { return "0"; }
  std::string res_str;
  // sign
  if (numerator < 0 ^ denominator < 0) { res_str += '-'; }
  // integral part
  long n = std::abs(numerator);
  long d = std::abs(denominator);
  long quotient = n / d;
  res_str += std::to_string(quotient);
  long remainder = n % d;
  if (remainder == 0) { return res_str; }
  res_str += '.';
  // fractional part
  std::unordered_map<long, int> remainder2pos;
  while (remainder != 0) {
    if (remainder2pos.find(remainder) != remainder2pos.end()) {
      res_str.insert(remainder2pos[remainder], "(");
      res_str += ')';
      break;
    }
    remainder2pos[remainder] = res_str.size();
    remainder *= 10;
    quotient = remainder / d;
    res_str += std::to_string(quotient);
    remainder = remainder % d;
  }
  return res_str;
}
