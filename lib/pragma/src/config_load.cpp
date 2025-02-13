// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2017, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/pragma/config_load.hpp>

#include <metashell/core/comment_json_writer.hpp>
#include <metashell/core/engine.hpp>

#include <metashell/data/exception.hpp>
#include <metashell/data/some_feature_not_supported.hpp>

#include <algorithm>

namespace metashell
{
  namespace pragma
  {
    namespace
    {
      void restore_config(const data::shell_config_name& name_,
                          iface::shell& shell_)
      {
        shell_.get_config().activate(name_);
        shell_.rebuild_environment();
      }
    }

    std::string config_load::arguments() const { return "<name>"; }

    std::string config_load::description() const
    {
      return "Loads the config in the shell (keeping the environment).";
    }

    void config_load::run(const data::command::iterator&,
                          const data::command::iterator&,
                          const data::command::iterator& args_begin_,
                          const data::command::iterator& args_end_,
                          iface::shell& shell_,
                          iface::displayer& displayer_) const
    {
      const data::shell_config_name name = data::shell_config_name(
          tokens_to_string(args_begin_, args_end_).value());

      const auto& configs = shell_.get_config().shell_configs();

      const auto cfg = std::find_if(configs.begin(), configs.end(),
                                    [&name](const data::shell_config& cfg_) {
                                      return cfg_.name == name;
                                    });

      if (cfg == configs.end())
      {
        throw data::exception("Config " + name + " not found.");
      }
      else
      {
        const auto old_config = shell_.get_config().active_shell_config().name;
        shell_.get_config().activate(name);
        try
        {
          shell_.rebuild_environment();

          data::text comment;
          comment.paragraphs.emplace_back("Switched to config " + name);

          if (const auto limit = core::limitation(shell_.engine()))
          {
            comment.paragraphs.emplace_back();
            comment.paragraphs.emplace_back(*limit);
          }

          displayer_.show_comment(comment);
        }
        catch (const std::exception& e)
        {
          displayer_.show_error("Error loading config " + name + ": " +
                                e.what());
          restore_config(old_config, shell_);
        }
        catch (...)
        {
          displayer_.show_error("Error loading config " + name +
                                ": unknown exception");
          restore_config(old_config, shell_);
        }
      }
    }
  }
}
