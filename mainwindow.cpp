#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QColor>
#include <QProgressDialog>

#include <csv_writedata_rest.cpp>
#include <csv_writedata_teamType.cpp>
#include <csv_writedata_playerType.cpp>

#include <free_forloop_and_randomize_functions.cpp>

using namespace QtConcurrent;


void MainWindow::LblNvalueChanged()
{
    n = ui -> SpnBoxAnzahl -> value();
    ui -> LblN -> setNum(n);
}
void MainWindow::LblNatCntryCurrentRowChanged()
{
    nat = natId.at(ui -> LstCountry -> currentRow() );
    cntry = teamCntryId.at(ui -> LstCountry -> currentRow() );
    ui -> LblNat -> setNum(nat);
    ui -> LblCntry -> setNum(cntry);
}

void MainWindow::CmdWriteDataClicked()
{
    ui -> SpnBoxAnzahl -> setDisabled(true);
    ui -> SldAnzahl -> setDisabled(true);
    ui -> LstCountry -> setDisabled(true);
    ui -> CmdWriteData -> setDisabled(true);
    ui -> CmdBeenden -> setDisabled(true);

    ui -> PgrDataWrite -> setValue(0);
    ui -> LblFertig -> setStyleSheet("color: crimson");
    ui -> LblFertig -> setText("In Progress");

    QFile teamsFileR("teams.csv");
    int id = fetchesHighestId(teamsFileR);

    QFile playerFileR("playerwrite.csv");
    int pid = fetchesHighestId(playerFileR);

    int tempVar = id;
    QString tempStr = QString::number(tempVar);
    tempStr.push_back('0');
    int textId = tempStr.toInt();
    textId += ADD_TO_TEXT_ID;

    QVector<int> position = {0, 3, 4, POSITION_LEFT_CENTRAL_BACK, POSITION_LEFT_BACK,
                             POSITION_RIGHT_MIDFIELDER, POSITION_RIGHT_CENTRAL_MIDFIELDER, POSITION_LEFT_CENTRAL_MIDFIELDER,
                             POSITION_LEFT_MIDFIELDER, POSITION_RIGHT_STRIKER, POSITION_LEFT_STRIKER, POSITION_SUBSTITUTE,
                             POSITION_SUBSTITUTE, POSITION_SUBSTITUTE, POSITION_SUBSTITUTE, POSITION_SUBSTITUTE,
                             POSITION_SUBSTITUTE, POSITION_SUBSTITUTE};

    QVector<int> position2 = {0, 3, 4, POSITION_LEFT_CENTRAL_BACK, POSITION_LEFT_BACK,
                              POSITION_RIGHT_MIDFIELDER, POSITION_RIGHT_CENTRAL_MIDFIELDER, POSITION_LEFT_CENTRAL_MIDFIELDER,
                              POSITION_LEFT_MIDFIELDER, POSITION_CENTRAL_STRIKER, POSITION_CENTRAL_STRIKER, 0, POSITION_CENTRAL_BACK, 3,
                              POSITION_CENTRAL_MIDFIELDER, POSITION_RIGHT_MIDFIELDER, POSITION_RIGHT_WING_MIDFIELDER, POSITION_RIGHT_STRIKER};
    if(NUMBER_OF_PLAYERS_PER_TEAM > 18)
    {
        for(int i = 0; i < NUMBER_OF_PLAYERS_PER_TEAM - 18; ++i)
        {
            position.append(POSITION_TRIBUNE);
            position2.append(POSITION_CENTRAL_DEFENSE_MIDFIELDER);
        }
    }
    int jrn = 0;
    int idx = 0;
    int ix = 0;
    QVector<int> yc = {2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012};
    QVector<int> re = {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48};
    QVector<teamType> teams;
    QVector<teamType> teamKits;
    QVector<teamCountryType> tCoun;
    QVector<playerType> player;
    QVector<playerTeamType> teamPlayerLinks;
    QVector<textIdType> teId;

    n = ui -> SpnBoxAnzahl -> value();
    nat = natId.at(ui -> LstCountry -> currentRow() );
    cntry = teamCntryId.at(ui -> LstCountry -> currentRow() );

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    for(int i = 0; i < n; ++i)
    {
        ++id;
        teams.append(teamType(id, pid + SHIFT_TO_STANDARD_KICKER_ID_AND_CAPTAIN, pid + SHIFT_TO_STANDARD_KICKER_ID_AND_CAPTAIN,
                              pid + SHIFT_TO_STANDARD_KICKER_ID_AND_CAPTAIN, pid + SHIFT_TO_STANDARD_KICKER_ID_AND_CAPTAIN,
                              pid + SHIFT_TO_STANDARD_KICKER_ID_AND_CAPTAIN) );

        teamKits.append(teamType(id, 0, 0, 1, 1, 1, 2, 4, 0, JERSEY_FONT_SIZE, 1, JERSEY_DOUBLED_DIGIT_FONT_SIZE,
                                 0, 2, 1, 1, 1, 0, 1, 1, 1, 1, SHORT_NUMBER_FONT_SIZE, 2, 0, 0, 0, 1, 1, 1, 1, 1,
                                 SHORTS_NUMBER_HOT_SPOT_ID, 0, 0, 0) );

        teamKits.append(teamType(id, 1, 0, 1, 1, 1, 2, 4, 0, JERSEY_FONT_SIZE, 1, JERSEY_DOUBLED_DIGIT_FONT_SIZE,
                                 0, 2, HEX_COLOR_C54C17, HEX_COLOR_C54C17, HEX_COLOR_C54C17, 0, HEX_COLOR_C54C17,
                                 HEX_COLOR_C54C17, HEX_COLOR_C54C17, 1, SHORT_NUMBER_FONT_SIZE, 2, 0, 0, 0, HEX_COLOR_C54C17,
                                 HEX_COLOR_C54C17, HEX_COLOR_C54C17, 1, 1, SHORTS_NUMBER_HOT_SPOT_ID, 0, 0, 0) );

        tCoun.append(teamCountryType(id, cntry) );
        textId += ADD_TO_TEXT_ID_IN_FOR_LOOP;
        teId.append(textIdType(textId, "Lorem Ipsum FC") );
        teId.append(textIdType(textId + 1, "Lor") );
        teId.append(textIdType(textId + 2, "Lorem Ipsum") );
        for(int i = 0; i < NUMBER_OF_PLAYERS_PER_TEAM; ++i)
        {
            ++pid;
            ++jrn;

            do
            {
                idx = randMemberPoisson(gen, MEAN);
            }
            while(idx > yc.size() - 1);

            int sc = randMemberUniform(gen, 1, MAX_ID_OF_SCHOE_COLOR);
            int cel = randMemberUniform(gen, 0, MAX_ID_OF_CELEBRATION);
            int lmht = randMemberUniform(gen, 0, MAX_ID_OF_LOW_MED_HAIR_TYPE);
            do
            {
                ix = randMemberPoisson(gen, MEAN_RETIRE);
            }
            while(ix > re.size() - 1);
            int pref = randMemberBernoulli(gen, STATISTIC_SHARE_OF_LEFT_FOOT);
            int inju = randMemberBernoulli(gen, SHARE_OF_INJURYPRONE_IS_TRUE);

            player.append(playerType(pid, yc.at(idx), sc, cel, lmht, re.at(ix),  pref, inju, position2.at(i), nat) );
            teamPlayerLinks.append(playerTeamType(id, pid, jrn, position.at(i) ) );
        }
        jrn = 0;
    }
    QString filePath = {};

    filePath = "players.csv";
    QFuture<void> f1 = run(writePlayersDataForLoop2, player, filePath);

    filePath = "playerwrite.csv";
    QFuture<void> f2 = run(writePlayersDataForLoop, player, filePath);

    filePath = "language.csv";
    QFuture<void> f3 = run(writeTextIdForLoop, teId, filePath);  

    filePath = "teamplayerlinks.csv";
    QFuture<void> f4 = run(writeTeamPlayerLinksForLoop, teamPlayerLinks, filePath);   

    filePath = "teamkits.csv";
    QFuture<void> f5 = run(writeTeamKitsForLoop, teamKits, filePath);   

    filePath = "teamwrite.csv";
    QFuture<void> f6 = run(writeTeamsForLoop, teams, filePath);

    filePath = "teams.csv";
    QFuture<void> f7 = run(writeTeamDataForLoop, teams, filePath);

    filePath = "team_country.csv";
    QFuture<void> f8 = run(writeTeamCountryForLoop, tCoun, filePath);

    f1.waitForFinished();
    f2.waitForFinished();
    f3.waitForFinished();
    f4.waitForFinished();
    f5.waitForFinished();
    f6.waitForFinished();
    f7.waitForFinished();
    f8.waitForFinished(); 


    QFile ft("teams.csv");
    id = fetchesHighestId(ft);
    QFile fp("playerwrite.csv");
    pid = fetchesHighestId(fp);
    tempVar = id;
    tempStr = QString::number(tempVar);
    tempStr.push_back('0');
    textId = tempStr.toInt();
    textId += ADD_TO_TEXT_ID;
    ui -> LblHighestTeamIdInt -> setNum(id);
    ui -> LblHighestPlayerIdInt -> setNum(pid);
    ui -> LblHighestTextIdInt -> setNum(textId);

    ui -> LblFertig -> setStyleSheet("color: chartreuse");
    ui -> LblFertig -> setText("FERTIG!");

    ui -> SpnBoxAnzahl -> setDisabled(false);
    ui -> SldAnzahl -> setDisabled(false);
    ui -> LstCountry -> setDisabled(false);
    ui -> CmdWriteData -> setDisabled(false);
    ui -> CmdBeenden -> setDisabled(false);
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> PgrDataWrite -> setValue(0);

    ui -> SpnBoxAnzahl -> setFocus();
    ui -> SpnBoxAnzahl -> setMinimum(1);
    ui -> SpnBoxAnzahl -> setMaximum(MAX_NUMBER_OF_TEAMS_CAN_BE_ADD);

    ui -> SldAnzahl -> setMinimum(1);
    ui -> SldAnzahl -> setMaximum(MAX_NUMBER_OF_TEAMS_CAN_BE_ADD);

    ui -> LblFertig -> setText("ready?");

    QFile file("nationality_and_country.csv");
    if(!file.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "File not exists";
    }
    else
    {
        QTextStream in(&file);
        while (!in.atEnd() )
        {
            line = in.readLine();

            item = line.split(';');

            natId.append(item.at(0).toInt() );
            teamCntryId.append(item.at(1).toInt() );

            ui -> LstCountry -> addItem(item.at(2) );
        }
        file.close();
    }
    ui -> LstCountry -> setCurrentRow(0);
    ui -> LblNat -> setNum(natId.at(0) );
    ui -> LblCntry -> setNum(teamCntryId.at(0) );

    QFile teamsFileR("teams.csv");
    int id = fetchesHighestId(teamsFileR);
    QFile playerFileR("playerwrite.csv");
    int pid = fetchesHighestId(playerFileR);
    int tempVar = id;
    QString tempStr = QString::number(tempVar);
    tempStr.push_back('0');
    int textId = tempStr.toInt();
    textId += ADD_TO_TEXT_ID;
    ui -> LblHighestTeamIdInt -> setNum(id);
    ui -> LblHighestPlayerIdInt -> setNum(pid);
    ui -> LblHighestTextIdInt -> setNum(textId);


    connect(ui -> SpnBoxAnzahl, SIGNAL(valueChanged(int) ), SLOT(LblNvalueChanged() ) );
    ui -> LblN -> setNum(1);

    connect(ui -> LstCountry, SIGNAL(currentRowChanged(int) ), SLOT(LblNatCntryCurrentRowChanged() ) );
    connect(ui -> CmdWriteData, SIGNAL(clicked() ), SLOT(CmdWriteDataClicked() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}
