///////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2022.                        //
//  Distributed under the Boost Software License,                //
//  Version 1.0. (See accompanying file LICENSE_1_0.txt          //
//  or copy at http://www.boost.org/LICENSE_1_0.txt)             //
///////////////////////////////////////////////////////////////////

#include <ctime>
#include <functional>
#if !defined(__arm__)
#include <iomanip>
#include <iostream>
#endif

// cd /mnt/c/Users/User/Documents/Ks/PC_Software/NumericalPrograms/ExtendedNumberTypes/boost_multiprecision_examples/boost_multiprecision_harden
// g++ -Wall -Wextra -Wconversion -Wsign-conversion -Wshadow -Wundef -Wunused-parameter -Wuninitialized -Wunreachable-code -Winit-self -Wzero-as-null-pointer-constant -O3 -std=c++11 -I/mnt/c/boost/modular_boost/boost/libs/config/include -I. standalone_bernoulli_tgamma_cpp_bin_float.cpp standalone_bernoulli_tgamma_cpp_dec_float.cpp standalone_bernoulli_tgamma_gmp_float.cpp standalone_bernoulli_tgamma_mpfr_float.cpp test.cpp -lgmp -lmpfr -o test.exe

// Build with arm-none-eabi for ARM1176.
// arm-none-eabi-g++ -std=c++11 -Wall -Wextra -Wconversion -Wsign-conversion -Wshadow -Wundef -Wunused-parameter -Wuninitialized -Wunreachable-code -Winit-self -Wzero-as-null-pointer-constant -O2 -g -gdwarf-2 -fno-exceptions -ffunction-sections -fdata-sections -x c++ -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -fno-enforce-eh-specs -ftemplate-depth=128 -marm -march=armv6zk -mtune=arm1176jzf-s -mfpu=vfpv2 -mfloat-abi=hard -ffast-math -DBOOST_NO_EXCEPTIONS -I./src/mcal/stm32f446 -I/mnt/c/boost/modular_boost/boost/libs/config/include -I. standalone_bernoulli_tgamma_cpp_bin_float.cpp standalone_bernoulli_tgamma_cpp_dec_float.cpp test.cpp -Wl,--gc-sections -Wl,-Map,./test.map --specs=nano.specs --specs=nosys.specs -o ./test.elf

extern auto example008_bernoulli_tgamma_cpp_bin_float() -> bool;
extern auto example008_bernoulli_tgamma_cpp_dec_float() -> bool;
#if !defined(__arm__)
extern auto example008_bernoulli_tgamma_gmp_float    () -> bool;
extern auto example008_bernoulli_tgamma_mpfr_float   () -> bool;
#endif

namespace local
{
  template<typename FunctionType>
  auto test(const FunctionType& pf) -> bool
  {
    #if !defined(__arm__)
    const auto start = std::clock();
    #endif
    const auto result_is_ok_pf = pf();
    #if !defined(__arm__)
    const auto stop  = std::clock();
    #endif

    #if !defined(__arm__)
    std::cout << static_cast<float>(stop - start) / static_cast<float>(CLOCKS_PER_SEC)
              << std::endl;
    #endif

    return result_is_ok_pf;
  }
} // namespace local

auto main() -> int
{
  const auto result_is_ok_cpp_bin_float = local::test(example008_bernoulli_tgamma_cpp_bin_float);
  const auto result_is_ok_cpp_dec_float = local::test(example008_bernoulli_tgamma_cpp_dec_float);
  #if !defined(__arm__)
  const auto result_is_ok_gmp_____float = local::test(example008_bernoulli_tgamma_gmp_float);
  const auto result_is_ok_mpfr____float = local::test(example008_bernoulli_tgamma_mpfr_float);
  #endif

  const auto result_is_ok =
  (
       result_is_ok_cpp_bin_float
    && result_is_ok_cpp_dec_float
    #if !defined(__arm__)
    && result_is_ok_gmp_____float
    && result_is_ok_mpfr____float
    #endif
  );

  #if !defined(__arm__)
  std::cout << "result_is_ok_cpp_bin_float: " << std::boolalpha << result_is_ok_cpp_bin_float << std::endl;
  std::cout << "result_is_ok_cpp_dec_float: " << std::boolalpha << result_is_ok_cpp_dec_float << std::endl;
  std::cout << "result_is_ok_gmp_____float: " << std::boolalpha << result_is_ok_gmp_____float << std::endl;
  std::cout << "result_is_ok_mpfr____float: " << std::boolalpha << result_is_ok_mpfr____float << std::endl;
  std::cout << "result_is_ok (total):       " << std::boolalpha << result_is_ok               << std::endl;
  #endif

  return (result_is_ok ? 0 : -1);
}

#if defined(__arm__)
extern "C"
void __sync_synchronize() { asm volatile("nop"); }
#endif
