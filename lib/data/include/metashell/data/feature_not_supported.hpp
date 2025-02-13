#ifndef METASHELL_DATA_FEATURE_NOT_SUPPORTED_HPP
#define METASHELL_DATA_FEATURE_NOT_SUPPORTED_HPP

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

#include <metashell/data/some_feature_not_supported.hpp>

namespace metashell
{
  namespace data
  {
    template <class Feature>
    struct feature_not_supported : some_feature_not_supported
    {
      explicit feature_not_supported(const data::engine_name& engine_)
        : some_feature_not_supported(engine_, Feature::name_of_feature())
      {
      }
    };
  }
}

#endif
