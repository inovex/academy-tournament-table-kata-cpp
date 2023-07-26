#pragma once

#include "Exceptions.h"
#include "Team.h"
#include <memory>

class GameResult
{
private:
  const std::shared_ptr<ITeam> homeTeam;
  const std::shared_ptr<ITeam> awayTeam;
  int homeTeamGoals;
  int awayTeamGoals;

public:
  GameResult(const std::shared_ptr<ITeam> _homeTeam,
             const std::shared_ptr<ITeam> _awayTeam, int _homeTeamGoals,
             int _awayTeamGoals);

  const std::shared_ptr<ITeam> getHomeTeam() const;
  const std::shared_ptr<ITeam> getAwayTeam() const;
  int getHomeTeamGoals() const;
  int getAwayTeamGoals() const;
  bool isDraw() const;
  const std::shared_ptr<ITeam> getWinningTeam() const;
};
