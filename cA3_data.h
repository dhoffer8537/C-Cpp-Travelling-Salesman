#pragma once
/*	File		: caA3a_data.h
*	Program		: cA3a
*	Programmer	: Drew Hoffer
*	Date		: November 15 2018
*	Description	: Header file for ca3A
*/


#pragma region
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdbool.h>
#include <iostream>
#include <map>
#include <random>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
#pragma warning(disable:4996)
using namespace std;
#pragma endregion


/*City List*/
#pragma region
#define AMT_CITIES	7
#define TOR			0//Toronto
#define ATL			1//Atlanta
#define AUS			2//Austin
#define SAF			3//Santa fe
#define DEN			4//Denver
#define CHI			5//Chicago
#define BUF			6//buffalo

#pragma endregion


/*All Flight Totals*/
#pragma region
#define TOR_FLIGHTS	23	//Toronto goes to atlanta 5 times
#define ATL_FLIGHTS 26	//Etc. . .
#define AUS_FLIGHTS 6
#define SAF_FLIGHTS 1
#define DEN_FLIGHTS 15
#define BUF_FLIGHTS 4
#define CHI_FLIGHTS 37
#define TOTAL_FLI_AMT 112
#pragma endregion


/*List of Different Airports*/
#pragma region
const int kCityNumList[AMT_CITIES] = { TOR, ATL, AUS, SAF, DEN, CHI, BUF };
const string kCityNameList[AMT_CITIES] = { "Toronto", "Atlanta", "Austin", "SantaFe", "Denver", "Chicago", "Buffalo" };
#pragma endregion


/*All timezones I'm working with*/
#pragma region
#define EST			-5
#define EST_STR		" EST."
#define CST			-6
#define CST_STR		" CST."
#define MST			-7
#define MST_STR		" MST."
#pragma endregion

/*Generic Constants*/
#pragma region
#define DEP 0
#define FLI 1
#define DEP_FLI 2 

#define HOURS_MATH 100
#define MINS_MATH 60
#define HOURS 60
#define MINS 60

#define NONE 0
#define NO_MORE_OPTIONS -1
#define END_OF_LINE		-2

#define ON 1
#define OFF 0
#define NOT_FOUND -1
#define FOUND 0
#define FOUND_EXISTING 1
#define DAY_TO_MINS 1440
#define START_CITY 0
#define DEST_CITY  1
#define MAX_STR_LEN 4096
#define TIME_ZONE 3
#define PM 12


#define EXIT_VAL -400
#define MAX_CITY_NUM 7
#define MIN_CITY_NUM 1
#define ALL_GOOD 0
#define INVALID -1
#define MAX_TIME 2359
#define MIN_TIME 0
#define TIME_INPUT 3
#pragma endregion


//Realistically this info would be read in from a file or db

/*Toronto Flight information*************************************************************************************************************************/
#pragma region
#define TOR_BRANCHES 3
const int kTorBranches[TOR_BRANCHES] = { ATL , DEN, CHI };
#define TOR_STR "Toronto"
#define TOR_ATL		5
#define TOR_DEN		2
#define TOR_CHI		16

#define TOR_DEN_INDX	5 // This is the index when the denver flights start
#define TOR_CHI_INDX	7

const int kTOR_FLIGHTS[DEP_FLI][TOR_FLIGHTS] = { { 385, 550, 750, 970, 1200,//Atlanta
												   450, 900,//Denver
												   400, 460, 520, 580, 640, 700, 760, 820, 880, 930, 990, 1050, 1110, 1170, 1260, 1320,},//Chicago
												 { 140, 290, 255, 370, 135,//Atlanta
												   215, 360,//Denver
												   80 , 95 , 95,  95,  95,  95,  95,  95,  95, 105, 105, 105, 105, 105, 90,75} };//Chicago
#pragma endregion
/****************************************************************************************************************************************************/




/*Atlanta Flight Information*************************************************************************************************************************/
#pragma region
#define ATL_BRANCHES 4
const int kAtlBranches[ATL_BRANCHES] = { TOR , AUS, DEN, CHI };
#define ATL_STR "Atlanta"
#define ATL_TOR 5
#define ATL_AUS	3
#define ATL_DEN 3
#define ATL_CHI 15

#define ATL_AUS_INDX 5
#define ATL_DEN_INDX 8
#define ATL_CHI_INDX 11

const int kATL_FLIGHTS[DEP_FLI][ATL_FLIGHTS] = { {430, 630, 900,  1030, 1260,//Toronto
											540, 930, 1200,//Austin
											360, 800, 1030,//Denver
											410, 470, 530, 590, 650, 710, 770, 830, 890, 950, 1010, 1070, 1130, 1190, 1230 },//Chicago
											{130, 250, 230, 370, 140,//Toronto
											130, 170, 150,//Austin
											180, 300, 170,//Denver
											130, 180, 180, 180, 180, 180, 180, 180, 180, 150, 150, 150, 150, 150, 130} };//Chicago
#pragma endregion
/****************************************************************************************************************************************************/




/*Austin Flight Information**************************************************************************************************************************/
#pragma region
#define AUS_BRANCHES 3
const int kAusBranches[AUS_BRANCHES] = { ATL , DEN, SAF };
#define AUS_STR "Austin"
#define AUS_ATL 3
#define AUS_DEN 2
#define AUS_SAF 1

#define AUS_DEN_INDX 3
#define AUS_SAF_INDX 5


const int kAUS_FLIGHTS[DEP_FLI][AUS_FLIGHTS] = { {550, 900, 1290,//Atlanta
												630, 1100,//Denver
												1020 },//SantaFe
												{140, 140, 150,//Atlanta
												 140, 140,//Denver
												 55} };//SantaFe
#pragma endregion
/****************************************************************************************************************************************************/




