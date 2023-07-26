#include "GameResult.h"
#include "gtest/gtest.h"

class GameResultTests : public ::testing::Test
{
protected:
  std::shared_ptr<ITeam> germany;
  std::shared_ptr<ITeam> england;

  virtual void SetUp()
  {
    germany = std::make_shared<Team>("Germany");
    england = std::make_shared<Team>("England");
  }
  virtual void TearDown()
  {
    germany.reset();
    england.reset();
  }
};

TEST_F(GameResultTests, getWinningTeam_HomeTeamWon_ReturnsHomeTeam)
{
  GameResult gameResult(germany, england, 6, 5);

  std::shared_ptr<ITeam> winningTeam = gameResult.getWinningTeam();

  ASSERT_EQ(germany, winningTeam);
}

TEST_F(GameResultTests, getWinningTeam_AwayTeamWon_ReturnsAwayTeam)
{
  GameResult gameResult(germany, england, 2, 5);

  std::shared_ptr<ITeam> winningTeam = gameResult.getWinningTeam();

  ASSERT_EQ(england, winningTeam);
}

TEST_F(GameResultTests, getWinningTeam_Draw_RetrunsNull)
{
  GameResult gameResult(germany, england, 2, 2);

  std::shared_ptr<ITeam> winningTeam = gameResult.getWinningTeam();

  ASSERT_EQ(nullptr, winningTeam);
}

TEST_F(GameResultTests, isDraw_HomeTeamWon_ReturnsFalse)
{
  GameResult gameResult(germany, england, 6, 5);

  bool result = gameResult.isDraw();

  ASSERT_FALSE(result);
}

TEST_F(GameResultTests, isDraw_AwayTeamWon_ReturnsFalse)
{
  GameResult gameResult(germany, england, 2, 5);

  bool result = gameResult.isDraw();

  ASSERT_FALSE(result);
}

TEST_F(GameResultTests, isDraw_Draw_ReturnsTrue)
{
  GameResult gameResult(germany, england, 2, 2);

  bool result = gameResult.isDraw();

  ASSERT_TRUE(result);
}

TEST_F(GameResultTests, constructor_HomeTeamNull_ThrowsException)
{
  ASSERT_THROW(new GameResult(nullptr, england, 0, 0), RuntimeException);
}

TEST_F(GameResultTests, constructor_AwayTeamNull_ThrowsException)
{
  ASSERT_THROW(new GameResult(germany, nullptr, 0, 0), RuntimeException);
}