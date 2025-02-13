// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2016, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/core/include_path_cache.hpp>

namespace metashell
{
  namespace core
  {
    include_path_cache::include_path_cache(
        iface::header_discoverer& header_discoverer_)
      : sys([&header_discoverer_]() {
          return header_discoverer_.include_path(data::include_type::sys);
        }),
        quote([&header_discoverer_]() {
          return header_discoverer_.include_path(data::include_type::quote);
        })
    {
    }

    const std::vector<boost::filesystem::path>& include_path_cache::
    operator[](data::include_type type_)
    {
      return type_ == data::include_type::sys ? *sys : *quote;
    }
  }
}
