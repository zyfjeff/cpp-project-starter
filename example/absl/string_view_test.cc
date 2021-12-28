#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "absl/strings/string_view.h"

TEST(StringViewTest, construct) {
  std::string t = "test";
  absl::string_view t_view(t);
  std::vector<std::string> v;
  v.emplace_back(t_view.data(), t_view.size());
}