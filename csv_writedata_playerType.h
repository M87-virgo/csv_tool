#ifndef CSV_PLAYERTYPE_H
#define CSV_PLAYERTYPE_H

#include <QFile>

class playerType
{
   private:
      int playerId = 0;
      QString firstName;
      QString surName;
      int birthDate = 0;
      int current = 0;
      int disableStarHead = 0;
      int originalName = 0;
      int yearContractValidtil = 0;
      int developmentStyleCode = 0;
      int developmentTypeCode = 0;
      int reincarnation = 0;
      int hasStarHead = 0;

      int height = 0;
      int weight = 0;
      int preferredPosition = 0;
      int preferredFoot = 0;
      int faceTypeId = 0;
      int hairColorId = 0;
      int hairTypeId = 0;
      int facialHairStyleId = 0;
      int legTypeId = 0;
      int sleeveLength = 0;
      int accessoryId1 = 0;
      int accessoryColor1 = 0;
      int accessoryId2 = 0;
      int accessoryColor2 = 0;
      int accessoryId3 = 0;
      int accessoryColor3 = 0;
      int accessoryId4 = 0;
      int accessoryColor4 = 0;
      int accessoryId5 = 0;
      int accessoryColor5 = 0;
      int shoeColor = 0;
      int injuryProne = 0;
      int acceleration = 0;
      int aggression = 0;
      int pace = 0;
      int stamina = 0;
      int strength = 0;
      int balance = 0;
      int marking = 0;
      int tackling = 0;
      int ballControl = 0;
      int dribbling = 0;
      int crossing = 0;
      int heading = 0;
      int passing = 0;
      int longBalls = 0;
      int longShotAccuracy = 0;
      int shotAccuracy = 0;
      int shotPower = 0;
      int anticipation = 0;
      int reflexes = 0;
      int rushing = 0;
      int handling = 0;
      int gkPositioning = 0;
      int creativity = 0;
      int playerComposure = 0;
      int starPlayer = 0;
      int assetId = 0;
      int potential = 0;
      int nationality = 0;
      int bodySizeCode = 0;
      int leaderShip = 0;
      int lowMedHairTypeId = 0;
      int retirementage = 0;
      int celebration = 0;
   public:
      playerType();
      playerType(const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&,
                    const QString&, const QString&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&,
                    const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&,
                    const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&,
                    const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&,
                    const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&,
                    const int&, const int&, const int&);
      void writePlayersData(QFile&);
      void writePlayersData2(QFile&);
};

#endif
