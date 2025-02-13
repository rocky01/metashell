#ifndef METASHELL_DATA_CONSTRAINT_RANGE_HPP
#define METASHELL_DATA_CONSTRAINT_RANGE_HPP

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

namespace metashell
{
  namespace data
  {
    namespace constraint
    {
      template <char From, char To>
      struct range
      {
        template <class CharT>
        static constexpr bool allowed_char(CharT c_)
        {
          return From <= c_ && c_ <= To;
        }
      };
    }
  }
}

#endif
