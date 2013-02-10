#include "phere/Format.hpp"

int main()
{
  using std::cout;
  using phere::format;

  cout << format("%1% %2% %3% %2% %1% \n", "11", "22", "333");
  // Boost.Format: "simple style"
  // cout << format("%1% %2% %3% %2% %1% \n") % "11" % "22" % "333"; // 'simple' style.
  return 0;
}
