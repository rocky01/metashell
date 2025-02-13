#ifndef METASHELL_DATA_SHELL_CONFIG_DATA_HPP
#define METASHELL_DATA_SHELL_CONFIG_DATA_HPP

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

#include <metashell/data/engine_name.hpp>

#include <string>
#include <vector>

namespace metashell
{
  namespace data
  {
    class shell_config_data
    {
    public:
      std::vector<std::string> engine_args;
      bool use_precompiled_headers = false;
      engine_name engine = engine_name("auto");
      bool preprocessor_mode = false;
    };
  }
}

#endif
