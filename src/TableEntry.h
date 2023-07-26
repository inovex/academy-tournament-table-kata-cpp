#pragma once

#include "Team.h"
#include <memory>

class ITableEntry
{
public:
  virtual void addPoints(int _points) = 0;
  virtual int getPoints() const = 0;

  virtual void addGoalsScored(int _goalsScored) = 0;
  virtual int getGoalsScored() const = 0;

  virtual void addGoalsAgainst(int _goalsAgainst) = 0;
  virtual int getGoalsAgainst() const = 0;

  virtual void setTeam(std::shared_ptr<ITeam> _team) = 0;
  virtual std::shared_ptr<ITeam> getTeam() const = 0;

  virtual std::string toString() const = 0;
};

class TableEntry : public ITableEntry
{
private:
  std::shared_ptr<ITeam> team;
  int goalsScored = 0;
  int goalsAgainst = 0;
  int points = 0;

public:
  void addPoints(int _points);
  int getPoints() const;

  void addGoalsScored(int _goalsScored);
  int getGoalsScored() const;

  void addGoalsAgainst(int _goalsAgainst);
  int getGoalsAgainst() const;

  void setTeam(std::shared_ptr<ITeam> _team);
  std::shared_ptr<ITeam> getTeam() const;

  std::string toString() const;
};
