#define BOOST_TEST_MODULE Format
#include <boost/test/unit_test.hpp>

#include "phere/Format.hpp"

using phere::format;
BOOST_AUTO_TEST_CASE( empty )
{
  // empty parameters means empty result
  BOOST_CHECK_EQUAL(format(),
					"");
  BOOST_CHECK_EQUAL(format(""),
					"");
}

BOOST_AUTO_TEST_CASE( printf_style )
{
  // C 'printf'-style formatting
  BOOST_CHECK_EQUAL(format("%d", 42),
					"42");
  BOOST_CHECK_EQUAL(format("%s", "string"),
					"string");
}

BOOST_AUTO_TEST_CASE( positional )
{
  // Boost.Format positional parameters
  BOOST_CHECK_EQUAL(format("%2% - %1%", "first", "second"),
					"second - first");
}
