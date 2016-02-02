#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <memory>
////////////////////////////////////////////////////////////
/// \brief A class that stores gameplay data
/// 
////////////////////////////////////////////////////////////


class GameData {
private:
	//Constructor
	GameData();

	static std::weak_ptr<GameData> m_instance;

	friend std::weak_ptr < GameData >;
	friend std::shared_ptr < GameData >;
public:
	//Get instance of singleton
	static std::shared_ptr<GameData> sharedGameData();

	std::string m_backgroundTextureFile;
	std::string m_textureAtlasImageFile;
	std::string m_textureAtlasPlistFile;
	// Tower base and tower related fields.
	std::string m_towerBaseFile;
	std::string m_towerGunFile;
	int m_towerWidth;
	int m_towerHeight;
	int m_firingDelay;
	int m_towerRotationSpeed;
	float m_towerRotationOriginX;
	float m_towerRotationOriginY;
	int m_numberOfTowerBases;

	float m_towerBaseX[3];
	float m_towerBaseY[3];


};

#endif