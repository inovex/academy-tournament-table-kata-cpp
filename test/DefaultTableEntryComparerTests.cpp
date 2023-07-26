#include "DefaultTableEntryComparer.h"
#include "gtest/gtest.h"

class DefaultTableEntryComparerTests : public ::testing::Test {
protected:
  std::shared_ptr<ITableEntryComparer> tableEntryComparer;
  std::shared_ptr<ITableEntry> germanyTableEntry;
  std::shared_ptr<ITableEntry> englandTableEntry;

  virtual void SetUp() {
    tableEntryComparer = std::make_shared<DefaultTableEntryComparer>();

    germanyTableEntry = std::make_shared<TableEntry>();
    englandTableEntry = std::make_shared<TableEntry>();
  }
  virtual void TearDown() {
    tableEntryComparer.reset();

    germanyTableEntry.reset();
    englandTableEntry.reset();
  }
};

TEST_F(DefaultTableEntryComparerTests,
       greaterThan_BothTeamsHaveSamePoints_RetrunsFalse) {
  germanyTableEntry->addPoints(1);
  englandTableEntry->addPoints(1);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_FALSE(result);
}

TEST_F(DefaultTableEntryComparerTests,
       greaterThan_FirstTeamHasMorePoints_RetrunsFalse) {
  germanyTableEntry->addPoints(2);
  englandTableEntry->addPoints(1);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_TRUE(result);
}

TEST_F(DefaultTableEntryComparerTests,
       greaterThan_FirstTeamHasLessPoints_RetrunsFalse) {
  germanyTableEntry->addPoints(1);
  englandTableEntry->addPoints(2);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_FALSE(result);
}