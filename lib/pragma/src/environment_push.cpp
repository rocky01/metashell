// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2014, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/pragma/environment_push.hpp>

namespace metashell
{
  namespace pragma
  {
    std::string environment_push::description() const
    {
      return "Pushes the current environment to the environment stack.";
    }

    void environment_push::run(iface::shell& shell_,
                               iface::displayer& displayer_) const
    {
      shell_.push_environment();
      shell_.display_environment_stack_size(displayer_);
    }
  }
}
