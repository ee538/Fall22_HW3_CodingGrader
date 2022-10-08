#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;
using ::testing::UnorderedElementsAre;
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(SinglyLinkedList, PushBackWorks) {
  SinglyLinkedList l;
  l.push_back(2);

  EXPECT_EQ(l[0], 2);
  EXPECT_EQ(l[1], -1);
  EXPECT_EQ(l[200], -1);
}

TEST(SinglyLinkedList, PopBackWorks) {
  SinglyLinkedList l;
  l.push_back(0);
  l.push_back(1);
  l.push_back(2);

  EXPECT_TRUE(l.pop_back());

  EXPECT_EQ(l[0], 0);
  EXPECT_EQ(l[1], 1);
  EXPECT_EQ(l.size(), 2);
}

TEST(SinglyLinkedList, PopBackWorksEmpty) {
  SinglyLinkedList l;
  EXPECT_FALSE(l.pop_back());
  EXPECT_TRUE(l.empty());
}

TEST(SinglyLinkedList, EraseWorks) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(0);

  EXPECT_EQ(l[0], 2);
  EXPECT_EQ(l[1], 3);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual, nullptr);
}

TEST(SinglyLinkedList, EraseWorksMiddle) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(1);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 3);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual->val, 1);
}

TEST(SinglyLinkedList, EraseWorksEnd) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(2);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 2);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual->val, 2);
}

TEST(SinglyLinkedList, EraseWorksOutside) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(3);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 2);
  EXPECT_EQ(l[2], 3);
  EXPECT_EQ(l.size(), 3);
  EXPECT_EQ(actual, nullptr);
}

TEST(SinglyLinkedList, ConvertToVectorWorks) {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({1, 2, 3}));
}

TEST(SinglyLinkedList, ConvertToVectorEmpty) {
  SinglyLinkedList l;

  auto actual = l.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}

TEST(SinglyLinkedList, ConstructorWorks) {
  SinglyLinkedList l({0, 1, 2, 3});

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, CopyConstructorWorks) {
  SinglyLinkedList l1({0, 1, 2, 3});
  SinglyLinkedList l2 = l1;
  auto actual = l2.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, CopyConstructorWorksEmpty) {
  SinglyLinkedList l1;
  SinglyLinkedList l2 = l1;
  auto actual = l2.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}

TEST(SinglyLinkedList, RemoveDuplicatesWorks) {
  SinglyLinkedList l({0, 1, 2, 3, 1});
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksMoreNumbers) {
  SinglyLinkedList l({0, 1, 2, 3, 1, 2, 2, 3, 3, 1, 0, 0, 4});
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3, 4}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksNoDuplicates) {
  SinglyLinkedList l({0, 1, 2, 3, 4});
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3, 4}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksEmpty) {
  SinglyLinkedList l;
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}