#include <gtest/gtest.h>
#include <sma.hpp>

TEST(SMATest, Iota) {
  std::vector<double> input = {0.0, 1.0, 2.0, 3.0, 4.0,
                               5.0, 6.0, 7.0, 8.0, 9.0};

  auto out = sma(input, 4);
  std::vector<double> expected = {0.0, 0.5, 1,   1.5, 2.5,
                                  3.5, 4.5, 5.5, 6.5, 7.5};

  ASSERT_EQ(expected.size(), out.size());

  for (int i = 0; i < out.size(); i++) {
    ASSERT_FLOAT_EQ(expected[i], out[i]);
  }
};

TEST(SMATest, KIsOne) {
  std::vector<double> input = {0.0, 1.0, 2.0, 3.0, 4.0,
                               5.0, 6.0, 7.0, 8.0, 9.0};

  auto out = sma(input, 1);

  ASSERT_EQ(input.size(), out.size());

  for (int i = 0; i < out.size(); i++) {
    ASSERT_FLOAT_EQ(input[i], out[i]);
  }
};

TEST(SMATest, SizeIsSmallerThanK) {
  std::vector<double> input = {0.0, 1.0, 2.0};

  auto out = sma(input, 4);

  std::vector<double> expected = {0.0, 0.5, 1};

  ASSERT_EQ(expected.size(), out.size());

  for (int i = 0; i < out.size(); i++) {
    ASSERT_FLOAT_EQ(expected[i], out[i]);
  }
};

TEST(SMATest, EmptyArray) {
  std::vector<double> input;
  auto out = sma(input, 4);
  ASSERT_EQ(0, out.size());
}
