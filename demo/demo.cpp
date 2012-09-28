#include "Format.hpp"

int main()
{
  using std::cout;
  using phere::Format::format;

  cout << format("%1% %2% %3% %2% %1% \n", "11", "22", "333");
  // Boost.Format: "simple style"
  // cout << format
  return 0;
}
