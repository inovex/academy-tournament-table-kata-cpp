#include "GameResult.h"

GameResult::GameResult(const std::shared_ptr<ITeam> _homeTeam,
                       const std::shared_ptr<ITeam> _awayTeam,
                       int _homeTeamGoals, int _awayTeamGoals)
    : homeTeam(_homeTeam), awayTeam(_awayTeam), homeTeamGoals(_homeTeamGoals),
      awayTeamGoals(_awayTeamGoals)
{
  if (homeTeam == NULL)
  {
    throw RuntimeException("Hometeam not specified");
  }

  if (awayTeam == NULL)
  {
    throw RuntimeException("Awayteam not specified");
  }
}

const std::shared_ptr<ITeam> GameResult::getHomeTeam() const
{
  return homeTeam;
}

const std::shared_ptr<ITeam> GameResult::getAwayTeam() const
{
  return awayTeam;
}

int GameResult::getHomeTeamGoals() const { return homeTeamGoals; }

int GameResult::getAwayTeamGoals() const { return awayTeamGoals; }

bool GameResult::isDraw() const { return homeTeamGoals == awayTeamGoals; }

const std::shared_ptr<ITeam> GameResult::getWinningTeam() const
{
  if (homeTeamGoals > awayTeamGoals)
  {
    return homeTeam;
  }

  if (awayTeamGoals > homeTeamGoals)
  {
    return awayTeam;
  }

  return NULL;
}