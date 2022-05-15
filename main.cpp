#include <iostream>
#include "test.h"
#include "produs.h"
#include "repo.h"
#include "ServiceProdus.h"
#include "ui.h"
#include <cstdio>
#include "bani.h"
#include "repoBani.h"
#include "Service bani.h"
#include "ServiceTranzactie.h"
int main()
{
//    Test::testALll();
    Produs produs;
    Repo<Produs> repo;
    repo.readFromFile("repo.txt");
    ProdusService serv(repo);
    Bani bani;
    RepoB<Bani> repoB;
    repoB.readFromFileB("repoB.txt");
    BaniService servB(repoB);
    Service service{serv, servB};
    UI ui{serv, servB, service };
    ui.run();
    return 0;

}