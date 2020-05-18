#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

map<string,map<string,float>> readCSV(){
	fstream fin;
//	fin.open("Movie_Ratings.csv", ios::in);
	fin.open("music.csv", ios::in);
	int count = 0;
	vector<string> key;
	map<string, map<string, float>> mymap;
//	vector<string> row;
	string line, word, temp, key2;
	
	while (fin >> temp){
		//row.clear();
		getline(fin,line);
		line = temp+line;
		stringstream s(line);
		int i = 0;
		while (getline(s, word,',')){
			if(count == 0 and !word.empty())
				key.push_back(word);
			else if(!word.empty()){
				if(i == 0)
					key2 = word;
				if(i>0){
					mymap[key[i-1]][key2] = stof(word);
//					cout<<key[i-1]<<" "<<key2<<"->"<<word<<endl;
				}
			}
			i++;
		}
		count++;

	}
//	cout<<mymap.size()<<endl;
//	cout<<mymap["\"Angelica\""]["\"Phoenix\""] + 1<<endl;
	return mymap;
}


float manhattanDistance(map<string,float> usera, map<string,float> userb){
	double distance;
	for(map<string,float>::iterator it = usera.begin(); it!=usera.end();it++){
//		cout<<it->first<<" "<<it->second<<endl;
		if(userb[it->first])
			distance += abs(it->second - userb[it->first]);
	}
	return distance;
}

float euclideanDistance(map<string,float> usera, map<string,float> userb){
	double distance;
	for(map<string,float>::iterator it = usera.begin(); it!=usera.end();it++){
		if(userb[it->first])
			distance += pow((it->second - userb[it->first]),2);
	}

	return sqrt(distance);
}

float minkowskiDistance(map<string,float> usera, map<string,float> userb, int r){
	double distance;
	for(map<string,float>::iterator it = usera.begin(); it!=usera.end();it++){
		if(userb[it->first])
			distance += pow(abs(it->second - userb[it->first]),r);
	}
	if(r == 2){
		return sqrt(distance);
	}else
		return distance; 
}

vector<float,string> compareOneAll(map<string, float> usera, map<string,map<string, float>> group){
	vector<float,string> distancias;
	//completar
	return distancias;
}

vector<string,float> recomend(map<string, float> usera, map<string,map<string, float>> group){
	vector<string, float> recomend;
	//completar
	return recomend;
}


int main(){
	map<string,map<string,float>> mapbd;
	mapbd = readCSV();
	//cout<<mapbd["\"Bill\""]["\"Vampire Weekend\""]<<endl;
	float distancia;

	distancia = manhattanDistance(mapbd["\"Hailey\""], mapbd["\"Veronica\""]);
	cout<<"distancia manhattan "<<distancia<<endl;
	distancia = manhattanDistance(mapbd["\"Angelica\""], mapbd["\"Bill\""]);
	cout<<"distancia manhattan "<<distancia<<endl;

	distancia = euclideanDistance(mapbd["\"Hailey\""], mapbd["\"Jordyn\""]);
	cout<<"distancia euclidean "<<distancia<<endl;
	distancia = euclideanDistance(mapbd["\"Angelica\""], mapbd["\"Bill\""]);
	cout<<"distancia euclidean "<<distancia<<endl;

	distancia = minkowskiDistance(mapbd["\"Angelica\""], mapbd["\"Bill\""],1);
	cout<<"distancia minkowski "<<distancia<<endl;
	distancia = minkowskiDistance(mapbd["\"Angelica\""], mapbd["\"Bill\""],2);
	cout<<"distancia minkowski "<<distancia<<endl;
	return 0;
}
