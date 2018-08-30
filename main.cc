#include <iostream>
#include <vector>
#include "player.h"
#include "player_simple.h"
#include "player_basic.h"
#include "tournament.h"
#include "trace.h"

#ifdef ENABLE_TRACE
std::ostream *gpTrace = 0;
#endif

const int numGames = 1;

int main(int argc, char **argv)
{
   int c;

   while ((c = getopt(argc, argv, "t:h")) != -1)
   {
      switch (c)
      {
#ifdef ENABLE_TRACE
         case 't' : gpTrace = new CTrace(optarg); break;
#else
         case 't' : std::cout << "Trace not supported" << std::endl; return 1;
#endif
         case 'h' :
         default : {
                      std::cout <<  "Options:" << std::endl;
                      std::cout << "-t <file> : Trace search to file" << std::endl;
                      std::cout << "-h        : Show this message" << std::endl;
                      exit(1);
                   }
      } // end of switch
   } // end of while

   srand(time(0));

   std::vector<Player *> players;

   players.push_back(new PlayerSimple());
   players.push_back(new PlayerBasic());

   Tournament t(players, numGames);
   
   t.play();

} // end of main

