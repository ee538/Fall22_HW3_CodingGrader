#include <climits>
#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;
using ::testing::IsEmpty;
using ::testing::UnorderedElementsAre;
template <class T>
void PrintVector(std::vector<T> input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(BinaryTree, GetParentIndex) {
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Input: " << std::endl;
  PrintVector(in);

  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.GetParentIndex(0), -1);
  EXPECT_EQ(bt.GetParentIndex(1000), 499);

  EXPECT_EQ(bt.GetParentIndex(1), 0);
  EXPECT_EQ(bt.GetParentIndex(2), 0);

  EXPECT_EQ(bt.GetParentIndex(3), 1);
  EXPECT_EQ(bt.GetParentIndex(4), 1);

  EXPECT_EQ(bt.GetParentIndex(5), 2);
  EXPECT_EQ(bt.GetParentIndex(6), 2);

  EXPECT_EQ(bt.GetParentIndex(7), 3);
  EXPECT_EQ(bt.GetParentIndex(8), 3);

  EXPECT_EQ(bt.GetParentIndex(9), 4);
  EXPECT_EQ(bt.GetParentIndex(10), 4);
}
TEST(BinaryTree, GetLeftIndex) {
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, 11};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.GetLeftIndex(1000), 2001);
  EXPECT_EQ(bt.GetLeftIndex(10), 21);

  EXPECT_EQ(bt.GetLeftIndex(0), 1);

  EXPECT_EQ(bt.GetLeftIndex(1), 3);
  EXPECT_EQ(bt.GetLeftIndex(2), 5);

  EXPECT_EQ(bt.GetLeftIndex(3), 7);
  EXPECT_EQ(bt.GetLeftIndex(4), 9);

  EXPECT_EQ(bt.GetLeftIndex(5), 11);
  EXPECT_EQ(bt.GetLeftIndex(6), 13);
}

TEST(BinaryTree, GetRightIndex) {
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, 11};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.GetRightIndex(1000), 2002);
  EXPECT_EQ(bt.GetRightIndex(10), 22);

  EXPECT_EQ(bt.GetRightIndex(0), 2);

  EXPECT_EQ(bt.GetRightIndex(1), 4);
  EXPECT_EQ(bt.GetRightIndex(2), 6);

  EXPECT_EQ(bt.GetRightIndex(3), 8);
  EXPECT_EQ(bt.GetRightIndex(4), 10);

  EXPECT_EQ(bt.GetRightIndex(5), 12);
  EXPECT_EQ(bt.GetRightIndex(6), 14);
}

TEST(BinaryTree, FindMinWithGaps) {
  std::vector<int> in = {10, 1, 2, -1, 4, -1, 6, 7, 8, 9, -1, 11};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMin(0), 1);
}

TEST(BinaryTree, FindMinMiddle) {
  std::vector<int> in = {0, 1, 12, -1, 4, -1, 6, 7, 8, 9, -1, 1};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMin(2), 6);
}

TEST(BinaryTree, FindMinReverse) {
  std::vector<int> in = {5, 4, 3, 2, 1, 0};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMin(0), 0);
}

TEST(BinaryTree, FindMinReverseWithGaps) {
  std::vector<int> in = {5, 4, 3, -1, 1, 0};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMin(0), 0);
}

TEST(BinaryTree, FindMinEmpty) {
  std::vector<int> in;
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMin(0), INT_MAX);
}

TEST(BinaryTree, FindMinEmpty2) {
  std::vector<int> in = {-1, -1, -1, -1};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMin(0), INT_MAX);
}

TEST(BinaryTree, FindMaxWithGaps) {
  std::vector<int> in = {10, 1, 2, -1, 4, -1, 6, 7, 8, 9, -1, 11};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMax(0), 10);
}

TEST(BinaryTree, FindMaxReverse) {
  std::vector<int> in = {5, 4, 3, 2, 1, 0};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMax(0), 5);
}

TEST(BinaryTree, FindMaxReverseWithGaps) {
  std::vector<int> in = {5, 4, 3, -1, 1, 0};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMax(0), 5);
}

TEST(BinaryTree, FindMaxEmpty) {
  std::vector<int> in;
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMax(0), INT_MIN);
}

TEST(BinaryTree, FindMaxEmpty2) {
  std::vector<int> in = {-1, -1, -1, -1};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMax(0), INT_MIN);
}

TEST(BinaryTree, FindMaxMiddle) {
  std::vector<int> in = {0, 1, 2, -1, 4, -1, 6, 7, 8, 9, -1, 1};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_EQ(bt.FindMax(2), 6);
}
//-----------------------------------------------------------------------------
TEST(BinaryTree, PreOrder1) {
  std::vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto root = 0;
  std::cout << "root: " << root << std::endl;

  auto bt = BinaryTree(in);

  EXPECT_THAT(bt.PreOrder(root),
              ElementsAreArray({7, 3, 8, 1, 9, 4, 10, 0, 11, 5, 12, 2, 6}));
}

TEST(BinaryTree, PreOrder2) {
  std::vector<int> in = {0, 1, 2, -1, -1, 5, 6, -1, -1, 9, 10, 11, 12};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto root = 0;
  std::cout << "root: " << root << std::endl;
  auto bt = BinaryTree(in);

  EXPECT_THAT(bt.PreOrder(root), ElementsAreArray({1, 0, 11, 5, 12, 2, 6}));
}

TEST(BinaryTree, PreOrderMiddle) {
  std::vector<int> in = {0, 1, 2, -1, -1, 5, 6, -1, -1, 9, 10, 11, 12};
  std::cout << "Input: " << std::endl;
  PrintVector(in);
  auto root = 2;
  std::cout << "root: " << root << std::endl;
  auto bt = BinaryTree(in);

  EXPECT_THAT(bt.PreOrder(root), ElementsAreArray({11, 5, 12, 2, 6}));
}

TEST(BinaryTree, PreOrderInvalid) {
  std::vector<int> in = {0, 1, 2, -1, -1, 5, 6, -1, -1, 9, 10, 11, 12};
  std::cout << "Input: " << std::endl;
  auto root = 100;
  std::cout << "root: " << root << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_THAT(bt.PreOrder(root), IsEmpty());
}

TEST(BinaryTree, PreOrderNonExisting) {
  std::vector<int> in = {0, 1, 2, -1, -1, 5, 6, -1, -1, 9, 10, 11, 12};
  std::cout << "Input: " << std::endl;
  auto root = 4;
  std::cout << "root: " << root << std::endl;
  PrintVector(in);
  auto bt = BinaryTree(in);

  EXPECT_THAT(bt.PreOrder(root), IsEmpty());
}