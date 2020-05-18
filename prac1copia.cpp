#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

map<string,map<string,float>> read_record(){
	fstream fin;
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
					cout<<key[i-1]<<" "<<key2<<"->"<<word<<endl;
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


float manhattanDistance(){
	double distance;

	return distance;
}

float  eclideanDistance(){
	double distance;

	return distance;
}

float minkowskidistance(){
	double distance;

	return distance;
}

int main(){

	read_record();
/*
	map<string, map<string, float>> mymap;

	mymap["Angelica"]["Blues Traveler"] = 3.5;
	mymap["Angelica"]["Broken Bells"] = 2;
	mymap["Angelica"]["Norah Jones"] = 4.5;
	mymap["Angelica"]["Phoenix"] = 5;
	mymap["Angelica"]["Slightly Stoopid"] = 1.5;
	mymap["Angelica"]["The Strokes"] = 2.5;
	mymap["Angelica"]["Vampire Weekend"] = 2;

	mymap["Bill"]["Blues Traveler"] = 2;
	mymap["Bill"]["Broken Bells"] = 3.5;
	mymap["Bill"]["Deadmau5"] = 4;
	mymap["Bill"]["Phoenix"] = 2;
	mymap["Bill"]["Slightly Stoopid"] = 3.5;
	mymap["Bill"]["Vampire Weekend"] = 3;

	mymap["Chan"]["Blues Traveler"] = 5;
	mymap["Chan"]["Broken Bells"] = 1;
	mymap["Chan"]["Deadmau5"] = 1;
	mymap["Chan"]["Norah Jones"] = 3;
	mymap["Chan"]["Phoenix"] = 5;
	mymap["Chan"]["Slightly Stoopid"] = 1;

	mymap["Dan"]["Blues Traveler"] = 3;
	mymap["Dan"]["Broken Bells"] = 4;
	mymap["Dan"]["Deadmau5"] = 4.5;
	mymap["Dan"]["Phoenix"] = 3;
	mymap["Dan"]["Slightly Stoopid"] = 4.5;
	mymap["Dan"]["The Strokes"] = 4;
	mymap["Dan"]["Vampire Weekend"] = 2;

	mymap["Hailey"]["Broken Bells"] = 4;
	mymap["Hailey"]["Deadmau5"] = 1;
	mymap["Hailey"]["Norah Jones"] = 4;
	mymap["Hailey"]["The Strokes"] = 4;
	mymap["Hailey"]["Vampire Weekend"] = 1;

	mymap["Jordyn"]["Broken Bells"] = 4.5;
	mymap["Jordyn"]["Deadmau5"] = 4;
	mymap["Jordyn"]["Norah Jones"] = 5;
	mymap["Jordyn"]["Phoenix"] = 5;
	mymap["Jordyn"]["Slightly Stoopid"] = 4.5;
	mymap["Jordyn"]["The Strokes"] = 4;
	mymap["Jordyn"]["Vampire Weekend"] = 4;

	mymap["Sam"]["Blues Traveler"] = 5;
	mymap["Sam"]["Broken Bells"] = 2;
	mymap["Sam"]["Norah Jones"] = 3;
	mymap["Sam"]["Phoenix"] = 5;
	mymap["Sam"]["Slightly Stoopid"] = 4;
	mymap["Sam"]["The Strokes"] = 5;

	mymap["Veronica"]["Blues Traveler"] = 3;
	mymap["Veronica"]["Norah Jones"] = 5;
	mymap["Veronica"]["Phoenix"] = 4;
	mymap["Veronica"]["Slightly Stoopid"] = 2.5;
	mymap["Veronica"]["The Strokes"] = 3;

	FILE *pFile;
	pFile = fopen("music.csv","r");
	
*/



	return 0;
}
