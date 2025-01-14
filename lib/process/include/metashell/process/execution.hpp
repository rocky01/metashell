#ifndef METASHELL_PROCESS_EXECUTION_HPP
#define METASHELL_PROCESS_EXECUTION_HPP

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

#include <metashell/data/exit_code_t.hpp>
#include <metashell/data/process_output.hpp>

#include <metashell/process/pipe.hpp>

#include <boost/filesystem/path.hpp>

#include <string>
#include <vector>

namespace metashell
{
  namespace process
  {
    class execution
    {
    public:
      execution(
          const boost::filesystem::path& binary_,
          const std::vector<std::string>& args_,
          const boost::filesystem::path& cwd_ = boost::filesystem::path());

      execution(const execution&) = delete;
      execution& operator=(const execution&) = delete;

      // Adding move operations for implementing ownership transfer
      execution(execution&& e_);
      execution& operator=(execution&& e_);

      ~execution();

      output_file& standard_input();
      input_file& standard_output();
      input_file& standard_error();

      data::exit_code_t wait();

    private:
      pipe _standard_input;
      pipe _standard_output;
      pipe _standard_error;

#ifdef _WIN32
      PROCESS_INFORMATION _process_information;
#else
      pid_t _pid;
#endif
    };
  }
}

#endif
