#include "DefaultPointDistributionBehavior.h"
#include "gtest/gtest.h"

class DefaultPointDistributionBehaviorTests : public ::testing::Test
{
protected:
  std::shared_ptr<IPointDistributionBehavior> pointDistributionBehavior;
  std::shared_ptr<ITeam> changeFirstTeamName;
  std::shared_ptr<ITeam> changeSecondTeamName;
  std::shared_ptr<ITableEntry> firstTeamTableEntry;
  std::shared_ptr<ITableEntry> secondTableEntry;

  virtual void SetUp()
  {
    pointDistributionBehavior =
        std::make_shared<DefaultPointDistributionBehavior>();

    changeFirstTeamName = std::make_shared<Team>("first");
    changeSecondTeamName = std::make_shared<Team>("second");

    firstTeamTableEntry = std::make_shared<TableEntry>();
    firstTeamTableEntry->setTeam(changeFirstTeamName);

    secondTableEntry = std::make_shared<TableEntry>();
    secondTableEntry->setTeam(changeSecondTeamName);
  }
  virtual void TearDown()
  {
    pointDistributionBehavior.reset();

    firstTeamTableEntry.reset();
    secondTableEntry.reset();

    changeFirstTeamName.reset();
    changeSecondTeamName.reset();
  }
};

TEST_F(DefaultPointDistributionBehaviorTests, whatShouldITest)
{
  // TODO
}
