#include "DefaultPointDistributionBehavior.h"
#include "gtest/gtest.h"

class DefaultPointDistributionBehaviorTests : public ::testing::Test
{
protected:
  std::shared_ptr<IPointDistributionBehavior> pointDistributionBehavior;
  std::shared_ptr<ITeam> germany;
  std::shared_ptr<ITeam> england;
  std::shared_ptr<ITableEntry> germanyTableEntry;
  std::shared_ptr<ITableEntry> englandTableEntry;
  const int zeroPoints = 0;
  const int winningPoints = 3;
  const int drawPoints = 1;

  virtual void SetUp()
  {
    pointDistributionBehavior =
        std::make_shared<DefaultPointDistributionBehavior>();

    germany = std::make_shared<Team>("Germany");
    england = std::make_shared<Team>("England");

    germanyTableEntry = std::make_shared<TableEntry>();
    germanyTableEntry->setTeam(germany);

    englandTableEntry = std::make_shared<TableEntry>();
    englandTableEntry->setTeam(england);
  }
  virtual void TearDown()
  {
    pointDistributionBehavior.reset();

    germanyTableEntry.reset();
    englandTableEntry.reset();

    germany.reset();
    england.reset();
  }
};

TEST_F(DefaultPointDistributionBehaviorTests,
       addPointsToTableEntries_HomeTeamWon_HomeTeamGetPoints)
{
  GameResult gameResult(germany, england, 1, 0);

  pointDistributionBehavior->addPointsToTableEntries(
      germanyTableEntry, englandTableEntry, gameResult);

  ASSERT_EQ(winningPoints, germanyTableEntry->getPoints());
  ASSERT_EQ(zeroPoints, englandTableEntry->getPoints());
}

TEST_F(DefaultPointDistributionBehaviorTests,
       addPointsToTableEntries_AwayTeamWon_AwayTeamGetPoints)
{
  GameResult gameResult(germany, england, 0, 1);

  pointDistributionBehavior->addPointsToTableEntries(
      germanyTableEntry, englandTableEntry, gameResult);

  ASSERT_EQ(zeroPoints, germanyTableEntry->getPoints());
  ASSERT_EQ(winningPoints, englandTableEntry->getPoints());
}

TEST_F(DefaultPointDistributionBehaviorTests,
       addPointsToTableEntries_Draw_BothTeamsGetPoints)
{
  GameResult gameResult(germany, england, 0, 0);

  pointDistributionBehavior->addPointsToTableEntries(
      germanyTableEntry, englandTableEntry, gameResult);

  ASSERT_EQ(drawPoints, germanyTableEntry->getPoints());
  ASSERT_EQ(drawPoints, englandTableEntry->getPoints());
}