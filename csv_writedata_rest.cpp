#include <QTextStream>
#include <QDebug>
#include <QIODevice>
#include <QTextCodec>

#include <csv_writedata_rest.h>


teamCountryType::teamCountryType() = default;
teamCountryType::teamCountryType(const int &id, const int &cId)
{
    teamId = id;
    countryId = cId;
}
void teamCountryType::writeTeamCountry(QFile &f)
{
    QTextStream out(&f);
    out.setCodec("UTF-16LE");
    out << teamId << "\t" << countryId << endl;
}

playerTeamType::playerTeamType() = default;
playerTeamType::playerTeamType(const int &id, const int &pid, const int &jn, const int &po)
{
    teamId = id;
    playerId = pid;
    jerseyNumber = jn;
    position = po;
}
void playerTeamType::writeTeamPlayerLinks(QFile &f)
{
    QTextStream out(&f);
    out.setCodec("UTF-16LE");
    out << teamId << "\t" << playerId << "\t" << jerseyNumber << "\t" << position << endl;
}

textIdType::textIdType() = default;
textIdType::textIdType(const int &tId, const QString &ln)
{
    textId = tId;
    langName = ln;
}
void textIdType::writeTextId(QFile &f)
{
    QTextStream out(&f);
    out.setCodec("UTF-16LE");
    out << textId << "\t" << langName << endl;
}
