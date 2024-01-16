#pragma once
#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <random>
#include "Cube.h"
#include "Prism.h"
#include "vector3D.h"
#include <iostream>
#include "Color.h"
#include "Camera.h"
#include "ModelLoader.h"
#include <chrono>
#include <algorithm>
#include "text.h"
#include <thread> 
#include "Score.h"
#include "Player.h"
#include "Obstacle.h"
#include "Scene.h"
#include "Bonus.h"
#include "Enemy.h"
#include "ScoreboardLoader.h"

using namespace std;
using namespace std::chrono;


class Game
{
private:

	const double TIME_INCREMENT = 0.5;
	const long UPDATE_PERIOD = 10;

	milliseconds initialMilliseconds;
	long lastUpdateTime;	

	const float incremento_tiempo = 1;

	float time_passed;

	Scene* activescene;

	//LAS ESCENAS DEL JUEGO
	Scene* startscene = new(nothrow) Scene();
	Scene* gamescene = new(nothrow) Scene();
	Scene* defeatscene = new(nothrow) Scene();
	Scene* scoreboardscene = new(nothrow) Scene();
	
	//PLAYER
	Player* player;

	//Score
	Score* score;
	Text* bonustext;

	//OBSTACULOS
	Enemy* enemy1;
	Enemy* enemy2;
	Enemy* enemy3;
	Bonus* bonus;

	//VARIABLES PARA LA GENERACION DE OBSTACULOS Y LAS COLISIONES
	float random_pos[5];
	vector<Obstacle*> obs_vector;
	vector<Obstacle*> bonus_vector;

		//SCOREBOARD
		ScoreboardLoader* scoreboard;
		vector<Text*> bestscores;

public:

	Game() : random_pos {-1.0, 1.5, 4, 6.5, 9.0}, player(nullptr), activescene(nullptr), lastUpdateTime(0), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())) {}

	void Init();
	void Render();
	void ObsGenerate(const float& time, const float& time_passed);
	void GenerateScoreboard();
	void BonusCollision();
	void EnemyCollision();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

