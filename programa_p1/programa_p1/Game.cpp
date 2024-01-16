#include "Game.h"
#include "vector3D.h"
#include "Color.h"

using namespace std;
using namespace std::chrono;

void Game::ProcessKeyPressed(unsigned char key, int px, int py) {
	std::cout << "Tecla pulsada: " << key << endl;

	if (activescene == startscene || activescene == scoreboardscene) {
		activescene = gamescene;
	}

	//Movimiento del 
	if (key == 'a') {
		if (activescene == defeatscene) activescene = gamescene;
		else{
			if (this->player->getcoordinateX() > -0.7) {
				this->player->setSpeedX(-1.0);
				this->player->SetFinalCoord(this->player->getcoordinateX() - 2.5);
			}
			else {
				this->player->setcoordinateX(-1.0);
			}
		}
	}
	else if (key == 'd') {
		if (activescene == defeatscene) activescene = scoreboardscene;
		else {
			if (this->player->getcoordinateX() < 8.7) {
				this->player->setSpeedX(1.0);
				this->player->SetFinalCoord(this->player->getcoordinateX() + 2.5);
			}
			else {
				this->player->setcoordinateX(9.0);
			}
		}
	}
}

void Game::ProcessMouseMovement(int x, int y) {
	std::cout << "Movimiento del raton: " << x << " ," << y << endl;
}

void Game::ProcessMouseClicked(int button, int stage, int x, int y) {
	std::cout << "Clic: " << button << endl;
}

