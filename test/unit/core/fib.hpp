#ifndef METASHELL_TEST_FIB_HPP
#define METASHELL_TEST_FIB_HPP

// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2013, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/data/type.hpp>

#include <string>

template <int N>
metashell::data::type fib()
{
  return metashell::data::type("fib<" + std::to_string(N) + ">");
}

template <int N>
metashell::data::type v1fib()
{
  return metashell::data::type("v1::fib<" + std::to_string(N) + ">");
}

template <int N>
metashell::data::type v2fib()
{
  return metashell::data::type("v2::fib<" + std::to_string(N) + ">");
}

#endif
