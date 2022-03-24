#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "absl/strings/string_view.h"

TEST(StringViewTest, construct) {
  std::string t = "test";
  absl::string_view t_view(t);
  std::vector<std::string> v;
  // data方法不保证\0结尾
  /*
    // string_view::data()
    //
    // Returns a pointer to the underlying character array (which is of course
    // stored elsewhere). Note that `string_view::data()` may contain embedded nul
    // characters, but the returned buffer may or may not be NUL-terminated;
    // therefore, do not pass `data()` to a routine that expects a NUL-terminated
    // string.
  */
  v.emplace_back(t_view.data(), t_view.size());

  // string_view对应的Convert函数，将string_view转换为std::string
  /*
    // Converts to `std::basic_string`.
    template <typename A>
    explicit operator std::basic_string<char, traits_type, A>() const {
      if (!data()) return {};
      return std::basic_string<char, traits_type, A>(data(), size());
    }
  */
  std::string c(t_view);
}