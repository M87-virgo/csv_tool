#ifndef CSV_WRITEDATA_REST_H
#define CSV_WRITEDATA_REST_H

#include <QFile>

class playerTeamType
{
    private:
        int teamId = 0;
        int playerId = 0;
        int jerseyNumber = 0;
        int position = 0;
    public:
        playerTeamType();
        playerTeamType(const int&, const int&, const int&, const int&);
        void writeTeamPlayerLinks(QFile&);
};


class teamCountryType
{
    private:
        int teamId = 0;
        int countryId = 0;
    public:
        teamCountryType();
        teamCountryType(const int&, const int&);
        void writeTeamCountry(QFile&);
};


class textIdType
{
    private:
        int textId = 0;
        QString langName;
    public:
        textIdType();
        textIdType(const int&, const QString&);
        void writeTextId(QFile&);
};

#endif
