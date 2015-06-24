

#include "StdAfx.h"
#include <iostream>
#include<conio.h>
#include<string.h>
#include <string>
using namespace std;

struct node {
	char nodename;

};

int v[20][20]; // this is the direct vertex cost 
int h[20][20]; // this is the straigh line heuristic 
int explored[20];
//int current_cost=1000;
int start = -1;
int goal = -1;
string cities[20] = { "Arad", "Bucharest", "Craiova", "Drobeta", "Eforie", "Fagaras",
"Giurgiu", "Hirsova", "Isai", "Lugoj", "Mehadia", "Neamt", "Oradea", "Pitesti",
"Rimnicu Vilcea", "Sibiu", "Timisoara", "Urziceni", "Vaslui", "Zerind" };
int i = 0;
int j = 0;
int k = 0;
int l = 0;

int path(int input);
int main()

{
	char quitprog;
	int s;
	//some important variables

	for (i = 0; i<20; i++)
	{
		explored[i] = -1;
	}




	// initialization
	for (i = 0; i <20; i++)
	{
		for (j = 0; j <20; j++)
		{
			v[i][j] = 0;
		}
	}

	//storing the information for direct edge information = direct distance
	v[0][0] = 0; v[0][19] = 75; v[0][16] = 118;
	v[0][15] = 140; v[1][5] = 211; v[1][6] = 90; v[1][13] = 101;
	v[1][17] = 85; v[2][3] = 120; v[2][13] = 138; v[2][14] = 146;
	v[3][2] = 120; v[3][10] = 75; v[4][7] = 86; v[5][2] = 211; v[5][15] = 99;
	v[6][1] = 90; v[7][4] = 86; v[7][17] = 98; v[8][11] = 87;
	v[8][18] = 92; v[9][10] = 70; v[9][16] = 111; v[10][3] = 75; v[10][9] = 70;
	v[11][8] = 87; v[12][15] = 151; v[12][19] = 71; v[13][1] = 101; v[13][2] = 138;
	v[13][14] = 97; v[14][2] = 146; v[14][13] = 97; v[14][15] = 80; v[15][0] = 140;
	v[15][5] = 99; v[15][12] = 151; v[15][14] = 80; v[16][0] = 118; v[16][9] = 111;
	v[17][1] = 85; v[17][7] = 98; v[17][18] = 142; v[18][8] = 92; v[18][17] = 142; v[19][0] = 75; v[19][12] = 71;
	/*RomaniaMap[Arad][Sibiu] = 140;
	RomaniaMap[Arad][Zerind] = 75;
	RomaniaMap[Arad][Timisoara] = 118;
	RomaniaMap[Bucharest][Giurgiu] = 90;
	RomaniaMap[Bucharest][Urziceni] = 85;
	RomaniaMap[Bucharest][Fagaras] = 211;
	RomaniaMap[Bucharest][Pitesti] = 101;
	RomaniaMap[Craiova][Drobeta] = 120;
	RomaniaMap[Craiova][RimnicuVilcea] = 146;
	RomaniaMap[Craiova][Pitesti] = 138;
	RomaniaMap[Drobeta][Craiova] = 120;
	RomaniaMap[Drobeta][Mehadia] = 75;
	RomaniaMap[Eforie][Hirsova] = 75;
	RomaniaMap[Fagaras][Bucharest] = 211;
	RomaniaMap[Fagaras][Sibiu] = 99;
	RomaniaMap[Giurgiu][Bucharest] = 90;
	RomaniaMap[Hirsova][Eforie] = 86;
	RomaniaMap[Hirsova][Urziceni] = 98;
	RomaniaMap[Iasi][Vaslui] = 92;
	RomaniaMap[Iasi][Neamt] = 87;
	RomaniaMap[Lugoj][Timisoara] = 111;
	RomaniaMap[Lugoj][Mehadia] = 70;
	RomaniaMap[Mehadia][Lugoj] = 70;
	RomaniaMap[Mehadia][Drobeta] = 75;
	RomaniaMap[Neamt][Iasi] = 87;
	RomaniaMap[Oradea][Zerind] = 71;
	RomaniaMap[Oradea][Sibiu] = 151;
	RomaniaMap[Pitesti][Bucharest] = 101;
	RomaniaMap[Pitesti][RimnicuVilcea] = 97;
	RomaniaMap[Pitesti][Craiova] = 138;
	RomaniaMap[RimnicuVilcea][Pitesti] = 97;
	RomaniaMap[RimnicuVilcea][Craiova] = 146;
	RomaniaMap[RimnicuVilcea][Sibiu] = 80;
	RomaniaMap[Sibiu][RimnicuVilcea] = 80;
	RomaniaMap[Sibiu][Fagaras] = 99;
	RomaniaMap[Sibiu][Oradea] = 151;
	RomaniaMap[Sibiu][Arad] = 140;
	RomaniaMap[Timisoara][Arad] = 118;
	RomaniaMap[Timisoara][Lugoj] = 111;
	RomaniaMap[Urziceni][Bucharest] = 85;
	RomaniaMap[Urziceni][Hirsova] = 98;
	RomaniaMap[Urziceni][Vaslui] = 142;
	RomaniaMap[Vaslui][Urziceni] = 142;
	RomaniaMap[Vaslui][Iasi] = 92;
	RomaniaMap[Zerind][Arad] = 75;
	RomaniaMap[Zerind][Oradea] = 71;
*/


	for (k = 0; k <20; k++)
	{
		for (l = 0; l <20; l++)
		{
			h[k][l] = 0;
		}
	}

	/// storing the HSLD  values of the romanian map :
	h[0][1] = 366; h[1][1] = 0; h[2][1] = 160; h[3][1] = 242; h[4][1] = 161; h[5][1] = 176; h[6][1] = 77; h[7][1] = 151; h[8][1] = 226; h[9][1] = 244; h[10][1] = 241; h[11][1] = 234; h[12][1] = 380; h[13][1] = 100; h[14][1] = 193; h[15][1] = 253; h[16][1] = 329; h[17][1] = 80; h[18][1] = 199; h[19][1] = 374;



	int g;
	string start_;
	string goal_;


	cout << "Please enter START city name from the following list of cities in Romanian Map:" << endl;
	for (g = 0; g<20; g++)
	{
		cout << "-" << cities[g] << endl;
	}
again:
	cin >> start_;
	for (int g = 0; g<20; g++)
	{
		if (start_.compare(cities[g]) == 0)
		{
			start = g;
			break;
		}
	}
	if (start == -1)
	{
		cout << "Incorrect city or wrong spellings. Please re-type" << endl;
		goto again;
	}



again_goal:
	cout << "and goal city?" << endl;
	cin >> goal_;
	for (int g = 0; g<20; g++)
	{
		if (goal_.compare(cities[g]) == 0)
		{
			goal = g;
			break;
		}
	}
	if (goal == -1)
	{
		cout << "Incorrect city or wrong spellings. Please re-type" << endl;
		goto again_goal;
	}



	k = 0;
	l = start;
	explored[l] = 1;
	if (l == goal){ cout << "You are already at the destination" << endl; getch(); return 0; }

	cout << "This is the optimal path using A* search" << endl;
	cout << endl << "-" << cities[l];
	do{
		cout << "-";
		l = path(l);
	} while (l != goal);


	//cout<<"This is what you get"<<l<<endl;
	//l=path(l);
	//cout<<"This is what you get"<<l<<endl;
	//l=path(l);
	//cout<<"This is what you get"<<l<<endl;
	//l=path(l);
	//cout<<"This is what you get"<<l<<endl;

	//path (start);
	//if ((s=path(start))==goal)
	//cout<<"Solution found!"<<endl;
	//else (s=path(s));

	getch();

	return 0;
}

int path(int input)
{
	int current_node = -1;
	int current_cost = 1000;
	int i = 0;
	for (i = 0; i <20; i++)
	{
		if ((v[input][i] != 0) && (current_cost>(v[input][i] + h[i][goal])) && (explored[i] != 1))
		{
			current_cost = v[input][i] + h[i][goal];
			current_node = i;
			

		}
	}
	cout << cities[current_node];
	explored[current_node] = 1;
	return current_node;

	//return current_cost;
}
