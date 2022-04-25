#include <ctime>
#include <iomanip>
#include <iostream>

// cd /mnt/c/Users/User/Documents/Ks/PC_Software/NumericalPrograms/ExtendedNumberTypes/boost_multiprecision_examples/boost_multiprecision_harden
// g++ -Wall -Wextra -Wconversion -Wsign-conversion -Wshadow -Wundef -Wunused-parameter -Wuninitialized -Wunreachable-code -Winit-self -Wzero-as-null-pointer-constant -O3 -std=c++11 -I/mnt/c/boost/modular_boost/boost/libs/config/include -I. standalone_bernoulli_tgamma_cpp_bin_float.cpp standalone_bernoulli_tgamma_gmp_float.cpp test.cpp -lgmp -o test.exe

extern auto example008_bernoulli_tgamma_cpp_bin_float() -> bool;
#if !defined(_MSC_VER)
extern auto example008_bernoulli_tgamma_gmp_float    () -> bool;
#endif

auto main() -> int
{
  auto start = std::clock();
  const auto result_is_ok_cpp_bin_float = example008_bernoulli_tgamma_cpp_bin_float();
  auto stop  = std::clock();

  std::cout << "Time example008_bernoulli_tgamma_cpp_bin_float(): "
            << static_cast<float>(stop - start) / static_cast<float>(CLOCKS_PER_SEC)
            << std::endl;

  #if !defined(_MSC_VER)
  start = std::clock();
  const auto result_is_ok_gmp_float = example008_bernoulli_tgamma_gmp_float();
  stop  = std::clock();

  std::cout << "Time example008_bernoulli_tgamma_gmp_float(): "
            << static_cast<float>(stop - start) / static_cast<float>(CLOCKS_PER_SEC)
            << std::endl;
  #endif

  const auto result_is_ok =
  (
       result_is_ok_cpp_bin_float
    #if !defined(_MSC_VER)
    && result_is_ok_gmp_float
    #endif
  );

  std::cout << "result_is_ok: " << std::boolalpha << result_is_ok << std::endl;

  return (result_is_ok ? 0 : -1);
}
