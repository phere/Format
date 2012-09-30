/*
 *  Format.hpp
 *  Format
 *
 *  Created by Rowan James on 14/05/11.
 *  Copyright 2011 Phere Development. All rights reserved.
 *
 */

#ifndef PHERE_FORMAT_FORMAT_HPP
#define PHERE_FORMAT_FORMAT_HPP

#include <string>
#include <iostream>
#include <boost/format.hpp>
#include <boost/exception/diagnostic_information.hpp>

namespace phere {
  namespace Format {
    namespace detail {
      template <typename Format>
      static void ApplyArgs(Format&&)
      {} // no args, no-op.
      
      template <typename Format, typename FirstArg>
      static void ApplyArgs(Format&& format,
			    FirstArg&& firstArg)
      {
	format % firstArg;
      }

      template <typename Format, typename FirstArg, typename ... OtherArgs>
      static void ApplyArgs(Format& format,
			    FirstArg&& firstArg,
			    OtherArgs&& ... otherArgs)
      {
	format % firstArg;
	ApplyArgs(format, std::forward<OtherArgs>(otherArgs)...);
      }
    } // namespace detail

    template <typename Result = std::string, typename FormatType, typename ... Args>
    static Result format(FormatType&& messageFormat, Args&& ... args)
    {
      try
	{
	  boost::format format(std::forward<FormatType>(messageFormat));
	  detail::ApplyArgs(format, std::forward<Args>(args)...);
	  return str(format);
	}
      catch (boost::io::format_error& ex)
	{
	  std::cerr << ">>>> Error encountered while formatting string for phere::debug::Logger : ";
	  std::cerr << boost::current_exception_diagnostic_information() << std::endl;
	}
      return Result();
    }
    // zero-argument overload returns default-construct Result type
    template <typename Result = std::string>
    static Result format()
    { return Result(); }
  } // namespace Format
} // namespace phere

#endif
