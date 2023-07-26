#include "GameResult.h"
#include "gtest/gtest.h"

class GameResultTests : public ::testing::Test
{
protected:
  std::shared_ptr<ITeam> changeFirstTeamName;
  std::shared_ptr<ITeam> changeSecondTeamName;

  virtual void SetUp()
  {
    changeFirstTeamName = std::make_shared<Team>("FirstTeam");
    changeSecondTeamName = std::make_shared<Team>("SecondTeam");
  }
  virtual void TearDown()
  {
    changeFirstTeamName.reset();
    changeSecondTeamName.reset();
  }
};

TEST_F(GameResultTests, mySuperDuperTestName)
{
  // TODO
}