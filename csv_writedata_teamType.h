#ifndef CSV_TEAMTYPE_H
#define CSV_TEAMTYPE_H

#include <QFile>

class teamType
{
   private:
      int teamId = 0;
      QString teamName;
      QString teamGenericName;
      int teamPrestige = 0;
      int genericKitId = 0;
      int ballType = 0;
      int adboardId = 0;
      int stadiumId = 0;
      int genericBanner = 0;
      int trainingsStadiumId = 0;
      int speechCountry = 0;
      int opponent = 0;
      int attackTactic2 = 0;
      int assetId = 0;
      int teamChemistry = 0;
      int overallRating = 0;

      int offsideTrap = 0;
      int withoutBall = 0;
      int formationId = 0;
      int attack = 0;
      int teamMentality = 0;
      int attackTactic1 = 0;
      int defenseTactic1 = 0;
      int defenseTactic2 = 0;
      int captain = 0;
      int penaltyTakerId = 0;
      int kickTakerId = 0;
      int leftCornerkickTakerId = 0;
      int rightCornerkickTakerId = 0;
      int numTransfersIn = 0;

      int kitType = 0;
      int wetKit = 0;
      int wrinkle = 0;
      int collarGeometry = 0;
      int namePlacement = 0;
      int nameColor = 0;
      int kitFont = 0;
      int jerseyType = 0;
      int jerseyFontSize = 0;
      int numberPlace1 = 0;
      int jerseyDoubleDigitFontSize = 0;
      int numberPlace2 = 0;
      int numberColor = 0;
      int jerseyColor1 = 0;
      int jerseyColor2 = 0;
      int jerseyColor3 = 0;
      int shortType = 0;
      int shortColor1 = 0;
      int shortColor2 = 0;
      int shortColor3 = 0;
      int shortNumberPlacement = 0;
      int shortNumberFontSize = 0;
      int shortNumberColor = 0;
      int shortNumberX = 0;
      int shortNumberY = 0;
      int sockType = 0;
      int sockColor1 = 0;
      int sockColor2 = 0;
      int sockColor3 = 0;
      int jerseyNumberColorId = 0;
      int shortsNumberColorId = 0;
      int shortsNumberHotSpotId = 0;
      int kitClashAvrhsv_h = 0;
      int kitClashAvrhsv_s = 0;
      int kitClashAvrhsv_v = 0;
   public:
      teamType();
      teamType(const int&, const int&, const int&, const int&, const int&,
                const int&, const QString&, const QString&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&);
      teamType(const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&,
                const int&, const int&, const int&, const int&, const int&, const int&);
      void writeTeamData(QFile&);
      void writeTeamKits(QFile&);
      void writeTeams(QFile&);
};

#endif
