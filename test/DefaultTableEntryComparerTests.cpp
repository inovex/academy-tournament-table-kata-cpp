#include "DefaultTableEntryComparer.h"
#include "gtest/gtest.h"

class CoefficientClientMock : public ICoefficientClient
{
public:
  std::map<std::shared_ptr<ITeam>, int> returnValue;
  mutable bool wasCalled = false;

  int getCoefficient(std::shared_ptr<ITeam> team) const
  {
    wasCalled = true;
    return returnValue.find(team)->second;
  }
};

class DefaultTableEntryComparerTests : public ::testing::Test
{
protected:
  std::shared_ptr<ITableEntryComparer> tableEntryComparer;
  std::shared_ptr<ITeam> germany;
  std::shared_ptr<ITeam> england;
  std::shared_ptr<ITableEntry> germanyTableEntry;
  std::shared_ptr<ITableEntry> englandTableEntry;
  std::shared_ptr<CoefficientClientMock> coefficientClientMock;

  virtual void SetUp()
  {
    coefficientClientMock = std::make_shared<CoefficientClientMock>();

    tableEntryComparer =
        std::make_shared<DefaultTableEntryComparer>(coefficientClientMock);

    germany = std::make_shared<Team>("Germany");
    england = std::make_shared<Team>("England");

    germanyTableEntry = std::make_shared<TableEntry>();
    germanyTableEntry->setTeam(germany);

    englandTableEntry = std::make_shared<TableEntry>();
    englandTableEntry->setTeam(england);
  }
  virtual void TearDown()
  {
    tableEntryComparer.reset();

    germany.reset();
    england.reset();

    germanyTableEntry.reset();
    englandTableEntry.reset();

    coefficientClientMock.reset();
  }
};

TEST_F(DefaultTableEntryComparerTests,
       greaterThan_FirstTeamHasMorePoints_RetrunsFalse)
{
  germanyTableEntry->addPoints(2);
  englandTableEntry->addPoints(1);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_TRUE(result);
}

TEST_F(DefaultTableEntryComparerTests,
       greaterThan_FirstTeamHasLessPoints_RetrunsFalse)
{
  germanyTableEntry->addPoints(1);
  englandTableEntry->addPoints(2);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_FALSE(result);
}

TEST_F(
    DefaultTableEntryComparerTests,
    greaterThan_BothTeamsHaveSamePointsAndFirstTeamLessGoalDifference_RetrunsFalse)
{
  germanyTableEntry->addPoints(1);
  englandTableEntry->addPoints(1);
  germanyTableEntry->addGoalsScored(1);
  englandTableEntry->addGoalsScored(2);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_FALSE(result);
}

TEST_F(
    DefaultTableEntryComparerTests,
    greaterThan_BothTeamsHaveSamePointsAndFirstTeamGreaterGoalDifference_RetrunsFalse)
{
  germanyTableEntry->addPoints(1);
  englandTableEntry->addPoints(1);
  germanyTableEntry->addGoalsScored(2);
  englandTableEntry->addGoalsScored(1);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_TRUE(result);
}

TEST_F(
    DefaultTableEntryComparerTests,
    greaterThan_BothTeamsHaveSamePointsAndSameGoalDifferenceAndSameCoefficient_RetrunsFalse)
{
  coefficientClientMock->returnValue.insert(
      std::pair<std::shared_ptr<ITeam>, int>(germany, 1));
  coefficientClientMock->returnValue.insert(
      std::pair<std::shared_ptr<ITeam>, int>(england, 1));
  germanyTableEntry->addPoints(1);
  englandTableEntry->addPoints(1);
  germanyTableEntry->addGoalsScored(1);
  englandTableEntry->addGoalsScored(1);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_FALSE(result);
}

TEST_F(
    DefaultTableEntryComparerTests,
    greaterThan_BothTeamsHaveSamePointsAndSameGoalDifferenceAndFirstTeamLessCoefficient_RetrunsFalse)
{
  coefficientClientMock->returnValue.insert(
      std::pair<std::shared_ptr<ITeam>, int>(germany, 1));
  coefficientClientMock->returnValue.insert(
      std::pair<std::shared_ptr<ITeam>, int>(england, 2));
  germanyTableEntry->addPoints(1);
  englandTableEntry->addPoints(1);
  germanyTableEntry->addGoalsScored(1);
  germanyTableEntry->addGoalsAgainst(2);
  englandTableEntry->addGoalsScored(2);
  englandTableEntry->addGoalsAgainst(3);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_FALSE(result);
}

TEST_F(
    DefaultTableEntryComparerTests,
    greaterThan_BothTeamsHaveSamePointsAndSameGoalDifferenceAndFirstTeamGreaterCoefficient_RetrunsFalse)
{
  coefficientClientMock->returnValue.insert(
      std::pair<std::shared_ptr<ITeam>, int>(germany, 2));
  coefficientClientMock->returnValue.insert(
      std::pair<std::shared_ptr<ITeam>, int>(england, 1));
  germanyTableEntry->addPoints(1);
  englandTableEntry->addPoints(1);
  germanyTableEntry->addGoalsScored(2);
  germanyTableEntry->addGoalsAgainst(3);
  englandTableEntry->addGoalsScored(1);
  englandTableEntry->addGoalsAgainst(2);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_TRUE(result);
}

TEST_F(DefaultTableEntryComparerTests,
       greaterThan_FirstTeamHasMorePoints_CoefficientClientIsNotCalled)
{
  germanyTableEntry->addPoints(2);
  englandTableEntry->addPoints(1);

  bool result =
      tableEntryComparer->greaterThan(*germanyTableEntry, *englandTableEntry);

  ASSERT_FALSE(coefficientClientMock->wasCalled);
}