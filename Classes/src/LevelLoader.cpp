#include "LevelLoader.h"

////////////////////////////////////////////////////////////
LevelLoader::LevelLoader(std::string const & filename) 
{
	loadJSONData(filename);
	m_document.Parse<0>(m_JSONData.c_str());	
	loadGameData();
}

////////////////////////////////////////////////////////////
void LevelLoader::loadJSONData(std::string const & filename)
{
	m_JSONData.clear();

	auto fileUtils = cocos2d::FileUtils::getInstance();
	// Loads all the data in the file into a std::string.
	m_JSONData = fileUtils->getStringFromFile(filename);
}

////////////////////////////////////////////////////////////
void LevelLoader::loadGameData()
{
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();

	Value::ConstMemberIterator it1 = m_document["global_settings"].MemberBegin();
	// Get value of "background_texture" 
	ptr->m_backgroundTextureFile = it1->value.GetString();
	// Get value of "texture_atlas_image_file" 
	it1++;
	ptr->m_textureAtlasImageFile = it1->value.GetString();
	// Get value of "texture_atlas_plist_file"
	it1++;
	ptr->m_textureAtlasPlistFile = it1->value.GetString();
	it1++;
	Value const & tower = it1->value; 
	assert(tower.IsObject());
	
}
