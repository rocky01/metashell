#ifndef METASHELL_DATA_SHELL_COMMAND_VIEW_HPP
#define METASHELL_DATA_SHELL_COMMAND_VIEW_HPP

// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2019, Abel Sinkovics (abel@sinkovics.hu)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <boost/operators.hpp>
#include <boost/optional.hpp>

#include <string>
#include <string_view>

namespace metashell
{
  namespace data
  {
    class shell_command_view
    {
    public:
      class iterator : public boost::forward_iterator_helper<iterator,
                                                             std::string,
                                                             std::ptrdiff_t,
                                                             std::string*,
                                                             std::string&>
      {
      public:
        iterator(std::string_view::const_iterator,
                 std::string_view::const_iterator);

        bool operator==(const iterator&) const;

        iterator& operator++();

        const std::string& operator*() const;

      private:
        std::string_view::const_iterator _begin;
        std::string_view::const_iterator _end;
        boost::optional<std::string> _value;
      };

      explicit shell_command_view(std::string_view);

      iterator begin() const;
      iterator end() const;

    private:
      std::string_view _value;
    };
  }
}

#endif