/*SantaFe Flight Information*************************************************************************************************************************/
#pragma region
#define SAF_BRANCHES 1
const int kSafBranches[SAF_BRANCHES] = { AUS };
#define SAF_STR "SantaFe"
#define SAF_AUS 1

const int kSAF_FLIGHTS[DEP_FLI][SAF_FLIGHTS] = { {900},{45} };
#pragma endregion
/****************************************************************************************************************************************************/




/*Denver Flight Information**************************************************************************************************************************/
#pragma region
#define DEN_BRANCHES 4
const int kDenBranches[DEN_BRANCHES] = { TOR ,ATL, AUS, CHI };
#define DEN_STR "Denver"
#define DEN_TOR 3
#define DEN_ATL 3
#define DEN_AUS 2
#define DEN_CHI 7

#define DEN_ATL_INDX 3
#define DEN_AUS_INDX 6
#define DEN_CHI_INDX 8

const int kDEN_FLIGHTS[DEP_FLI][DEN_FLIGHTS] = { {390, 630, 840,//Toronto
												360, 780, 900,//Atlanta
												720, 900,//Austin
												420, 480, 600, 720, 840, 960, 1110},//Chicago		
												{250, 320, 300,//Toronto
												190, 200, 230,//Atlanta
												120, 140,//Austin
												140, 170, 170, 170, 170, 170, 160} };//Chicago
#pragma endregion
/****************************************************************************************************************************************************/




/*Chicago Flight Information*************************************************************************************************************************/
#pragma region
#define CHI_BRANCHES 4
const int kChiBranches[CHI_BRANCHES] = { TOR ,ATL, DEN, BUF };
#define CHI_STR "Chicago"
#define CHI_TOR 12
#define CHI_ATL 15
#define CHI_DEN 6
#define CHI_BUF 4

#define CHI_ATL_INDX 12
#define CHI_DEN_INDX 27
#define CHI_BUF_INDX 33

const int kCHI_FLIGHTS[DEP_FLI][CHI_FLIGHTS] = { {460, 550, 610, 670, 730, 790, 850, 910, 970, 1030, 1150, 1270,		//Toronto
										 410, 480, 540, 600, 660, 720, 780, 840, 900, 960, 1020, 1080, 1140, 1200, 1310,//Atlanta
										 540, 690, 810, 930, 1050, 1260,												//Denver
										 660, 790, 900, 1080 },															//Buffalo
										{70, 150, 150, 150, 150, 150, 150, 150, 150, 150, 120, 130,						//Toronto
										 130, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 180,		//Atlanta
										 130, 140, 140, 140, 140, 170,													//Denver
										 120, 110, 150, 130} };															//Buffalo
#pragma endregion
/*****************************************************************************************************************************************************/




/*Buffalo Flight Information*************************************************************************************************************************/
#pragma region
#define BUF_BRANCHES 1
#define BUF_STR "Buffalo"
const int kBufBranches[BUF_BRANCHES] = { CHI };

#define BUF_CHI_LEFT 0
const int kBUF_FLIGHTS[DEP_FLI][BUF_FLIGHTS] = { { 580, 670, 1060, 1210},
												 {100, 110, 160 , 140} };
#pragma endregion
/*****************************************************************************************************************************************************/




/*Class Info******************************************************************************************************************************************/
#pragma region
/*	Class		: Flight
 *	Description	: This is my flight class, the idea is that this class is basically going to be a point A to B thing when instantiated.
 */
class Flight
{
private:
	int startingCity;		// Represents the city that the flight begins at
	int destinationCity;	// Represents the city that the flight ends at
	int flightTime;			// How long the flight will take
	int departure;			// When the flight leaves

	static bool ValidateStartingCity(int currentCity);	// Confirms the string
	static bool ValidateDestinationCity(int nextCity);		// Confirms the string
	static bool ValidateFlightTime(int travelTime, int whichCity);
	static bool ValidateDepartTime(int departureTime, int whichCity);

	//Validators here
public:
	Flight(void);
	Flight(int startCity, int destinationCity, int startTime, int travelTime);

	int GetStartingCity(void);
	bool SetStartingCity(int currentCity);

	int GetDestinationCity(void);
	bool SetDestinationCity(int nextCity);

	int GetDepartTime(void);
	bool SetDepartTime(int departureTime);

	int GetFlightTime(void);
	bool SetFlightTime(int travelTime);


	~Flight(void);
};
#pragma endregion





/*City Branches*/
#pragma region
const int kCityBranches[AMT_CITIES] = { TOR_BRANCHES, ATL_BRANCHES, AUS_BRANCHES, SAF_BRANCHES, DEN_BRANCHES, CHI_BRANCHES, BUF_BRANCHES };
#pragma endregion





/*Prototypes*/
#pragma region
int convertToMins(int startTime);
int getNum(void);
vector<Flight> optimizePath(map<int, vector<int>> travelInfo, map<int, vector<Flight>> airports, int startingTime, int* solutionCounter);
map<int, vector<Flight>> initializeCityInfo(void);
int mainMenu(map<int, vector<Flight>> airports);
int goDeeper(int currentCity, int whichOnesLeft, int* trip);
int recursionTime(int* solutionCounter, int endCity, int currentCity, map<int, vector<int>>* path, vector<int>* tempVect, int* trip);
int howManyBranches(int city);
void displayTrip(vector<Flight> bestRoute, int startingCity, int destinationCity, int startingTime);
void minsToNormalTime(int time, char* timeStr);
string checkStrNums(int whichCity, int whichPart);
void dayHourMin(int time, char* timeStr);
int infoConfirmation(int input, int whichInputType);
int convertTime(int timeOfDay, Flight currentCity);
int sameCity(int startCity, int destinationCity);
#pragma endregion