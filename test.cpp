﻿///////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2022.                        //
//  Distributed under the Boost Software License,                //
//  Version 1.0. (See accompanying file LICENSE_1_0.txt          //
//  or copy at http://www.boost.org/LICENSE_1_0.txt)             //
///////////////////////////////////////////////////////////////////

#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>

// cd /mnt/c/Users/User/Documents/Ks/PC_Software/NumericalPrograms/ExtendedNumberTypes/boost_multiprecision_examples/boost_multiprecision_harden
// g++ -Wall -Wextra -Wconversion -Wsign-conversion -Wshadow -Wundef -Wunused-parameter -Wuninitialized -Wunreachable-code -Winit-self -Wzero-as-null-pointer-constant -O3 -std=c++11 -I/mnt/c/boost/modular_boost/boost/libs/config/include -I. standalone_bernoulli_tgamma_cpp_bin_float.cpp standalone_bernoulli_tgamma_cpp_dec_float.cpp standalone_bernoulli_tgamma_gmp_float.cpp test.cpp -lgmp -o test.exe

extern auto example008_bernoulli_tgamma_cpp_bin_float() -> bool;
extern auto example008_bernoulli_tgamma_cpp_dec_float() -> bool;
extern auto example008_bernoulli_tgamma_gmp_float    () -> bool;

namespace local
{
  template<typename FunctionType>
  auto test(const FunctionType& pf) -> bool
  {
    const auto start = std::clock();
    const auto result_is_ok_pf = pf();
    const auto stop  = std::clock();

    std::cout << static_cast<float>(stop - start) / static_cast<float>(CLOCKS_PER_SEC)
              << std::endl;

    return result_is_ok_pf;
  }
} // namespace local

auto main() -> int
{
  const auto result_is_ok_cpp_bin_float = local::test(example008_bernoulli_tgamma_cpp_bin_float);
  const auto result_is_ok_cpp_dec_float = local::test(example008_bernoulli_tgamma_cpp_dec_float);
  const auto result_is_ok_gmp_____float = local::test(example008_bernoulli_tgamma_gmp_float);

  const auto result_is_ok =
  (
       result_is_ok_cpp_bin_float
    && result_is_ok_cpp_dec_float
    && result_is_ok_gmp_____float
  );

  std::cout << "result_is_ok: " << std::boolalpha << result_is_ok << std::endl;

  return (result_is_ok ? 0 : -1);
}
