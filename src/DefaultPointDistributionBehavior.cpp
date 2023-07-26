#include "DefaultPointDistributionBehavior.h"

void DefaultPointDistributionBehavior::addPointsToTableEntries(
    const std::shared_ptr<ITableEntry> &homeTeamTableEntry,
    const std::shared_ptr<ITableEntry> &awayTeamTableEntry,
    const GameResult &gameResult)
{
  std::shared_ptr<ITeam> winningTeam = gameResult.getWinningTeam();

  if (winningTeam == NULL)
  {
    homeTeamTableEntry->addPoints(PointsInCaseOfDraw);
    awayTeamTableEntry->addPoints(PointsInCaseOfDraw);

    return;
  }

  if (winningTeam == homeTeamTableEntry->getTeam())
  {
    homeTeamTableEntry->addPoints(PointsInCaseOfWin);
  }

  if (winningTeam == awayTeamTableEntry->getTeam())
  {
    awayTeamTableEntry->addPoints(PointsInCaseOfWin);
  }
}
