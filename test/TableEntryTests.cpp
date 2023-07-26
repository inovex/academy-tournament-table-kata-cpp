#include "TableEntry.h"
#include "gtest/gtest.h"

class TableEntryTests : public ::testing::Test
{
protected:
  std::shared_ptr<ITableEntry> tableEntry;
  std::shared_ptr<ITeam> germany;
  int zero = 0;

  virtual void SetUp()
  {
    tableEntry = std::make_shared<TableEntry>();
    germany = std::make_shared<Team>("Germany");
  }
  virtual void TearDown()
  {
    tableEntry.reset();
    germany.reset();
  }
};

TEST_F(TableEntryTests, toString_TableEntryWithTeam_ReturnsExpectedString)
{
  const char *expected = "Germany 0 0:0";
  tableEntry->setTeam(germany);

  std::string result = tableEntry->toString();

  ASSERT_STREQ(expected, result.c_str());
}

TEST_F(TableEntryTests,
       toString_TableEntryWithTeamPointsAndGoals_ReturnsExpectedString)
{
  const char *expected = "Germany 3 4:2";
  tableEntry->setTeam(germany);
  tableEntry->addPoints(3);
  tableEntry->addGoalsScored(4);
  tableEntry->addGoalsAgainst(2);

  std::string result = tableEntry->toString();

  ASSERT_STREQ(expected, result.c_str());
}

TEST_F(TableEntryTests, addGoalsScored_SomeGoals_SumsTheAddedGoalsUp)
{
  int expectedGoals = 5;
  int firstGoals = 2;
  int secondGoals = 3;

  tableEntry->addGoalsScored(firstGoals);
  tableEntry->addGoalsScored(secondGoals);

  int points = tableEntry->getGoalsScored();
  ASSERT_EQ(expectedGoals, points);
}

TEST_F(TableEntryTests, addGoalsAgainst_SomeGoals_SumsTheAddedGoalsUp)
{
  int expectedGoals = 5;
  int firstGoals = 2;
  int secondGoals = 3;

  tableEntry->addGoalsAgainst(firstGoals);
  tableEntry->addGoalsAgainst(secondGoals);

  int points = tableEntry->getGoalsAgainst();
  ASSERT_EQ(expectedGoals, points);
}

TEST_F(TableEntryTests, getGoalsScored_DefaultTableEntry_ReturnsZero)
{
  int goalsScored = tableEntry->getGoalsScored();

  ASSERT_EQ(zero, goalsScored);
}

TEST_F(TableEntryTests, getGoalsScored_SomeGoalsScored_ReturnsExpectedGoals)
{
  int someGoals = 5;
  tableEntry->addGoalsScored(someGoals);

  int points = tableEntry->getGoalsScored();

  ASSERT_EQ(someGoals, points);
}

TEST_F(TableEntryTests, getGoalsAgainst_DefaultTableEntry_ReturnsZero)
{
  int goalsAgainst = tableEntry->getGoalsAgainst();

  ASSERT_EQ(zero, goalsAgainst);
}

TEST_F(TableEntryTests, getGoalsAgainst_SomeGoalsAgainst_ReturnsExpectedGoals)
{
  int someGoals = 5;
  tableEntry->addGoalsAgainst(someGoals);

  int points = tableEntry->getGoalsAgainst();

  ASSERT_EQ(someGoals, points);
}

TEST_F(TableEntryTests, addPoints_SomePoints_SumsTheAddedPointsUp)
{
  int expectedPoints = 7;
  int firstPoints = 4;
  int secondPoints = 3;

  tableEntry->addPoints(firstPoints);
  tableEntry->addPoints(secondPoints);

  int points = tableEntry->getPoints();
  ASSERT_EQ(expectedPoints, points);
}

TEST_F(TableEntryTests, getPoints_DefaultTableEntry_ReturnsZero)
{
  int points = tableEntry->getPoints();

  ASSERT_EQ(zero, points);
}

TEST_F(TableEntryTests, getPoints_SomePointsAdded_ReturnsExpectedPoints)
{
  int somePoints = 5;
  tableEntry->addPoints(somePoints);

  int points = tableEntry->getPoints();

  ASSERT_EQ(somePoints, points);
}

TEST_F(TableEntryTests, getTeam_DefaultTableEntry_ReturnsNull)
{
  std::shared_ptr<ITeam> team = tableEntry->getTeam();

  ASSERT_EQ(nullptr, team);
}

TEST_F(TableEntryTests, getTeam_TeamIsSet_ReturnsExpectedTeam)
{
  tableEntry->setTeam(germany);

  std::shared_ptr<ITeam> team = tableEntry->getTeam();

  ASSERT_EQ(germany, team);
}