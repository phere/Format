phere.Format
============

Format a C++ string with usage like `sprintf`, but without all that tedious messing around in hyperspace.

Formatting is done with [Boost.Format](http://boost.org/libs/format/), so you get both `printf`-style format placeholders and Boost.Format's handy positional ones.

Currently, format exceptions are swallowed, returning an empty string - this suits my usage in phere/Debug quite well, but I'm planning to add throwing versions of `format(...)` as well.

Your format arguments are sent to _Boost.Format_ through C++11 variadic templates - so you'll want a compiler with good support for those.  This lets us hide the modulo-operator overloading they use to construct the format object and feed your parameters to it.

Usage
-----
Have a look at `demo/demo.cpp` or `test/usage.cpp`.

Include the header `Format.hpp`.  Use it.  No building necessary.

```C++
#include "Format.hpp"

int main()
{
  using std::cout;
  using phere::format;

  cout << format("%1% %2% %3% %2% %1% \n", "11", "22", "333");
  // Boost.Format: "simple style"
  // cout << format("%1% %2% %3% %2% %1% \n") % "11" % "22" % "333";
  return 0;
}
```

( It prints : "11 22 333 22 11 \n" )
