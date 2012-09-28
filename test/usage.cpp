#define BOOST_TEST_MODULE Format
#include <boost/test/unit_test.hpp>

#include "Format.hpp"

BOOST_AUTO_TEST_CASE( usage )
{
  using phere::Format::format;

  // empty parameters mean empty result
  BOOST_CHECK(format()
	      == "");
  BOOST_CHECK(format("")
	      == "");

  // C 'printf'-style formatting
  BOOST_CHECK(format("%d", 42)
	      == "42");
  BOOST_CHECK(format("%s", "string")
	      == "string");

  // Boost.Format positional parameters
  BOOST_CHECK(format("%2% - %1%", "first", "second")
	      == "second - first");
}
