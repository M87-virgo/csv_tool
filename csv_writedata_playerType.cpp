#include <QTextStream>
#include <QDebug>
#include <QIODevice>
#include <QTextCodec>

#include <csv_writedata_playerType.h>
#include <csv_const.hpp>

playerType::playerType() = default;
playerType::playerType(const int &pid, const int &ycv, const int &sCol, const int &cel, const int &lmht, const int &reti, const int &pf, const int &injp, const int &pp, const int &nat,
                    const QString &fn = "Lorem", const QString &sn = "Ipsum", const int &bd = BIRTH_DATE, const int &c = 0, const int &dsh = 0, const int &on = 0, const int &dsc = 2,
                    const int &dtc = 2, const int &r = 0, const int &hsh = 0, const int &hg = HEIGHT, const int &wg = WEIGHT, const int &ft = FACE_TYPE_ID, const int &hc = 2,
                    const int &ht = HAIR_TYPE_ID, const int &fhs = 1, const int &leg = 3, const int &sl = 0, const int &acc1 = 0, const int &aCol1 = ACOL, const int &acc2 = 0,
                    const int &aCol2 = ACOL, const int &acc3 = 0, const int &aCol3 = ACOL, const int &acc4 = 0, const int &aCol4 = ACOL, const int &acc5 = 0, const int &aCol5 = ACOL,
                    const int &a = PLAYER_ATTRIBUTES, const int &agg = PLAYER_ATTRIBUTES, const int &p = PLAYER_ATTRIBUTES, const int &stam = PLAYER_ATTRIBUTES, const int &s = PLAYER_ATTRIBUTES,
                    const int &b = PLAYER_ATTRIBUTES, const int &mar = PLAYER_ATTRIBUTES, const int &t = PLAYER_ATTRIBUTES, const int &bc = PLAYER_ATTRIBUTES, const int &dri = PLAYER_ATTRIBUTES,
                    const int &cr = PLAYER_ATTRIBUTES, const int &h = PLAYER_ATTRIBUTES, const int &pass = PLAYER_ATTRIBUTES, const int &lb = PLAYER_ATTRIBUTES,
                    const int &lsacc = PLAYER_ATTRIBUTES, const int &sacc = PLAYER_ATTRIBUTES, const int &sp = PLAYER_ATTRIBUTES, const int &anti = PLAYER_ATTRIBUTES,
                    const int &refl = PLAYER_ATTRIBUTES, const int &rush = PLAYER_ATTRIBUTES, const int &hand = PLAYER_ATTRIBUTES, const int &gkp = PLAYER_ATTRIBUTES,
                    const int &crea = PLAYER_ATTRIBUTES, const int &pComp = PLAYER_ATTRIBUTES,const int &stpl = 0, const int & = 0, const int &pot = POTENTIAL, const int &bsc = 1,
                    const int &ls = PLAYER_ATTRIBUTES)
{
    playerId = pid;
    firstName = fn;
    surName = sn;
    birthDate = bd;
    current = c;
    disableStarHead = dsh;
    originalName = on;
    yearContractValidtil = ycv;
    developmentStyleCode = dsc;
    developmentTypeCode = dtc;
    reincarnation = r;
    hasStarHead = hsh;

    height = hg;
    weight = wg;
    preferredPosition = pp;
    preferredFoot = pf;
    faceTypeId = ft;
    hairColorId = hc;
    hairTypeId = ht;
    facialHairStyleId = fhs;
    legTypeId = leg;
    sleeveLength = sl;
    accessoryId1 = acc1;
    accessoryColor1 = aCol1;
    accessoryId2 = acc2;
    accessoryColor2 = aCol2;
    accessoryId3 = acc3;
    accessoryColor3 = aCol3;
    accessoryId4 = acc4;
    accessoryColor4 = aCol4;
    accessoryId5 = acc5;
    accessoryColor5 = aCol5;
    shoeColor = sCol;
    injuryProne = injp;
    acceleration = a;
    aggression = agg;
    pace = p;
    stamina = stam;
    strength = s;
    balance = b;
    marking = mar;
    tackling = t;
    ballControl = bc;
    dribbling = dri;
    crossing = cr;
    heading = h;
    passing = pass;
    longBalls = lb;
    longShotAccuracy = lsacc;
    shotAccuracy = sacc;
    shotPower = sp;
    anticipation = anti;
    reflexes = refl;
    rushing = rush;
    handling = hand;
    gkPositioning = gkp;
    creativity = crea;
    playerComposure = pComp;
    starPlayer = stpl;
    assetId = pid;
    potential = pot;
    nationality = nat;
    bodySizeCode = bsc;
    leaderShip = ls;
    lowMedHairTypeId = lmht;
    retirementage = reti;
    celebration = cel;
}
void playerType::writePlayersData(QFile &f)
{
    QTextStream out(&f);
    out.setCodec("UTF-16LE");
    out << playerId << "\t" << firstName << "\t" << surName << "\t" << birthDate << "\t"
            << current << "\t" << disableStarHead << "\t" << originalName << "\t"
            << yearContractValidtil << "\t" << developmentStyleCode << "\t" << developmentTypeCode << "\t" << reincarnation << "\t"
            << hasStarHead << endl;
}
void playerType::writePlayersData2(QFile &f)
{
    QTextStream out(&f);
    out.setCodec("UTF-16LE");
    out << playerId << "\t" << height << "\t" << weight << "\t" << preferredPosition << "\t"
            << preferredFoot << "\t" << faceTypeId << "\t" << hairColorId << "\t" << hairTypeId << "\t"
            << facialHairStyleId << "\t" << legTypeId << "\t" << sleeveLength << "\t" << accessoryId1 << "\t"
            << accessoryColor1 << "\t" << accessoryId2 << "\t" << accessoryColor2 << "\t" << accessoryId3 << "\t"
            << accessoryColor3 << "\t" << accessoryId4 << "\t" << accessoryColor4 << "\t" << accessoryId5 << "\t" << accessoryColor5 << "\t"
            << shoeColor << "\t" << injuryProne << "\t" << acceleration << "\t" << aggression << "\t" << pace << "\t" << stamina << "\t"
            << strength << "\t" << balance << "\t" << marking << "\t" << tackling << "\t" << ballControl << "\t" << dribbling << "\t"
            << crossing << "\t" << heading << "\t" << passing << "\t" << longBalls << "\t" << longShotAccuracy << "\t"
            << shotAccuracy << "\t" << shotPower << "\t" << anticipation << "\t" << reflexes << "\t" << rushing << "\t" << handling << "\t"
            << gkPositioning << "\t" << creativity << "\t" << playerComposure << "\t" << starPlayer << "\t" << assetId << "\t"
            << potential << "\t" << nationality << "\t" << bodySizeCode << "\t" << leaderShip << "\t" << lowMedHairTypeId << "\t" << retirementage << "\t"
            << celebration << endl;
}
