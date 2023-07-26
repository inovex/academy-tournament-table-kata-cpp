#include "Table.h"
#include <iostream>
#include <memory>

int main()
{
  std::shared_ptr<ITeam> germany = std::make_shared<Team>("Germany");
  std::shared_ptr<ITeam> netherlands = std::make_shared<Team>("Netherlands");
  std::shared_ptr<ITeam> england = std::make_shared<Team>("England");
  std::shared_ptr<ITeam> italy = std::make_shared<Team>("Italy");

  Table table;

  // First round
  GameResult germanAgainstNetherlands(germany, netherlands, 1, 0);
  GameResult italyAgainstEngland(italy, england, 2, 3);
  table.bookGameResultToTable(germanAgainstNetherlands);
  table.bookGameResultToTable(italyAgainstEngland);

  // Second round
  GameResult germanAgainstItaly(germany, italy, 4, 2);
  GameResult netherlandsAgainstEngland(netherlands, england, 2, 3);
  table.bookGameResultToTable(germanAgainstItaly);
  table.bookGameResultToTable(netherlandsAgainstEngland);

  // Third round
  GameResult germanAgainstEngland(germany, england, 1, 0);
  GameResult italyAgainstNetherlands(italy, netherlands, 2, 2);
  table.bookGameResultToTable(germanAgainstEngland);
  table.bookGameResultToTable(italyAgainstNetherlands);

  std::cout << table.toString() << std::endl;

  return 0;
}
