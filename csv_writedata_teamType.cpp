#include <QTextStream>
#include <QDebug>
#include <QIODevice>
#include <QTextCodec>

#include <csv_writedata_teamType.h>
#include <csv_const.hpp>

teamType::teamType() = default;
teamType::teamType(const int &id, const int &kitT, const int &wk, const int &w, const int &cg,
                const int &npm, const int &nc, const int &kf, const int &jt, const int &jfs, const int &np1,
                const int &jddfs, const int &np2, const int &numc, const int &jc1, const int &jc2,
                const int &jc3, const int &st, const int &scol1, const int &scol2, const int &scol3,
                const int &snp, const int &snfs, const int &snc, const int &snX, const int &snY,
                const int &sot, const int &soc1, const int &soc2, const int &soc3, const int &jnc,
                const int &sncol, const int &snhp, const int &kca_h, const int &kca_s, const int &kca_v)
{
    teamId = id;

    kitType = kitT;
    wetKit = wk;
    wrinkle = w;
    collarGeometry = cg;
    namePlacement = npm;
    nameColor = nc;
    kitFont = kf;
    jerseyType = jt;
    jerseyFontSize = jfs;
    numberPlace1 = np1;
    jerseyDoubleDigitFontSize = jddfs;
    numberPlace2 = np2;
    numberColor = numc;
    jerseyColor1 = jc1;
    jerseyColor2 = jc2;
    jerseyColor3 = jc3;
    shortType = st;
    shortColor1 = scol1;
    shortColor2 = scol2;
    shortColor3 = scol3;
    shortNumberPlacement = snp;
    shortNumberFontSize = snfs;
    shortNumberColor = snc;
    shortNumberX = snX;
    shortNumberY = snY;
    sockType = sot;
    sockColor1 = soc1;
    sockColor2 = soc2;
    sockColor3 = soc3;
    jerseyNumberColorId = jnc;
    shortsNumberColorId = sncol;
    shortsNumberHotSpotId = snhp;
    kitClashAvrhsv_h = kca_h;
    kitClashAvrhsv_s = kca_s;
    kitClashAvrhsv_v = kca_v;
}
teamType::teamType(const int &id, const int &cap, const int &pt, const int &kt,
                    const int &lct, const int &rct, const QString &tn = "FC Lorem Ipsum", const QString &tgn = "", const int &pr = TEAM_PRESTIGE,
                    const int & = 0, const int &bt = BALL_TYPE, const int &ab = 1, const int &sta = STADIUM_ID, const int &gb = 1,
                    const int &tsta = TRAININGS_STADIUM_ID, const int &sc = 1, const int &o = 1, const int & = 0, const int &tc = TEAM_CHEMISTRY,
                    const int &orat = OVERALL_RATING, const int &ot = 0, const int &wb = 0, const int &f = FORMATION_ID_FOR_4_4_2, const int &att = 0,
                    const int &tm = 2, const int &at1 = 1, const int &at2 = 2, const int &dt1 = DEFENSE_TACTIC_FOUR_CHAIN, const int &dt2 = DEFENSE_TACTIC_TWO,
                    const int &nti = 0)
{
    teamId = id;
    teamName = tn;
    teamGenericName = tgn;
    teamPrestige = pr;
    genericKitId = id;
    ballType = bt;
    adboardId = ab;
    stadiumId = sta;
    genericBanner = gb;
    trainingsStadiumId = tsta;
    speechCountry = sc;
    opponent = o;
    assetId = id;
    teamChemistry = tc;
    overallRating = orat;

    offsideTrap = ot;
    withoutBall = wb;
    formationId = f;
    attack = att;
    teamMentality = tm;
    attackTactic1 = at1;
    attackTactic2 = at2;
    defenseTactic1 = dt1;
    defenseTactic2 = dt2;
    captain = cap;
    penaltyTakerId = pt;
    kickTakerId = kt;
    leftCornerkickTakerId = lct;
    rightCornerkickTakerId = rct;
    numTransfersIn = nti;
}
void teamType::writeTeams(QFile &f)
{
    QTextStream out(&f);
    out.setCodec("UTF-16LE");
    out << teamId << "\t" << offsideTrap << "\t" << withoutBall << "\t" << formationId << "\t"
            << attack << "\t" << teamMentality << "\t" << attackTactic1 << "\t"
            << attackTactic2 << "\t" << defenseTactic1 << "\t" << defenseTactic2 << "\t" << captain << "\t"
            << penaltyTakerId << "\t" << kickTakerId << "\t" << leftCornerkickTakerId << "\t" << rightCornerkickTakerId << "\t"
            << numTransfersIn << endl;
}
void teamType::writeTeamData(QFile &f)
{
    QTextStream out(&f);
    out.setCodec("UTF-16LE");
    out << teamId << "\t" << teamName << "\t" << teamGenericName << "\t" << teamPrestige << "\t"
            << genericKitId << "\t" << ballType << "\t" << adboardId << "\t"
            << stadiumId << "\t" << genericBanner << "\t" << trainingsStadiumId << "\t" << speechCountry << "\t"
            << opponent << "\t" << assetId << "\t" << teamChemistry << "\t" << overallRating << endl;
}
void teamType::writeTeamKits(QFile &f)
{
    QTextStream out(&f);
    out.setCodec("UTF-16LE");
    out << teamId << "\t" << kitType << "\t" << wetKit << "\t" << wrinkle << "\t"
            << collarGeometry << "\t" << namePlacement << "\t" << nameColor << "\t" << kitFont << "\t"
            << jerseyType << "\t" << jerseyFontSize << "\t" << numberPlace1 << "\t" << jerseyDoubleDigitFontSize << "\t"
            << numberPlace2 << "\t" << numberColor << "\t" << jerseyColor1 << "\t" << jerseyColor2 << "\t"
            << jerseyColor3 << "\t" << shortType << "\t" << shortColor1 << "\t" << shortColor2 << "\t" << shortColor3 << "\t"
            << shortNumberPlacement << "\t" << shortNumberFontSize << "\t" << shortNumberColor << "\t" << shortNumberX << "\t"
            << shortNumberY << "\t" << sockType << "\t" << sockColor1 << "\t" << sockColor2 << "\t" << sockColor3 << "\t"
            << jerseyNumberColorId << "\t" << shortsNumberColorId << "\t" << shortsNumberHotSpotId << "\t"
            << kitClashAvrhsv_h << "\t" << kitClashAvrhsv_s << "\t" << kitClashAvrhsv_v << endl;
}
