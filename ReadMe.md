phere.Format
============

Format a C++ string with usage like `sprintf`, but without all that tedious messing around in hyperspace.

Formatting is done with [Boost.format](http://boost.org/libs/format/), so you get both `printf`-style format placeholders and Boost.Format's hand positional ones.

Currently, format exceptions are swallowed, returning an empty string - this suits my usage in phere/Debug quite well, but I'm planning to add throwing versions of `format(...)` as well.

Your format arguments are sent to _Boost.Format_ through C++11 variadic templates - so you'll want a compiler with good support for those.

```C++
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
```

( It prints : "11 22 333 22 11 \n" )
