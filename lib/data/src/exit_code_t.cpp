// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2015, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/data/exit_code_t.hpp>

#include <iostream>

namespace metashell
{
  namespace data
  {
    exit_code_t::exit_code_t(int value_) : _value(value_) {}

    int exit_code_t::value() const { return _value; }

    bool operator==(exit_code_t a_, exit_code_t b_)
    {
      return a_.value() == b_.value();
    }

    std::ostream& operator<<(std::ostream& out_, exit_code_t e_)
    {
      return out_ << "exit_code(" << e_.value() << ")";
    }

    std::string to_string(exit_code_t e_) { return std::to_string(e_.value()); }
  }
}
