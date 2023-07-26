#include "TableEntry.h"

void TableEntry::addGoalsScored(int _goalsScored)
{
  goalsScored += _goalsScored;
}

void TableEntry::addGoalsAgainst(int _goalsAgainst)
{
  goalsAgainst += _goalsAgainst;
}

void TableEntry::addPoints(int _points) { points += _points; }

std::shared_ptr<ITeam> TableEntry::getTeam() const { return team; }

void TableEntry::setTeam(std::shared_ptr<ITeam> _team) { team = _team; }

int TableEntry::getPoints() const { return points; }

int TableEntry::getGoalsScored() const { return goalsScored; }

int TableEntry::getGoalsAgainst() const { return goalsAgainst; }

std::string TableEntry::toString() const
{
  std::string result;

  result.append(team->getName());
  result.append(" ");
  result.append(std::to_string(points));
  result.append(" ");
  result.append(std::to_string(goalsScored));
  result.append(":");
  result.append(std::to_string(goalsAgainst));

  return result;
}