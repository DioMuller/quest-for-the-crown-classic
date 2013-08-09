#include "GameManager.h"
#include "Helpers.h"
#include "Maps.hpp"

GameManager* instance;

GameManager::GameManager()
{
	//Initialize the player
	_player = new Player(10,10);

	//Initialize Level Manager
	InitializeMaps();
	_manager->InitializeChildren();

	//Initialize Game State
	_isRunning = true;
	_initialized = true;
	_success = false;

    for( int i = 0; i < DUNGEONS; i++ )
    {
        _dungeonsDone[i] = false;;
    }
}

GameManager::~GameManager()
{
	//Delete all elements from objects?
	delete _player;
}

void GameManager::UpdateGame()
{
	instance->_currentTime = current_time();

	//For each Game Object -> Update
	instance->_player->Update(instance->_currentTime);

	//Updates Level
	instance->_manager->Update(instance->_currentTime);
}

void GameManager::DrawGame()
{
	//For each Game Object -> Draw
	instance->_player->Draw();

	//Draw Level
	instance->_manager->Draw();
	
    mostrar(0,0,FOREGROUND_WHITE, "L");
	//Draw GUI Bar
    if( instance->_player->GetUpdateGui() )
    {
	    mostrar(0,0,FOREGROUND_WHITE, "Life                                                                            ");
	    mostrar(0,1,FOREGROUND_WHITE, "                                                                                ");
		
	    for( int i = 0; i < instance->_player->GetTotalHealth(); i++ )
	    {
		    WORD color = instance->_player->GetCurrentHealth() > i  ? FOREGROUND_RED | FOREGROUND_INTENSITY : FOREGROUND_WHITE;
		    mostrar( 6 + i, 0, color, "@");
	    }

	    WORD active = FOREGROUND_BLUE | BACKGROUND_WHITE;
	    WORD inactive = FOREGROUND_WHITE;

	    if( instance->_player->HasWeapon(BOW) ) mostrar(20, 0, FOREGROUND_WHITE, "Weapon: ");
	    if( instance->_player->HasWeapon(BOW) ) mostrar(31, 0, instance->_player->GetCurrentWeapon() == SWORD ? active : inactive, "SWORD");
	    if( instance->_player->HasWeapon(BOW) ) mostrar(38, 0, instance->_player->GetCurrentWeapon() == BOW ? active : inactive, "BOW");
        if( instance->_player->HasWeapon(BOW) ) mostrar(31, 1, FOREGROUND_WHITE, "Arrows: ");
        if( instance->_player->HasWeapon(BOW) ) mostrar(38, 1, FOREGROUND_WHITE, GetAmmo(BOW));

        instance->_player->SetUpdateGui(false);
    }
}

void GameManager::CleanGame()
{
	instance->_player->Clean();
	instance->_manager->Clean();
}

bool GameManager::HitPlayer(int x, int y)
{
	if( instance->_player->CollidesWith(x,y) )
	{
		instance->_player->Hit();
        return true;
	}

    return false;
}

bool GameManager::IsRunning()
{
	return instance->_initialized && instance->_isRunning;
}

void GameManager::TryHit(int x, int y)
{
	instance->_manager->TryHit(x,y);
}

WORD GameManager::GetBackground()
{
	return instance->_manager->GetLevelBackground();
}

void GameManager::EndGame(bool success)
{
	instance->_success = success;
	instance->_isRunning = false;
}

bool GameManager::CanMoveTo(int x, int y, bool isProjectile)
{
	if( x < 0 || x > 79 || y < 2 || y > 24 ) return false;

	return instance->_manager->CheckXY(x, y, isProjectile);
}


void GameManager::ChangeLevel(Direction direction)
{
	instance->_manager->ChangeLevel(instance->_player, direction);
}

bool GameManager::WasSuccessful()
{
	return instance->_success;
}

Position GameManager::GetPlayerPosition()
{
	return instance->_player->GetPosition();
}

void GameManager::SetPlayerPosition(Position position)
{
	instance->_player->SetX(position.X);
	instance->_player->SetY(position.Y);
}

