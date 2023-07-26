#pragma once

#include "Team.h"
#include <memory>

class ICoefficientClient
{
public:
  virtual int getCoefficient(std::shared_ptr<ITeam> team) const = 0;
};

class CoefficientClient : public ICoefficientClient
{
public:
  int getCoefficient(std::shared_ptr<ITeam> team) const;
};