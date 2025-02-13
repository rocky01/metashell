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

#include <metashell/core/engine_entry.hpp>

#include <boost/algorithm/string/join.hpp>
#include <boost/range/adaptor/transformed.hpp>

#include <algorithm>

namespace metashell
{
  namespace core
  {
    namespace
    {
      std::string no_features() { return "no features are supported"; }
    }

    engine_entry::engine_entry(
        engine_factory factory_,
        std::string args_,
        data::markdown_string description_,
        std::vector<data::feature> features_,
        std::function<bool(const std::vector<std::string>&)> this_engine_)
      : _factory(move(factory_)),
        _args(move(args_)),
        _description(std::move(description_)),
        _features(move(features_)),
        _this_engine(std::move(this_engine_))
    {
      std::sort(_features.begin(), _features.end());
    }

    std::unique_ptr<iface::engine> engine_entry::build(
        const data::config& config_,
        const boost::filesystem::path& internal_dir_,
        const boost::filesystem::path& temp_dir_,
        const boost::filesystem::path& env_filename_,
        const std::map<data::engine_name, engine_entry>& engines_,
        iface::environment_detector& env_detector_,
        iface::displayer& displayer_,
        logger* logger_) const
    {
      return _factory(config_, internal_dir_, temp_dir_, env_filename_,
                      engines_, env_detector_, displayer_, logger_);
    }

    const std::string& engine_entry::args() const { return _args; }

    const data::markdown_string& engine_entry::description() const
    {
      return _description;
    }

    const std::vector<data::feature>& engine_entry::features() const
    {
      return _features;
    }

    bool engine_entry::usable_by_auto() const { return bool(_this_engine); }

    bool engine_entry::this_engine(const std::vector<std::string>& args_) const
    {
      return usable_by_auto() && _this_engine(args_);
    }

    std::string list_features(const engine_entry& engine_)
    {
      return engine_.features().empty() ?
                 no_features() :
                 boost::algorithm::join(
                     engine_.features() |
                         boost::adaptors::transformed(
                             [](data::feature f_) { return to_string(f_); }),
                     ", ");
    }

    data::markdown_string list_features_in_markdown(const engine_entry& engine_)
    {
      return engine_.features().empty() ?
                 italics(data::markdown_string(no_features())) :
                 join(engine_.features() |
                          boost::adaptors::transformed([](data::feature f_) {
                            return data::self_reference(to_string(f_));
                          }),
                      data::markdown_string(", "));
    }

    std::function<bool(const std::vector<std::string>&)> never_used_by_auto()
    {
      return {};
    }
  }
}