void GameManager::GoToDungeon(int dungeon)
{
	instance->_manager->GoToDungeon(dungeon);
}

void GameManager::AddObject(GameObject* object)
{
	instance->_manager->AddObject(object);
}

void GameManager::RemoveObject(GameObject* object)
{
	instance->_manager->RemoveObject(object);
}

char GameManager::GetChar(Position position)
{
	return instance->_manager->GetChar(position);
}

void GameManager::ResetGame()
{
	instance = new GameManager();
}

void GameManager::InitializeMaps()
{
	/************************************************************
	* Maps                                                *
	************************************************************/
	Level* map01 = new Level(worldmap_01, map1neighbours, BACKGROUND_GREEN);
	Level* map02 = new Level(worldmap_02, map2neighbours, BACKGROUND_GREEN);
	Level* map03 = new Level(worldmap_03, map3neighbours, BACKGROUND_RED);
	Level* map04 = new Level(worldmap_04, map4neighbours, BACKGROUND_GREEN);
	Level* map05 = new Level(worldmap_05, map5neighbours, BACKGROUND_BLUE);
	Level* map06 = new Level(worldmap_06, map6neighbours, BACKGROUND_RED);
	Level* map07 = new Level(worldmap_07, map7neighbours, BACKGROUND_RED | BACKGROUND_GREEN);
	Level* map08 = new Level(worldmap_08, map8neighbours, BACKGROUND_BLUE);
	Level* map09 = new Level(worldmap_09, map9neighbours, 0);

	Level* dungeon1map1 = new Level(dungeon1_map01, dungeon1map1neighbours, 0);
	Level* dungeon1map2 = new Level(dungeon1_map02, dungeon1map2neighbours, 0);
	Level* dungeon1map3 = new Level(dungeon1_map03, dungeon1map3neighbours, 0);
	Level* dungeon1map4 = new Level(dungeon1_map04, dungeon1map4neighbours, 0);
	Level* dungeon1map5 = new Level(dungeon1_map05, dungeon1map5neighbours, 0);

	/************************************************************
	* Map Arrays                                                *
	************************************************************/
	//Overworld map array.
	Level* overworldLevels[OVERWORLD_LEVELS] = { map01, map02, map03, map04, map05, map06, map07, map08, map09 };

	//Dungeon1 map array.
	Level* dungeon1Levels[DUNGEON1_LEVELS] = { dungeon1map1, dungeon1map2, dungeon1map3, dungeon1map4, dungeon1map5 };

	/************************************************************
	* Dungeon Definitions                                       *
	************************************************************/
	LevelManager* dungeon1 = new LevelManager(dungeon1Levels, DUNGEON1_LEVELS, NULL, 0, Position(39, 22));

    //Dungeons array
	LevelManager* dungeons[DUNGEONS] = { dungeon1 };

	//And finally, the overworld.
	LevelManager* overworldMap = new LevelManager(overworldLevels, OVERWORLD_LEVELS, dungeons, DUNGEONS, Position(0,0));

	_manager = overworldMap;
}

void GameManager::AddPlayerWeapon()
{
    instance->_player->AddWeapon();
}

void GameManager::HealPlayer()
{
    instance->_player->RestoreHealth();
}

void GameManager::FinishDungeon(int x)
{
    if( x >= 0 && x < DUNGEONS ) instance->_dungeonsDone[x] = true;
}
        
bool GameManager::GetDungeonFinished(int x)
{
    if( x >= 0 && x < DUNGEONS ) return instance->_dungeonsDone[x];

    return false;
}

void GameManager::AddPlayerHealth()
{
    instance->_player->UpgradeHealth();
}

void GameManager::ReturnToEntrance()
{
    instance->_manager->BackToMap();
}

int GameManager::GetAmmo(WeaponType weapon)
{
    return instance->_player->GetAmmo(weapon);
}

void GameManager::AddAmmo(WeaponType weapon, int toAdd)
{
    instance->_player->AddAmmo(weapon, toAdd);
}

bool GameManager::HasWeapon(WeaponType weapon)
{
    return instance->_player->HasWeapon(weapon);
}