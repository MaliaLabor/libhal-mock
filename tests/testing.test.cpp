// Copyright 2024 Khalil Estell
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <libhal-mock/pwm.hpp>

#include <exception>

#include <boost/ut.hpp>

namespace hal::mock {
void testing_utilities_test()
{
  using namespace boost::ut;

  spy_handler<int, char> spy;

  expect(that % 0 == spy.call_history().size());

  spy.trigger_error_on_call(4,
                            [&]() { throw std::out_of_range("out of range"); });

  [[maybe_unused]] auto a =
    throws<std::out_of_range>([&]() { spy.record(1, 'A'); });

  expect(that % 1 == spy.call_history().size());
  expect(that % 1 == std::get<0>(spy.call_history().at(0)));
  expect(that % 1 == spy.history<0>(0));
  expect(that % 'A' == std::get<1>(spy.call_history().at(0)));
  expect(that % 'A' == spy.history<1>(0));

  [[maybe_unused]] auto b =
    throws<std::out_of_range>([&]() { spy.record(2, 'B'); });

  expect(that % 2 == spy.call_history().size());
  expect(that % 1 == std::get<0>(spy.call_history().at(0)));
  expect(that % 1 == spy.history<0>(0));
  expect(that % 'A' == std::get<1>(spy.call_history().at(0)));
  expect(that % 'A' == spy.history<1>(0));
  expect(that % 2 == std::get<0>(spy.call_history().at(1)));
  expect(that % 2 == spy.history<0>(1));
  expect(that % 'B' == std::get<1>(spy.call_history().at(1)));
  expect(that % 'B' == spy.history<1>(1));

  [[maybe_unused]] auto c =
    throws<std::out_of_range>([&]() { spy.record(3, 'C'); });

  expect(that % 3 == spy.call_history().size());
  expect(that % 1 == std::get<0>(spy.call_history().at(0)));
  expect(that % 1 == spy.history<0>(0));
  expect(that % 'A' == std::get<1>(spy.call_history().at(0)));
  expect(that % 'A' == spy.history<1>(0));
  expect(that % 2 == std::get<0>(spy.call_history().at(1)));
  expect(that % 2 == spy.history<0>(1));
  expect(that % 'B' == std::get<1>(spy.call_history().at(1)));
  expect(that % 'B' == spy.history<1>(1));
  expect(that % 3 == std::get<0>(spy.call_history().at(2)));
  expect(that % 3 == spy.history<0>(2));
  expect(that % 'C' == std::get<1>(spy.call_history().at(2)));
  expect(that % 'C' == spy.history<1>(2));

  [[maybe_unused]] auto d =
    throws<std::out_of_range>([&]() { spy.record(4, 'D'); });

  expect(that % 4 == spy.call_history().size());
  expect(that % 1 == std::get<0>(spy.call_history().at(0)));
  expect(that % 1 == spy.history<0>(0));
  expect(that % 'A' == std::get<1>(spy.call_history().at(0)));
  expect(that % 'A' == spy.history<1>(0));
  expect(that % 2 == std::get<0>(spy.call_history().at(1)));
  expect(that % 2 == spy.history<0>(1));
  expect(that % 'B' == std::get<1>(spy.call_history().at(1)));
  expect(that % 'B' == spy.history<1>(1));
  expect(that % 3 == std::get<0>(spy.call_history().at(2)));
  expect(that % 3 == spy.history<0>(2));
  expect(that % 'C' == std::get<1>(spy.call_history().at(2)));
  expect(that % 'C' == spy.history<1>(2));
  expect(that % 4 == std::get<0>(spy.call_history().at(3)));
  expect(that % 4 == spy.history<0>(3));
  expect(that % 'D' == std::get<1>(spy.call_history().at(3)));
  expect(that % 'D' == spy.history<1>(3));

  spy.reset();

  expect(that % 0 == spy.call_history().size());

  [[maybe_unused]] auto e =
    throws<std::out_of_range>([&]() { spy.record(1, 'A'); });

  expect(that % 1 == spy.call_history().size());
  expect(that % 1 == std::get<0>(spy.call_history().at(0)));
  expect(that % 1 == spy.history<0>(0));
  expect(that % 'A' == std::get<1>(spy.call_history().at(0)));
  expect(that % 'A' == spy.history<1>(0));

  [[maybe_unused]] auto f =
    throws<std::out_of_range>([&]() { spy.record(2, 'B'); });

  expect(that % 2 == spy.call_history().size());
  expect(that % 1 == std::get<0>(spy.call_history().at(0)));
  expect(that % 1 == spy.history<0>(0));
  expect(that % 'A' == std::get<1>(spy.call_history().at(0)));
  expect(that % 'A' == spy.history<1>(0));
  expect(that % 2 == std::get<0>(spy.call_history().at(1)));
  expect(that % 2 == spy.history<0>(1));
  expect(that % 'B' == std::get<1>(spy.call_history().at(1)));
  expect(that % 'B' == spy.history<1>(1));

  [[maybe_unused]] auto g =
    throws<std::out_of_range>([&]() { spy.record(3, 'C'); });

  expect(that % 3 == spy.call_history().size());
  expect(that % 1 == std::get<0>(spy.call_history().at(0)));
  expect(that % 1 == spy.history<0>(0));
  expect(that % 'A' == std::get<1>(spy.call_history().at(0)));
  expect(that % 'A' == spy.history<1>(0));
  expect(that % 2 == std::get<0>(spy.call_history().at(1)));
  expect(that % 2 == spy.history<0>(1));
  expect(that % 'B' == std::get<1>(spy.call_history().at(1)));
  expect(that % 'B' == spy.history<1>(1));
  expect(that % 3 == std::get<0>(spy.call_history().at(2)));
  expect(that % 3 == spy.history<0>(2));
  expect(that % 'C' == std::get<1>(spy.call_history().at(2)));
  expect(that % 'C' == spy.history<1>(2));

  [[maybe_unused]] auto h =
    throws<std::out_of_range>([&]() { spy.record(4, 'D'); });

  expect(that % 4 == spy.call_history().size());
  expect(that % 1 == std::get<0>(spy.call_history().at(0)));
  expect(that % 1 == spy.history<0>(0));
  expect(that % 'A' == std::get<1>(spy.call_history().at(0)));
  expect(that % 'A' == spy.history<1>(0));
  expect(that % 2 == std::get<0>(spy.call_history().at(1)));
  expect(that % 2 == spy.history<0>(1));
  expect(that % 'B' == std::get<1>(spy.call_history().at(1)));
  expect(that % 'B' == spy.history<1>(1));
  expect(that % 3 == std::get<0>(spy.call_history().at(2)));
  expect(that % 3 == spy.history<0>(2));
  expect(that % 'C' == std::get<1>(spy.call_history().at(2)));
  expect(that % 'C' == spy.history<1>(2));
  expect(that % 4 == std::get<0>(spy.call_history().at(3)));
  expect(that % 4 == spy.history<0>(3));
  expect(that % 'D' == std::get<1>(spy.call_history().at(3)));
  expect(that % 'D' == spy.history<1>(3));
};
}  // namespace hal::mock
