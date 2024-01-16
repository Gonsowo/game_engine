#include "ScoreboardLoader.h"

void ScoreboardLoader::InitScore(string filePath) {
	try {
		ifstream objFile(filePath);
		if (objFile.is_open()) {
			string line;
			while (getline(objFile, line)) {
				this->scores.push_back(stoi(line));
			}
		}
		else {
			cout << "No se ha podido abrir el archivo desde: " << filePath;
		}
		objFile.close();
	}
	catch (exception& ex) {
		cout << "Excepcion al abrir: " << filePath;
		cout << ex.what();
	}
}

int ScoreboardLoader::GetAnScore(const int& index)
{
	try {
		if (this->scores.empty() == false) { return scores[index]; }
		else { return -1; }
	}
	catch (exception& ex) {
		cout << "No se puede acceder a este indice: " << index;
		cout << ex.what();
	}
}


void ScoreboardLoader::OrderScore(string filePath) {
	try {
		this->scores.clear();
		ifstream objFile(filePath);
		if (objFile.is_open()) {
			string line;
			while (getline(objFile, line)) {
				this->scores.push_back(stoi(line));
			}
		}
		else {
			cout << "No se ha podido abrir el archivo desde: " << filePath;
		}
		sort(this->scores.begin(), this->scores.end(), greater<int>());
		objFile.close();
	}
	catch (exception& ex) {
		cout << "Excepcion al abrir: " << filePath;
		cout << ex.what();
	}
}

void ScoreboardLoader::LoadScore(const int& score, string filePath) {
	try {
		ofstream objFile(filePath);
		if (objFile.is_open()) {
			this->scores.push_back(score);
			for (int& var : this->scores) {
				objFile << to_string(var) << "\n";
			}
		}
		else {
			cout << "No se ha podido abrir el archivo desde: " << filePath;
		}
		objFile.close();
	}
	catch (exception& ex) {
		cout << "Excepcion al abrir: " << filePath;
		cout << ex.what();
	}
}