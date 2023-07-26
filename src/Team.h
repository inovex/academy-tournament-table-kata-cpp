#pragma once

#include <string>

class ITeam
{
public:
  virtual std::string getName() const = 0;
};

class Team : public ITeam
{
private:
  std::string name;

public:
  Team(const std::string _name) : name(_name){};

  inline std::string getName() const { return name; };
};