void Game::Init() {

	//CAMERA
	Camera* camera = new Camera();
	camera->setCoordinates(vector3D(4.0, 5.0, 12.0));
	gamescene->AddGameObject(camera);
	startscene->AddGameObject(camera);
	defeatscene->AddGameObject(camera);
	scoreboardscene->AddGameObject(camera);

	////////////////////////////STARTSCENE////////////////////////////////////

	//TEXTO INFORMATIVO
	Text* starttext = new Text();
	starttext->setCoordinates(vector3D(0.0, 5.0, 1.0));
	starttext->setText("PULSA CUALQUIER TECLA PARA COMENZAR");
	startscene->AddGameObject(starttext);


	////////////////////////////GAMESCENE////////////////////////////////////

	//SCORE
	this->score = new Score();
	gamescene->AddGameObject(score);

	//SCOREBOARD
	scoreboard = new ScoreboardLoader();
	scoreboard->InitScore("..\\Scores\\Score.txt");

	//BONUS TEXT
	bonustext = new Text();
	bonustext->setCoordinates(vector3D(4.0, 2.0, 1.0));
	bonustext->setColorComponent(Color(1.0, 1.0, 0.0));
	bonustext->setText("");
	gamescene->AddGameObject(bonustext);

	//PLAYER
	this->player = new Player();
	player->setCoordinates(vector3D(4.0, 0.0, 1.0));
	player->setColorComponent(Color(0.0 ,0.4 ,0.7));
	player->setsize(2.0);
	gamescene->AddGameObject(player);

	//ENEMY1
	this->enemy1 = new Enemy("..\\3dModels\\Mine.obj", 1.5);
	enemy1->GetModel()->setCoordinates(vector3D(4.0, 0.0, 20.0));
	enemy1->GetModel()->PaintColor(Color(1.0, 0.1, 0.0));
	enemy1->GetModel()->setSpeed(vector3D(0.0, 0.0, 1.0));
	gamescene->AddGameObject(enemy1->GetModel());
	obs_vector.push_back(enemy1);
	enemy1->ClearLoader();

	//ENEMY2
	this->enemy2 = new Enemy("..\\3dModels\\Mine.obj", 1.5);
	enemy2->GetModel()->setCoordinates(vector3D(4.0, 0.0, 20.0));
	enemy2->GetModel()->PaintColor(Color(1.0, 0.1, 0.0));
	enemy2->GetModel()->setSpeed(vector3D(0.0, 0.0, 1.0));
	obs_vector.push_back(enemy2);
	gamescene->AddGameObject(enemy2->GetModel());
	enemy2->ClearLoader();

	//ENEMY3
	this->enemy3 = new Enemy("..\\3dModels\\Mine.obj", 1.5);
	enemy3->GetModel()->setCoordinates(vector3D(4.0, 0.0, 20.0));
	enemy3->GetModel()->PaintColor(Color(1.0, 0.1, 0.0));
	enemy3->GetModel()->setSpeed(vector3D(0.0, 0.0, 1.0));
	gamescene->AddGameObject(enemy3->GetModel());
	obs_vector.push_back(enemy3);
	enemy3->ClearLoader();

	//BONUS
	this->bonus = new Bonus("..\\3dModels\\Moneda.obj", 3.5);
	bonus->GetModel()->setCoordinates(vector3D(4.0, 0.0, 20.0));
	bonus->GetModel()->PaintColor(Color(1.0, 1.0, 0.0));
	bonus->GetModel()->setSpeed(vector3D(0.0, 0.0, 1.0));
	bonus->GetModel()->setOrientationSpeedY(3.0);
	gamescene->AddGameObject(bonus->GetModel());
	bonus_vector.push_back(bonus);
	bonus->ClearLoader();

	//ESCENARIO
	Prism* test0 = new Prism();
	test0->setCoordinates(vector3D(-1.0, -1.0, -40.0));
	test0->setColorComponent(Color(0.0, 0.0, 0.0));
	test0->setOrientation(vector3D(0.0, 90.0, 0.0));
	test0->setLength(90.0);
	test0->setHeigth(0.2);
	test0->setWidth(2.2);
	gamescene->AddGameObject(test0);

	Prism* test1 = new Prism();
	test1->setCoordinates(vector3D(1.5, -1.0, -40.0));
	test1->setColorComponent(Color(0.0, 0.0, 0.0));
	test1->setOrientation(vector3D(0.0, 90.0, 0.0));
	test1->setLength(90.0);
	test1->setHeigth(0.2);
	test1->setWidth(2.2);
	gamescene->AddGameObject(test1);

	Prism* test2 = new Prism();
	test2->setCoordinates(vector3D(4.0, -1.0, -40.0));
	test2->setColorComponent(Color(0.0, 0.0, 0.0));
	test2->setOrientation(vector3D(0.0, 90.0, 0.0));
	test2->setLength(90.0);
	test2->setHeigth(0.2);
	test2->setWidth(2.2);
	gamescene->AddGameObject(test2);

	Prism* test3 = new Prism();
	test3->setCoordinates(vector3D(6.5, -1.0, -40.0));
	test3->setColorComponent(Color(0.0, 0.0, 0.0));
	test3->setOrientation(vector3D(0.0, 90.0, 0.0));
	test3->setLength(90.0);
	test3->setHeigth(0.2);
	test3->setWidth(2.2);
	gamescene->AddGameObject(test3);

	Prism* test4 = new Prism();
	test4->setCoordinates(vector3D(9.0, -1.0, -40.0));
	test4->setColorComponent(Color(0.0, 0.0, 0.0));
	test4->setOrientation(vector3D(0.0, 90.0, 0.0));
	test4->setLength(90.0);
	test4->setHeigth(0.2);
	test4->setWidth(2.2);
	gamescene->AddGameObject(test4);

	////////////////////////////DEFEATSCENE////////////////////////////////////

	//TEXTO DE DERROTA
	Text* gameover = new Text();
	gameover->setCoordinates(vector3D(2.5, 6.0, 1.0));
	gameover->setText("GAMEOVER");
	defeatscene->AddGameObject(gameover);

	//TEXTO INFORMATIVO
	Text* wheregoing = new Text();
	wheregoing->setCoordinates(vector3D(-1.5, 3.0, 1.0));
	wheregoing->setText("Pulsa 'A' para jugar de nuevo o pulsa 'D' para acceder a las puntuaciones");
	defeatscene->AddGameObject(wheregoing);

	////////////////////////////SCOREBOARDSCENE////////////////////////////////////
	Text* puntuacion = new Text();
	puntuacion->setCoordinates(vector3D(2.0, 10.0, 1.0));
	puntuacion->setText("LAS 5 MEJORES PUNTUACIONES");
	scoreboardscene->AddGameObject(puntuacion);

	Text* score1 = new Text();
	score1->setCoordinates(vector3D(2.0, 8.0, 1.0));
	this->bestscores.push_back(score1);
	scoreboardscene->AddGameObject(score1);

	Text* score2 = new Text();
	score2->setCoordinates(vector3D(2.0, 6.0, 1.0));
	this->bestscores.push_back(score2);
	scoreboardscene->AddGameObject(score2);

	Text* score3 = new Text();
	score3->setCoordinates(vector3D(2.0, 4.0, 1.0));
	this->bestscores.push_back(score3);
	scoreboardscene->AddGameObject(score3);

	Text* score4 = new Text();
	score4->setCoordinates(vector3D(2.0, 2.0, 1.0));
	this->bestscores.push_back(score4);
	scoreboardscene->AddGameObject(score4);

	Text* score5 = new Text();
	score5->setCoordinates(vector3D(2.0, 0.0, 1.0));
	this->bestscores.push_back(score5);
	scoreboardscene->AddGameObject(score5);

	//Empujar escena
	 
	this->activescene = startscene;

}

void Game::Render() {
	this->activescene->Render();
}

void Game::ObsGenerate(const float& time, const float& time_passed) {
	if (this->enemy1->GetModel()->getcoordinateZ() >= 50) {

		//Aumentar velocidad
		float speed = 1.0 + time_passed / 4000;

		//Indice para ir pasando por los vectores
		int i;

		//ENEMIGO
		random_shuffle(random_pos, random_pos + 5);	//Se desordena el array de posiciones
		i = 0; //Inicializa i
		for (Obstacle* var : obs_vector) {
			if (speed <= 2.2) var->GetModel()->setSpeedZ(speed); //Limitador de velocidad
			var->GetModel()->setcoordinateZ(-70); //Aparecen en la posicion inicial
			var->GetModel()->setcoordinateX(random_pos[i]); //Aparecen en un carril aleatorio
			i++;
		}

		//BONUS
		random_shuffle(random_pos, random_pos + 5);	//Se desordena el array de posiciones
		i = 0;//Resetea i
		for (Obstacle* var : bonus_vector) {
			if (speed <= 2.2) var->GetModel()->setSpeedZ(speed);
			var->GetModel()->setcoordinateZ(-70); 
			var->GetModel()->setcoordinateX(random_pos[i]); 
			bonustext->setText("");
			i++;
		}
	}
}

void Game::GenerateScoreboard(){
	this->scoreboard->LoadScore(score->GetScore(), "..\\Scores\\Score.txt");
	this->scoreboard->OrderScore("..\\Scores\\Score.txt");
	for (int i = 0; i < 5; i++) {
		if (i<scoreboard->GetSize()) this->bestscores[i]->setText(to_string(i + 1) + "- " + to_string(this->scoreboard->GetAnScore(i)));
		else this->bestscores[i]->setText(to_string(i + 1) + "- _________");
	}
}

void Game::BonusCollision(){
	for (Obstacle* var : bonus_vector) {
		if (var->CheckCollision(this->player, var->GetModel()) == true) {
			this->score->ScoreBonus(time_passed);
			this->bonustext->setText("+" + to_string((int)(200 + time_passed / 5)));
			this->bonustext->setcoordinateX(this->player->getcoordinateX());
			this->bonustext->setcoordinateY(2.0);
		}
	}
}

void Game::EnemyCollision(){
	for (Obstacle* var : obs_vector) {
		if (var->CheckCollision(this->player, var->GetModel()) == true) {
			time_passed = 0;
			for (Obstacle* var : obs_vector) { var->GetModel()->setcoordinateZ(20.0); }
			for (Obstacle* var : bonus_vector) { var->GetModel()->setcoordinateZ(20.0); }
			this->player->setcoordinateX(4.0);
			GenerateScoreboard();
			this->score->Reset();
			activescene = defeatscene;
		}
	}
}

void Game::Update() {
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	if((currentTime.count() - this->initialMilliseconds.count() - this->lastUpdateTime > UPDATE_PERIOD))
	{ 
	time_passed = time_passed + TIME_INCREMENT;

	//UPDATES
	activescene->Update(TIME_INCREMENT);

	//COLISIONES
	BonusCollision();
	EnemyCollision();

	//GENERACION DE OBSTACULOS
	ObsGenerate(TIME_INCREMENT, time_passed);

	//PASAR TIEMPO
	this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
	}
}
