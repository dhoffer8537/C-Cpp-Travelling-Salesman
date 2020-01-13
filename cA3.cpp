/*	File		: cA3a.cpp
*	Program		: cA3a
*	Programmer	: Drew Hoffer
*	Date		: November 15 2018
*	Description	: This program is intended to take a list of input as given on econestoga and traverse through it in order to create an optimal path.
*/

#include "cA3_data.h"


/*Main / Functions*/

int main(void)
{
	/*Data initialization*/
	/* This is the array of airports , This variable will be a list of airports (Identified by the first int) followed by a pair
	This pair will have an array determined by the first int, IE. Toronto has 3 places so it will be an array 3 long, followed by all the flights
	That will be associated with those places.*/
	map<int, vector<Flight>> airports;
	airports = initializeCityInfo();
	/*Input and looping  */
	mainMenu(airports);
	return 0;
}




/*
* Name		  : goDeeper
* Description : This function's purpose is to take the index passed to it and determine which flight corresponds with that index. In the event
*	   		  : that the city is already taken it will then add one to see if it can fly to the next etc. If all are taken the function returns none found.
* Parameters  : int currentCity
*			  : int whichOnesLeft
*			  : int* trip				:Determines if the city is capable of flying to the destination based on if it is already on our flight or not
* Return	  : int currentCity			: An updated city that we are now flying to
*/
int goDeeper(int currentCity, int whichOnesLeft, int* trip)
{
	switch (currentCity)
	{

		/*Toronto Branches*/
	case TOR:
	{
		// SO long as the city hasnt been flown to then go there
		if (whichOnesLeft == 0)
		{
			if (trip[ATL] != 1)// If we have flown to atlanta then dont go to this one instead check the next
			{
				currentCity = ATL;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 1)
		{
			if (trip[DEN] != 1)
			{
				currentCity = DEN;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 2)
		{
			if (trip[CHI] != 1)
			{
				currentCity = CHI;
				break;
			}

		}
		// If we have all of them in our flight path then we want to say hey theres no more options
		// If that is the case we also need to somehow say that the last city in our array of where we hav travelled needs to be taken out
		currentCity = NO_MORE_OPTIONS;
	}
	break;


	/*Atlanta Branches*/
	case ATL:
	{
		if (whichOnesLeft == 0)
		{
			if (trip[TOR] != 1)
			{
				currentCity = TOR;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 1)
		{
			if (trip[AUS] != 1)
			{
				currentCity = AUS;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 2)
		{
			if (trip[DEN] != 1)
			{
				currentCity = DEN;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 2)
		{
			if (trip[CHI] != 1)
			{
				currentCity = CHI;
				break;
			}
		}
		currentCity = NO_MORE_OPTIONS;

		break;
	}
	/*Austin Branches*/
	case AUS:
	{
		if (whichOnesLeft == 0)
		{
			if (trip[ATL] != 1)
			{
				currentCity = ATL;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 1)
		{
			if (trip[DEN] != 1)
			{
				currentCity = DEN;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 2)
		{
			if (trip[SAF] != 1)
			{
				currentCity = SAF;
				break;
			}
		}
		currentCity = NO_MORE_OPTIONS;

		break;
	}
	/*Denver Branches*/
	case DEN:
	{
		if (whichOnesLeft == 0)
		{
			if (trip[TOR] != 1)
			{
				currentCity = TOR;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 1)
		{
			if (trip[ATL] != 1)
			{
				currentCity = ATL;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 2)
		{
			if (trip[AUS] != 1)
			{
				currentCity = AUS;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 3)
		{
			if (trip[CHI] != 1)
			{
				currentCity = CHI;
				break;
			}

		}
		currentCity = NO_MORE_OPTIONS;
		break;
	}
	/*SantaFe Branches*/
	case SAF:
	{
		if (whichOnesLeft == 0)
		{
			if (trip[AUS] != 1)
			{
				currentCity = AUS;
				break;
			}
		}
		currentCity = NO_MORE_OPTIONS;
		break;
	}
	/*Chicago Branches*/

	case CHI:
	{
		if (whichOnesLeft == 0)
		{
			if (trip[TOR] != 1)
			{
				currentCity = TOR;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 1)
		{
			if (trip[ATL] != 1)
			{
				currentCity = ATL;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 2)
		{
			if (trip[DEN] != 1)
			{
				currentCity = DEN;
				break;
			}
			else
			{
				whichOnesLeft++;
			}
		}
		if (whichOnesLeft == 3)
		{
			if (trip[BUF] != 1)
			{
				currentCity = BUF;
				break;
			}
		}
		currentCity = NO_MORE_OPTIONS;
		break;
	}
	/*Buffalo Branches*/
	case BUF:
	{
		if (whichOnesLeft == 0)
		{
			if (trip[CHI] != 1)
			{
				currentCity = CHI;
				break;
			}
		}

		currentCity = NO_MORE_OPTIONS;
	}
	}
	return currentCity;
}




/*
* Name		  : recursionTime
* Description : This function is where all the magic happens. This function will take a few parameters and with them determine the flight.
*	   		  : This function will then take the flight and add to the map holding all the flights it found that reached the destination
* Parameters  : int* solutionCounter	:This is our total solutions, we use this for our looping later to find the best route
*			  : int endcity, int currentCity
*			  : map<int, vector<int>>* path :All our paths that reached the destination
*			  : vector<int>* tempVect		: The temporary path that we are adding to the map
*			  : int* trip					: The invalid cities that are already on the flight path
* Return	  : endCityFound				:The outcome of what searching for the next city has found.
*/
int recursionTime(int* solutionCounter, int endCity, int currentCity, map<int, vector<int>>* path, vector<int>* tempVect, int* trip)
{
	int inserterfier = currentCity + 1;	//This preserves city while adding the correct city name to vecotr
	tempVect->push_back(inserterfier);	// Add the new city to our vector

	trip[currentCity] = ON;	// I am setting my trip to include the current city

	int cityLoop = 0;
	int nextCityLoop = 0;
	int nextCity = 0;
	int endCityFound = 0;
	bool loopVar = true;


	cityLoop = howManyBranches(currentCity);// Get how many places the current city can go to cause we will loop that many times

	for (int i = 0; i <= cityLoop; i++)		//Loop as many times as the city can branch to
	{
		// Figure out where the place is we need to go to based on the loop ie. 0 will be first branch etc.
		nextCity = goDeeper(currentCity, i, trip);

		if (nextCity == NO_MORE_OPTIONS)// This returns where we are headed to next
		{
			break;
		}
		else if (nextCity != NO_MORE_OPTIONS)
		{

			trip[nextCity] = 1;			//add next city to array
		}

		if (nextCity == endCity)// If its the end then it is safe to assume that this will be the fastest and not needc to check the next 6 around it
		{
			/*This chunk of code below will basically take the map and compare it to the tempvect
			If the two are the same anywhere then it wont bother adding the tempVect ot the map*/
			if (*solutionCounter > 0)//Checks if this is the first one in the whole enchalata
			{
				for (map<int, vector<int>>::iterator mapIter = path->begin(); mapIter != path->end(); ++mapIter)
				{
					int attempt = *solutionCounter;			//Similar to city name i want to preserve the amount of solutions i have
					inserterfier = nextCity + 1;
					tempVect->push_back(inserterfier);		//Add ending city to list to check
					vector<int>::iterator tempVectIter = tempVect->begin();
					if (*tempVect != path->at(--attempt))
					{

						path->insert(make_pair(*solutionCounter, *tempVect));///This is the line that has an issue, for some reason i am not inserting it correctly
						tempVect->pop_back();
						(*solutionCounter)++;
						break;
					}
					else
					{
						tempVect->pop_back();//If the vector already has the option then we want to clear the end anyway
					}

				}
			}
			else if (*solutionCounter == 0)			//If this is our first solution we save it regardless
			{
				inserterfier = nextCity + 1;
				tempVect->push_back(inserterfier);
				path->insert(make_pair(*solutionCounter, *tempVect));///This is the line that has an issue, for some reason i am not inserting it correctly
				tempVect->pop_back();
				(*solutionCounter)++;
			}
			trip[nextCity] = OFF;

			///Need something in here to  reset the end city from the array, currently after finding one it will never come back in here
		}
		else//If we didnt find the endcity yet then we want to go to another location
		{

			if (recursionTime(solutionCounter, endCity, nextCity, path, tempVect, trip) == NO_MORE_OPTIONS)// Go into the next city and pass how
			{
			}
		}

	}
	tempVect->pop_back();
	trip[currentCity] = OFF;		//Clean array


	return endCityFound;
}




/*
* Name		  : convertToMins
* Description : Takes the time in 24 hour time then converts it to just minutes.
*	   		  :
* Parameters  : int startTime
*			  :
*			  :
* Return	  : The final time in minutes
*/
int convertToMins(int startTime)
{
	int hours = HOURS_MATH;
	int mins = MINS_MATH;
	int finalTime = 0;
	if (startTime < 0)
	{
		finalTime = INVALID;
	}
	else
	{
		if (startTime % HOURS_MATH > 59)
		{
			finalTime = INVALID;
		}
		if (startTime >= hours)
		{
			hours = startTime / hours;// Divide by 100 to convert military time hours to get the total hours
			finalTime = hours * HOURS;	// Multiply that by 60 for converting hours to mins
			mins = startTime % HOURS_MATH;
			if (mins > 59)
			{
				finalTime = INVALID;
			}
			else
			{
				finalTime += mins;
			}
		}
		else
		{
			mins = startTime % HOURS_MATH;
			if (mins > 59)
			{
				finalTime = INVALID;
			}
			else
			{
				finalTime = mins;
			}
		}
	}
	return finalTime;

}




/*
* Name		  : getNum
* Description : This is Carlo's function and will be used to get a number from the user.
*	   		  :
* Parameters  : void
*			  :
*			  :
* Return	  : The number the user entered or a -1 if they entered a non digit.
*/
int getNum(void)
{

	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	fgets(record, 121, stdin);
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		 * the system, set number to -1 */
		number = -1;
	}
	return number;
}




/*
* Name		  : howManyBranches
* Description : This function returns the branches that a given city will be able to fly to
*	   		  :
* Parameters  : int city
*			  :
*			  :
* Return	  : howMany		:The number of potential destinations the city can fly to.
*/
int howManyBranches(int city)
{
	int howMany = 0;

	switch (city)
	{
	case(TOR):
	{
		howMany = TOR_BRANCHES;
		break;
	}
	case(ATL):
	{
		howMany = ATL_BRANCHES;
		break;
	}
	case(AUS):
	{
		howMany = AUS_BRANCHES;
		break;
	}
	case(SAF):
	{
		howMany = SAF_BRANCHES;
		break;
	}
	case(DEN):
	{
		howMany = DEN_BRANCHES;
		break;
	}
	case(CHI):
	{
		howMany = CHI_BRANCHES;
		break;
	}
	case(BUF):
	{
		howMany = BUF_BRANCHES;
	}

	}
	return howMany;
}




/*
* Name		  : mainMenu
* Description : This function's job is to loop constantly and perform all of the logic behind recursion and deter
*	   		  :
* Parameters  : map<int, pair<vector<int>, vector<Flight>>> airports
*			  :
*			  :
* Return	  : The startingCity, this will tell us if we have exited due to the user entering 0 as their starting city.
*/
int mainMenu(map<int, vector<Flight>> airports)
{
	int startCity = -1; // -1 for a start value until the user enters a value, then if the user enters 0 it will exit the function




	while (startCity != EXIT_VAL)
	{
		int destinationCity = 0;
		int startTime = 0;

		/*Start of Input Gathering*********************************************************************/
		do
		{
			printf("Enter 0 as a starting City to quit.\n");
			printf("Please enter a starting City\n1.Toronto - 2.Atlanta - 3.Austin - 4.SantaFe - 5.Denver - 6.Chicago - 7.Buffalo\n>>");
			startCity = getNum();
			if (startCity == 0)			//If the user enters 0 as a starting city this will force us out of gathering a name
			{
				startCity = EXIT_VAL;
				break;
			}
		} while (infoConfirmation(startCity, START_CITY) != ALL_GOOD);
		if (startCity == EXIT_VAL)//Exit the program here
		{
			break;
		}
		startCity--; // This is done so that we can start at the first index(Toronto in this case)


		do
		{
			printf("\n");
			printf("Please enter a destination City\n1.Toronto - 2.Atlanta - 3.Austin - 4.SantaFe - 5.Denver - 6.Chicago - 7.Buffalo\n>>");
			destinationCity = getNum();

		} while (infoConfirmation(destinationCity, DEST_CITY) != ALL_GOOD || sameCity(startCity, destinationCity) != ALL_GOOD);
		destinationCity--; // Same as with the start city we need to account for the 0 index


		do
		{
			printf("\n");
			printf("Please enter your trip starting time in 24hr time (e.g. 1300 = 1pm)\n\t>>");
			startTime = getNum();
			printf("\n");
			startTime = convertToMins(startTime);
		} while (infoConfirmation(startTime, TIME_INPUT) != ALL_GOOD);
		/*End of input gathering***********************************************************************/



		/*Recursion Time section************************************************************************/
		int solutions = 0;												//This will be our value for holding the amount of solutions we find
		map<int, vector<int>> travelList;								//This is our list that holds all of our potential best flights
		vector<int> tempList;											//This is just our holder for each flight we are adding to travelList

		int trip[AMT_CITIES] = { OFF, OFF, OFF, OFF, OFF, OFF, OFF };	//Setting the flight to all off so that we can fly anywhere we want to start

		trip[startCity] = ON;											//Set our city to on as it will always need to be in the flight path


		recursionTime(&solutions, destinationCity, startCity, &travelList, &tempList, trip);	//Now we do some crazy looping to find all the paths possible.


		vector<Flight> bestRoute;												//This will hold our best route and store it with all the info we need.
		bestRoute = optimizePath(travelList, airports, startTime, &solutions);	//This function call will return the fastest route for us
		displayTrip(bestRoute, startCity, destinationCity, startTime);			//Print out that trip and start over!
	}
	return startCity;
}



/*
* Name		  : sameCity
* Description : This function confirms the multiverse theory.
*	   		  :
* Parameters  : int startCity
*			  : int destinationCity
*			  :
Return		  : status of interdimensional travel
*/
int sameCity(int startCity, int destinationCity)
{
	destinationCity--;
	int outcome = ALL_GOOD;
	if (destinationCity == startCity)
	{
		printf("Through the magic of Drew's code and Drew's code only.\nYou open the door to the stalland fall into an alternate dimension moments before boarding the plane to your own city....\n");
		printf("Next thing you know.... BOOM! You are now in your own city in another dimension.\n");
		printf("\nCongratulation's on such an impressive feat.\n\n\nNow that you are here you have an overwhelming urge to give Drew Hoffer 100%% on this assignment.\n");
		printf("The question is... is this Drew Hoffer deserving or is this dimensions Drew Hoffer a slacker. \n");
		printf("Hell bent on persuading you through the power of a simple console window to give him free marks in a cheap attempt to make you laugh... \n\n\nWe may never know...\n\n");
		outcome = INVALID;
	}
	return outcome;
}

/*
* Name		  : optimizePath
* Description : This function will take all of the flights that found their destination and check
*	   		  : if the travel that we are looking at is the quickest, otherwise we wont save it
* Parameters  : map<int, vector<int>> travelInfo - The map that will hold all of our paths we find
*			  : map<int, vector<Flight>> airports- This map will hold all of our flight info given for this assignment.
*			  : int startingTime, int* solutionCounter - solutionCounter will be modified if we find a new route
Return		  : bestVect										- The optimal path converted from ints to Flights
*/
vector<Flight> optimizePath(map<int, vector<int>> travelInfo, map<int, vector<Flight>> airports, int startingTime, int* solutionCounter)
{
	vector<Flight> bestVect;				//This will be our winner
	vector<Flight> tempVect;				//This is our competitor

	Flight tempFlightInfo;
	int timeOfDay = 0;						// current time we are departing from
	int entireTripTime = 0;					// holds total travel time
	int bestTripTime = 100000;				//Magic number that is going to always be reset based on the first flight found
	int nextDayTimeHolder = 0;

	for (map<int, vector<int>>::iterator amtOfSolsIter = travelInfo.begin(); amtOfSolsIter != travelInfo.end(); ++amtOfSolsIter)	//How many trips we have in the loop
	{
		timeOfDay = startingTime;	//We need to reset our time for each vector element
		entireTripTime = 0;			//We need to reset for next vector

		/*This portion is for getting start and destination cities and placing them in our object to be added to our vector*/
		for (vector<int>::iterator tripInfoIter = amtOfSolsIter->second.begin(); tripInfoIter != amtOfSolsIter->second.end(); ++tripInfoIter)	//This will loop through our vectors inside of our total trips map
		{
			//This section will correctly add cities to our object and break if we are at the end not adding anything in that instance
			tempFlightInfo.SetStartingCity(0);
			tempFlightInfo.SetDestinationCity(0);
			bool foundCity = false;

			int realCityNum = *tripInfoIter;
			realCityNum--;
			tempFlightInfo.SetStartingCity(realCityNum);	//Gets the number that trips info is looking at right now
			vector<int>::iterator tempIter = tripInfoIter;


			if (++tempIter != amtOfSolsIter->second.end())//Checks to see if the next value in the vector is a value we can set
			{
				realCityNum = *tempIter;
				realCityNum--;
				tempFlightInfo.SetDestinationCity(realCityNum);	//Sets the destination city here
			}
			else
			{
				break;
			}

			/*This portion is for checking based on our airport start and destination which time slot we will need to use */
			for (int i = 0; i < AMT_CITIES; i++)
			{
				if (foundCity == true)
				{
					break;
				}

				vector<Flight>::iterator FlightIter = airports.at(i).begin();
				while (FlightIter != airports.at(i).end())
				{
					if (tempFlightInfo.GetStartingCity() == FlightIter->GetStartingCity())//If our start cities match then...
					{
						///The current problem i am working with is that if our current time is over the last element then we need to make it roll over to the next day
						if (tempFlightInfo.GetDestinationCity() == FlightIter->GetDestinationCity())//If our destination cities match then...
						{
							//Now we need to add the times here till we equal the closest one then we copy that entire flight obj to our temp one 

							if (timeOfDay <= FlightIter->GetDepartTime())
							{
								tempFlightInfo.SetDepartTime(FlightIter->GetDepartTime());
								tempFlightInfo.SetFlightTime(FlightIter->GetFlightTime());

								entireTripTime += FlightIter->GetDepartTime() - timeOfDay;	//Adds the time we are waiting for a flight to the overall time
								entireTripTime += FlightIter->GetFlightTime();

								// time before this
								timeOfDay += FlightIter->GetDepartTime() - timeOfDay;
								timeOfDay += FlightIter->GetFlightTime();

								timeOfDay = convertTime(timeOfDay, tempFlightInfo);

								if (timeOfDay > DAY_TO_MINS)
								{
									timeOfDay = (DAY_TO_MINS - timeOfDay);
								}

								foundCity = true;
								tempVect.emplace_back(tempFlightInfo);//add our new flight to our trip with filled in time information
								break;
								// time fixed after this
							}
						}
					}
					FlightIter++;

					if (foundCity != true && FlightIter == airports.at(i).end())
					{
						if (i == 6)
						{
							timeOfDay = (DAY_TO_MINS - timeOfDay);
							nextDayTimeHolder = true;				//Add the time wrapped around for starters
							i = 0;										//Reset our loop so we can start from 0
							FlightIter = airports.at(i).begin();		//Okay so we couldn't find a time on this run through. This means that we need to wrap around by a day.

						}
					}
				}

			}


		}
		if (entireTripTime < bestTripTime)//Check if our best tripTime is greater than what that last trip was
		{
			bestTripTime = entireTripTime;		//Make our new best
			bestVect.clear();
			bestVect = tempVect;			//Great we have a new best trip
			tempVect.clear();		//Forget this one we are checking the next now
		}
		else
		{
			entireTripTime = 0;		//We need to reset for our next vector
			tempVect.clear();		//Forget this one we are checking the next now
		}
	}

	return bestVect;
}




/*
* Name		  : convertTime
* Description : This function will take the time of day and figure out what time should be returned for the purpose of timezones.
*	   		  :
* Parameters  : int timeOfDay
*			  : Flight currentCity - The flight that we are taking
*			  :
Return		  : A newly calculated time with timezone taken into account.
*/
int convertTime(int timeOfDay, Flight currentCity)
{
	const int torontoOffset = 2;
	const int atlantaOffset = 2;
	const int austinOffset = 1;
	const int santaFeOffset = 0;
	const int denverOffset = 0;
	const int chicagoOffset = 1;
	const int buffaloOffset = 2;
	int startingOffset = 0;
	int destinationOffset = 0;

	switch (currentCity.GetStartingCity())
	{
	case(TOR):
	{
		startingOffset = torontoOffset;
		break;
	}
	case(ATL):
	{
		startingOffset = atlantaOffset;

		break;
	}
	case(AUS):
	{
		startingOffset = austinOffset;

		break;
	}
	case(SAF):
	{
		startingOffset = santaFeOffset;

		break;
	}
	case(DEN):
	{
		startingOffset = denverOffset;

		break;
	}
	case(CHI):
	{
		startingOffset = chicagoOffset;

		break;
	}
	case(BUF):
	{
		startingOffset = buffaloOffset;

		break;
	}
	}

	switch (currentCity.GetDestinationCity())
	{
	case(TOR):
	{
		destinationOffset = torontoOffset;
		break;
	}
	case(ATL):
	{
		destinationOffset = atlantaOffset;

		break;
	}
	case(AUS):
	{
		destinationOffset = austinOffset;

		break;
	}
	case(SAF):
	{
		destinationOffset = santaFeOffset;

		break;
	}
	case(DEN):
	{
		destinationOffset = denverOffset;

		break;
	}
	case(CHI):
	{
		destinationOffset = chicagoOffset;

		break;
	}
	case(BUF):
	{
		destinationOffset = buffaloOffset;

		break;
	}
	}
	timeOfDay += (destinationOffset - startingOffset) * HOURS;
	return timeOfDay;
}




/*
* Name		  : infoConfirmation
* Description : This function takes the input given and compares based on what type of input we have. If any of the values are out of range it lets us know.
*	   		  :
* Parameters  : int input			- The input typed by the user
*			  : int whichInputType	- The type of input, ie startcity, destcity, or time
*			  :
Return		  : outcome			-Determining if its ok to use or not
*/
int infoConfirmation(int input, int whichInputType)
{
	int outcome = 0;

	if (whichInputType == START_CITY)
	{
		if (input > MAX_CITY_NUM)
		{
			printf("\nInvalid input, range is between %d - %d\n\n", MIN_CITY_NUM, MAX_CITY_NUM);
			outcome = INVALID;
		}
		else if (input < MIN_CITY_NUM)
		{
			printf("\nInvalid input, range is between %d - %d\n\n", MIN_CITY_NUM, MAX_CITY_NUM);
			outcome = INVALID;
		}

	}
	else if (whichInputType == DEST_CITY)
	{
		if (input > MAX_CITY_NUM)
		{
			printf("\nInvalid input, range is between %d - %d\n\n", MIN_CITY_NUM, MAX_CITY_NUM);
			outcome = INVALID;
		}
		else if (input < MIN_CITY_NUM)
		{
			printf("\nInvalid input, range is between %d - %d\n\n", MIN_CITY_NUM, MAX_CITY_NUM);
			outcome = INVALID;
		}
	}
	else
	{
		if (input > DAY_TO_MINS - 1)
		{
			printf("Error invalid time given please follow 24 hour format\n");
			printf("Range is between 000%d - %d\n\n", MIN_TIME, MAX_TIME);
			outcome = INVALID;
		}
		else if (input < MIN_TIME)
		{
			printf("Error invalid time given please follow 24 hour format\n");
			printf("Range is between 000%d - %d\n\n", MIN_TIME, MAX_TIME);
			outcome = INVALID;
		}

	}
	return outcome;
}




/*
* Name		  : displayTrip
* Description : This function just displays the outcome from the flight by creating a MEGA STRING
*	   		  :
* Parameters  : vector<Flight> bestRoute		- The bestRoute we could find
*			  : int startingCity				- The city we started at
*			  : int destinationCity				- The city we are going to
*			  : int startingTime				- The time we are starting at
Return		  : nothing
*/
void displayTrip(vector<Flight> bestRoute, int startingCity, int destinationCity, int startingTime)
{
	int time = startingTime;
	int entireTripTime = 0;
	vector<Flight>::iterator bestRouteIter = bestRoute.begin();
	char timeStr[MAX_STR_LEN] = "";
#pragma region Flying From start city to destination city leaving startcity at start time
	string outputStr = "\nFlying from ";
	outputStr.append(checkStrNums(startingCity, START_CITY));	//Appends the starting city 
	outputStr.append(" to ");
	outputStr.append(checkStrNums(destinationCity, DEST_CITY));	//appends destination city

	outputStr.append(".\nStarting from  ");
	outputStr.append(checkStrNums(bestRouteIter->GetStartingCity(), START_CITY));
	outputStr.append(" at ");

	minsToNormalTime(startingTime, timeStr);
	outputStr.append(timeStr);									// Appends the time
	outputStr.append(checkStrNums(startingCity, TIME_ZONE));	//Appends timezone


#pragma endregion 

	while (bestRouteIter != bestRoute.end())
	{
#pragma region Leaving CITY at TIME TIMEZONE for DESTINATION
		outputStr.append("\nLeaving ");
		outputStr.append(checkStrNums(bestRouteIter->GetStartingCity(), START_CITY));
		outputStr.append(" at ");
		minsToNormalTime(bestRouteIter->GetDepartTime(), timeStr);
		//Adds the wait time between the starting time and departure time	////Need to take into account if we have a rollover day
		outputStr.append(timeStr);									// Appends the time
		outputStr.append(checkStrNums(startingCity, TIME_ZONE));	//Appends timezone

		if (time > bestRouteIter->GetDepartTime())
		{
			outputStr.append(" next day");
			time = (DAY_TO_MINS - time);
			entireTripTime += time;
			entireTripTime += bestRouteIter->GetDepartTime();
		}
		else
		{
			entireTripTime += bestRouteIter->GetDepartTime() - time;
		}
		outputStr.append(" for ");
		outputStr.append(checkStrNums(bestRouteIter->GetDestinationCity(), DEST_CITY));	//Appends the destination city
		time = bestRouteIter->GetDepartTime() + bestRouteIter->GetFlightTime();		//Adds the trip time to our time of day
		entireTripTime += bestRouteIter->GetFlightTime();							//Adds the flight to our overall time
#pragma endregion
#pragma region Arriving in City at TIME TIMEZONE.
		outputStr.append(".\nArriving in ");
		outputStr.append(checkStrNums(bestRouteIter->GetDestinationCity(), DEST_CITY));	//Arriving in destination city
		outputStr.append(" at ");
		time = convertTime(time, *bestRouteIter);
		minsToNormalTime(time, timeStr);				//Save the time now that it has added the time to it				///This will need to take into account the timezone changes for output
		outputStr.append(timeStr);
		outputStr.append(checkStrNums(bestRouteIter->GetDestinationCity(), TIME_ZONE));
		bestRouteIter++;

#pragma endregion

	}
	/*Print out the results from this search*/
	outputStr.append("\nTotal TravelTime: ");
	dayHourMin(entireTripTime, timeStr);
	outputStr.append(timeStr);
	outputStr.append("\n");
	printf("%s\n\n\n", outputStr.c_str());
}




/*
* Name		  : checkStrNums
* Description : This function just appends information based on what is given to our string.
*	   		  :
* Parameters  : int whichCity
*			  : int whichPart     - The output we want ie. start city, dest city, or timezone output
*			  :
Return		  : output				- The string we made
*/
string checkStrNums(int whichCity, int whichPart)
{
	string output = "";

	if (whichPart == START_CITY)
	{
		switch (whichCity)
		{
		case(TOR):
		{
			output.append(TOR_STR);
			break;
		}
		case(ATL):
		{
			output.append(ATL_STR);
			break;
		}
		case(AUS):
		{
			output.append(AUS_STR);
			break;
		}
		case(SAF):
		{
			output.append(SAF_STR);
			break;
		}
		case(DEN):
		{
			output.append(DEN_STR);
			break;
		}
		case(CHI):
		{
			output.append(CHI_STR);
			break;
		}
		case(BUF):
		{
			output.append(BUF_STR);
			break;
		}
		}

	}
	else if (whichPart == DEST_CITY)
	{
		switch (whichCity)
		{
		case(TOR):
		{
			output.append(TOR_STR);
			break;
		}
		case(ATL):
		{
			output.append(ATL_STR);
			break;
		}
		case(AUS):
		{
			output.append(AUS_STR);
			break;
		}
		case(SAF):
		{
			output.append(SAF_STR);
			break;
		}
		case(DEN):
		{
			output.append(DEN_STR);
			break;
		}
		case(CHI):
		{
			output.append(CHI_STR);
			break;
		}
		case(BUF):
		{
			output.append(BUF_STR);
			break;
		}

		}
	}

	else if (whichPart == TIME_ZONE)
	{
		switch (whichCity)
		{
		case(TOR):
		{
			output.append(EST_STR);
			break;
		}
		case(ATL):
		{
			output.append(EST_STR);
			break;
		}
		case(AUS):
		{
			output.append(CST_STR);
			break;
		}
		case(SAF):
		{
			output.append(MST_STR);
			break;
		}
		case(DEN):
		{
			output.append(MST_STR);
			break;
		}
		case(CHI):
		{
			output.append(CST_STR);
			break;
		}
		case(BUF):
		{
			output.append(EST_STR);
			break;
		}
		}
	}
	return output;
}




/*
* Name		  : dayHourMin
* Description : Takes the time given to it and continually subtracts it to determine the overall time for output from a string.
*	   		  :
* Parameters  : int time			-The given time to convert
*			  : char* timeStr		-The string that will hold the converted time
*			  :
Return		  : nothing
*/
void dayHourMin(int time, char* timeStr)
{
	char buffer[MAX_STR_LEN] = "";
	int days = 0;
	int hours = 0;
	int mins = 0;


	while (time >= DAY_TO_MINS)
	{
		time -= DAY_TO_MINS;
		days++;
	}
	if (days < 10)
	{
		sprintf(buffer, "0%d : ", days);
	}
	else
	{
		sprintf(buffer, "%d : ", days);

	}
	strcpy(timeStr, buffer);


	while (time >= HOURS)
	{
		time -= HOURS;
		hours++;
	}
	if (hours < 10)
	{
		sprintf(buffer, "0%d : ", hours);

	}
	else
	{
		sprintf(buffer, " %d : ", hours);
	}
	strcat(timeStr, buffer);
	while (time > 0)
	{
		time -= 1;
		mins++;
	}
	if (mins < 10)
	{
		sprintf(buffer, "0%d", mins);
	}
	else
	{
		sprintf(buffer, " %d", mins);

	}
	strcat(timeStr, buffer);

}




/*
* Name		  : minsToNormalTime
* Description : This function converts the time given to it and sends it to a string in our nice 12hr time format
*	   		  :
* Parameters  : int time			-The time to convert in mins
*			  : char* timeStr		- The time output in a string format
*			  :
Return		  : nothing
*/
void minsToNormalTime(int time, char* timeStr)
{
	char buffer[MAX_STR_LEN] = "";
	int days = 0;
	int hours = 0;
	int mins = 0;

	while (time >= HOURS)
	{
		time -= HOURS;
		hours++;
	}
	while (time > 0)
	{
		time -= 1;
		mins++;
	}

	if (hours >= PM)
	{
		if (hours > PM)
		{
			hours = hours - 12;
		}
		if (mins < 10)
		{
			sprintf(buffer, "%d:0%d PM", hours, mins);
		}
		else
		{
			sprintf(buffer, "%d:%d PM", hours, mins);
		}
	}
	else
	{

		if (mins < 10)
		{
			if (hours > 0)
			{
				sprintf(buffer, "%d:0%d AM", hours, mins);
			}
			else
			{
				sprintf(buffer, "12:0%d AM", mins);
			}
		}
		else
		{
			if (hours > 0)
			{
				sprintf(buffer, "%d:%d AM", hours, mins);
			}
			else
			{
				sprintf(buffer, "12:%d AM", mins);
			}
		}
	}

	std::strcpy(timeStr, buffer);
}




/*Class: Flight - Constructor Methods***********************************************/
/*
* Name		  : Flight
* Description : Default constructor
*	   		  :
* Parameters  : void
*			  :
*			  :
Return		  :
*/
Flight::Flight(void)
{
	SetStartingCity(TOR);
	SetDestinationCity(ATL);
	SetDepartTime(kTOR_FLIGHTS[DEP][0]);
	SetFlightTime(kTOR_FLIGHTS[FLI][0]);
}




/*
* Name		  : Flight()
* Description : Custom Constructor
*	   		  :
* Parameters  : int startingCity
*			  : int destinationCity
*			  : int startTime, int travelTime
Return		  :
*/
Flight::Flight(int startingCity, int destinationCity, int startTime, int travelTime)
{
	SetStartingCity(startingCity);
	SetDestinationCity(destinationCity);
	SetDepartTime(startTime);
	SetFlightTime(travelTime);
}




/*Class: Flight - FlightTime Methods***********************************************/
/*
* Name		  : GetFlightTime
* Description : Accessor
*	   		  :
* Parameters  : void
*			  :
*			  :
Return		  : int flightTime
*/
int Flight::GetFlightTime(void)
{
	return flightTime;
}




/*
* Name		  : SetFlightTime
* Description : Mutator - Takes a new time and checks if it is a valid time. If it is it will set the flightTime.
*	   		  :
* Parameters  : int travelTime
*			  :
*			  :
Return		  : bool success - Determined by value given. True - valid/ False - Not valid
*/
bool Flight::SetFlightTime(int travelTime)
{
	bool success = false;

	if (ValidateFlightTime(travelTime, startingCity) == true)
	{

		flightTime = travelTime;
		success = true;
	}

	return success;
}




/*
* Name		  : ValidateFlightTime
* Description : Validator
*	   		  :
* Parameters  : int travelTime
*			  : int cityName
*			  :
Return		  :bool success determined based on value given
*/
bool Flight::ValidateFlightTime(int travelTime, int cityName)
{
	bool success = false;
	switch (cityName)
	{
	case(TOR):
		for (int i = 0; i < TOR_FLIGHTS; i++)
		{
			if (kTOR_FLIGHTS[FLI][i] == travelTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(ATL):
		for (int i = 0; i < ATL_FLIGHTS; i++)
		{
			if (kATL_FLIGHTS[FLI][i] == travelTime)
			{
				success = true;
				break;
			}
		}
		break; //const int kCityNumList[AMT_CITIES] = { TOR, ATL, AUS, SAF, DEN, CHI, BUF };

	case(AUS):
		for (int i = 0; i < AUS_FLIGHTS; i++)
		{
			if (kAUS_FLIGHTS[FLI][i] == travelTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(SAF):
		for (int i = 0; i < SAF_FLIGHTS; i++)
		{
			if (kSAF_FLIGHTS[FLI][i] == travelTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(DEN):
		for (int i = 0; i < DEN_FLIGHTS; i++)
		{
			if (kDEN_FLIGHTS[FLI][i] == travelTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(CHI):

		for (int i = 0; i < CHI_FLIGHTS; i++)
		{
			if (kCHI_FLIGHTS[FLI][i] == travelTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(BUF):
		for (int i = 0; i < BUF_FLIGHTS; i++)
		{
			if (kBUF_FLIGHTS[FLI][i] == travelTime)
			{
				success = true;
				break;
			}
		}
	}
	return success;
}




/*Class: Flight - DepartureTime Methods************************************************/
/*
* Name		  : GetFlightTime
* Description : Accessor
*	   		  :
* Parameters  : void
*			  :
*			  :
Return		  :
*/
int Flight::GetDepartTime(void)
{
	return departure;
}




/*
* Name		  : SetDepartTime
* Description : Mutator
*	   		  :
* Parameters  : int departureTime
*			  :
*			  :
Return		  : bool success
*/
bool Flight::SetDepartTime(int departureTime)
{
	bool success = false;

	if (ValidateDepartTime(departureTime, startingCity) == true)
	{
		departure = departureTime;
		success = true;
	}

	return success;
}




/*
* Name		  : GetFlightTime
* Description : Accessor
*	   		  :
* Parameters  : void
*			  :
*			  :
Return		  :
*/
bool Flight::ValidateDepartTime(int departureTime, int cityName)
{
	bool success = false;
	switch (cityName)
	{
	case(TOR):
		for (int i = 0; i < TOR_FLIGHTS; i++)
		{
			if (kTOR_FLIGHTS[DEP][i] == departureTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(ATL):
		for (int i = 0; i < ATL_FLIGHTS; i++)
		{
			if (kATL_FLIGHTS[DEP][i] == departureTime)
			{
				success = true;
				break;
			}
		}
		break; //const int kCityNumList[AMT_CITIES] = { TOR, ATL, AUS, SAF, DEN, CHI, BUF };

	case(AUS):
		for (int i = 0; i < AUS_FLIGHTS; i++)
		{
			if (kAUS_FLIGHTS[DEP][i] == departureTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(SAF):
		for (int i = 0; i < SAF_FLIGHTS; i++)
		{
			if (kSAF_FLIGHTS[DEP][i] == departureTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(DEN):
		for (int i = 0; i < DEN_FLIGHTS; i++)
		{
			if (kDEN_FLIGHTS[DEP][i] == departureTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(CHI):

		for (int i = 0; i < CHI_FLIGHTS; i++)
		{
			if (kCHI_FLIGHTS[DEP][i] == departureTime)
			{
				success = true;
				break;
			}
		}
		break;

	case(BUF):
		for (int i = 0; i < BUF_FLIGHTS; i++)
		{
			if (kBUF_FLIGHTS[DEP][i] == departureTime)
			{
				success = true;
				break;
			}
		}
	}
	return success;
}




/*Class: Flight - DestinationCity Methods***********************************************/
/*
* Name		  : GetDestinationCity
* Description : Accessor
*	   		  :
* Parameters  : void
*			  :
*			  :
Return		  :int destinationCity
*/
int Flight::GetDestinationCity(void)
{
	return destinationCity;
}



/*
* Name		  : ValidateDestinationCity
* Description : Validator
*	   		  :
* Parameters  : int nextCity
*			  :
*			  :
Return		  : bool success
*/
bool Flight::ValidateDestinationCity(int nextCity)
{
	bool success = false;

	for (int i = 0; i < AMT_CITIES; i++)
	{
		if (nextCity == kCityNumList[i])//Compares to the constant holding all the city numbers
		{
			success = true;// if we found one great, return true
			break;
		}
	}
	return success;
}



/*
* Name		  : SetDestinationCity
* Description : Mutator
*	   		  :
* Parameters  : int nextCity
*			  :
*			  :
Return		  : bool success
*/
bool Flight::SetDestinationCity(int nextCity)
{
	bool success = false;

	if (ValidateDestinationCity(nextCity) == true)
	{
		destinationCity = nextCity;
		success = true;
	}

	return success;
}




/*Class: Flight - StartingCity Methods***********************************************/
/*
* Name		  : GetStartingCity
* Description : Accessor
*	   		  :
* Parameters  : void
*			  :
*			  :
Return		  : startingCity
*/
int Flight::GetStartingCity(void)
{
	return startingCity;
}




/*
* Name		  : SetStartingCity
* Description : Mutator
*	   		  :
* Parameters  : int newCity
*			  :
*			  :
Return		  : bool success
*/
bool Flight::SetStartingCity(int newCity)
{
	bool success = false;

	if (ValidateStartingCity(newCity) == true)
	{
		startingCity = newCity;
		success = true;
	}
	return success;
}




/*
* Name		  : ValidateStartingCity
* Description : Validator
*	   		  :
* Parameters  : int newCIty
*			  :
*			  :
Return		  : bool success
*/
bool Flight::ValidateStartingCity(int newCity)
{
	bool success = false;

	for (int i = 0; i < AMT_CITIES; i++)
	{
		if (newCity == kCityNumList[i])
		{
			success = true;
		}
	}
	return success;

}




/*Class: Flight - Destructor Method*************************************************/
/*
* Name		  : ~Flight
* Description : Destructor
*	   		  :
* Parameters  : void
*			  :
*			  :
Return		  :
*/
Flight::~Flight(void)
{
	//This is my destructor
}




//Intentionally hid this ugly code away... Dont look at it
/*
* Name		  : initializeCityInfo
* Description : This function will initialize all of the cities with their relevent travel information.
*	   		  :
* Parameters  : void
*			  :
*			  :
* Return	  : A map with all of the cities(as keys) and their different travel loctions, as well as the flight information for those cities
*/
map<int, vector<Flight>> initializeCityInfo(void)
{

	vector<Flight> FlightVect;
	map<int, vector<Flight>> airports;
	Flight torontoArray[TOR_FLIGHTS];
	Flight atlantaArray[ATL_FLIGHTS];
	Flight austinArray[AUS_FLIGHTS];
	Flight santaFeArray[SAF_FLIGHTS];
	Flight denverArray[DEN_FLIGHTS];
	Flight chicagoArray[CHI_FLIGHTS];
	Flight buffaloArray[BUF_FLIGHTS];

	/*Toronto Times Initialization********************************/
	for (int i = 0; i < TOR_FLIGHTS; i++)
	{
		if (i < TOR_DEN_INDX)
		{
			if (i < TOR_DEN_INDX)
			{
				torontoArray[i].SetStartingCity(TOR);
				torontoArray[i].SetDestinationCity(ATL);
				torontoArray[i].SetDepartTime(kTOR_FLIGHTS[DEP][i]);
				torontoArray[i].SetFlightTime(kTOR_FLIGHTS[FLI][i]);

			}
		}

		else if (i < TOR_CHI_INDX)
		{
			if (i < TOR_CHI_INDX)
			{
				torontoArray[i].SetStartingCity(TOR);
				torontoArray[i].SetDestinationCity(DEN);
				torontoArray[i].SetDepartTime(kTOR_FLIGHTS[DEP][i]);
				torontoArray[i].SetFlightTime(kTOR_FLIGHTS[FLI][i]);

			}
		}
		else
		{
			if (i < TOR_FLIGHTS)
			{
				torontoArray[i].SetStartingCity(TOR);
				torontoArray[i].SetDestinationCity(CHI);
				torontoArray[i].SetDepartTime(kTOR_FLIGHTS[DEP][i]);
				torontoArray[i].SetFlightTime(kTOR_FLIGHTS[FLI][i]);
			}

		}
	}

	FlightVect.insert(FlightVect.end(), &torontoArray[0], &torontoArray[TOR_FLIGHTS]);
	airports.emplace(TOR, FlightVect);//This line works as currently the vectors are only filled with toronto information, however, on atlanta we want to have the info 
	FlightVect.clear();			// I want to clear the vector so i can add the next cities information in
	/*Atlanta Times Initialization********************************/
	for (int i = 0; i < ATL_FLIGHTS; i++)
	{
		if (i < ATL_AUS_INDX)
		{
			atlantaArray[i].SetStartingCity(ATL);
			atlantaArray[i].SetDestinationCity(TOR);
			atlantaArray[i].SetDepartTime(kATL_FLIGHTS[DEP][i]);
			atlantaArray[i].SetFlightTime(kATL_FLIGHTS[FLI][i]);
		}
		else if (i < ATL_DEN_INDX)
		{
			atlantaArray[i].SetStartingCity(ATL);
			atlantaArray[i].SetDestinationCity(AUS);
			atlantaArray[i].SetDepartTime(kATL_FLIGHTS[DEP][i]);
			atlantaArray[i].SetFlightTime(kATL_FLIGHTS[FLI][i]);
		}
		else if (i < ATL_CHI_INDX)
		{
			atlantaArray[i].SetStartingCity(ATL);
			atlantaArray[i].SetDestinationCity(DEN);
			atlantaArray[i].SetDepartTime(kATL_FLIGHTS[DEP][i]);
			atlantaArray[i].SetFlightTime(kATL_FLIGHTS[FLI][i]);
		}
		else
		{
			atlantaArray[i].SetStartingCity(ATL);
			atlantaArray[i].SetDestinationCity(CHI);
			atlantaArray[i].SetDepartTime(kATL_FLIGHTS[DEP][i]);
			atlantaArray[i].SetFlightTime(kATL_FLIGHTS[FLI][i]);
		}
	}

	FlightVect.insert(FlightVect.end(), &atlantaArray[0], &atlantaArray[ATL_FLIGHTS]);
	airports.emplace(ATL, FlightVect);
	FlightVect.clear();
	/*Austin Times Initialization********************************/

	for (int i = 0; i < AUS_FLIGHTS; i++)
	{
		if (i < AUS_DEN_INDX)
		{
			austinArray[i].SetStartingCity(AUS);
			austinArray[i].SetDestinationCity(ATL);
			austinArray[i].SetDepartTime(kAUS_FLIGHTS[DEP][i]);
			austinArray[i].SetFlightTime(kAUS_FLIGHTS[FLI][i]);
		}
		else if (i < AUS_SAF_INDX)
		{
			austinArray[i].SetStartingCity(AUS);
			austinArray[i].SetDestinationCity(DEN);
			austinArray[i].SetDepartTime(kAUS_FLIGHTS[DEP][i]);
			austinArray[i].SetFlightTime(kAUS_FLIGHTS[FLI][i]);
		}
		else
		{
			austinArray[i].SetStartingCity(AUS);
			austinArray[i].SetDestinationCity(SAF);
			austinArray[i].SetDepartTime(kAUS_FLIGHTS[DEP][i]);
			austinArray[i].SetFlightTime(kAUS_FLIGHTS[FLI][i]);
		}
	}

	FlightVect.insert(FlightVect.end(), &austinArray[0], &austinArray[AUS_FLIGHTS]);
	airports.emplace(AUS, FlightVect);
	FlightVect.clear();

	/*SantaFe Times Initialization********************************/
	for (int i = 0; i < SAF_FLIGHTS; i++)
	{

		santaFeArray[i].SetStartingCity(SAF);
		santaFeArray[i].SetDestinationCity(AUS);
		santaFeArray[i].SetDepartTime(kSAF_FLIGHTS[DEP][i]);
		santaFeArray[i].SetFlightTime(kSAF_FLIGHTS[FLI][i]);
	}

	FlightVect.insert(FlightVect.end(), &santaFeArray[0], &santaFeArray[SAF_FLIGHTS]);
	airports.emplace(SAF, FlightVect);
	FlightVect.clear();
	/*Denver Times Initialization********************************/
	for (int i = 0; i < DEN_FLIGHTS; i++)
	{
		if (i < DEN_ATL_INDX)
		{
			denverArray[i].SetStartingCity(DEN);
			denverArray[i].SetDestinationCity(TOR);
			denverArray[i].SetDepartTime(kDEN_FLIGHTS[DEP][i]);
			denverArray[i].SetFlightTime(kDEN_FLIGHTS[FLI][i]);
		}
		else if (i < DEN_AUS_INDX)
		{
			denverArray[i].SetStartingCity(DEN);
			denverArray[i].SetDestinationCity(ATL);
			denverArray[i].SetDepartTime(kDEN_FLIGHTS[DEP][i]);
			denverArray[i].SetFlightTime(kDEN_FLIGHTS[FLI][i]);
		}
		else if (i < DEN_CHI_INDX)
		{
			denverArray[i].SetStartingCity(DEN);
			denverArray[i].SetDestinationCity(AUS);
			denverArray[i].SetDepartTime(kDEN_FLIGHTS[DEP][i]);
			denverArray[i].SetFlightTime(kDEN_FLIGHTS[FLI][i]);
		}
		else
		{
			denverArray[i].SetStartingCity(DEN);
			denverArray[i].SetDestinationCity(CHI);
			denverArray[i].SetDepartTime(kDEN_FLIGHTS[DEP][i]);
			denverArray[i].SetFlightTime(kDEN_FLIGHTS[FLI][i]);
		}
	}

	FlightVect.insert(FlightVect.end(), &denverArray[0], &denverArray[DEN_FLIGHTS]);
	airports.emplace(DEN, FlightVect);
	FlightVect.clear();

	/*Chicago Times Initialization********************************/
	for (int i = 0; i < CHI_FLIGHTS; i++)
	{
		if (i < CHI_ATL_INDX)
		{
			chicagoArray[i].SetStartingCity(CHI);
			chicagoArray[i].SetDestinationCity(TOR);
			chicagoArray[i].SetDepartTime(kCHI_FLIGHTS[DEP][i]);
			chicagoArray[i].SetFlightTime(kCHI_FLIGHTS[FLI][i]);
		}
		else if (i < CHI_DEN_INDX)
		{
			chicagoArray[i].SetStartingCity(CHI);
			chicagoArray[i].SetDestinationCity(ATL);
			chicagoArray[i].SetDepartTime(kCHI_FLIGHTS[DEP][i]);
			chicagoArray[i].SetFlightTime(kCHI_FLIGHTS[FLI][i]);
		}
		else if (i < CHI_BUF_INDX)
		{
			chicagoArray[i].SetStartingCity(CHI);
			chicagoArray[i].SetDestinationCity(DEN);
			chicagoArray[i].SetDepartTime(kCHI_FLIGHTS[DEP][i]);
			chicagoArray[i].SetFlightTime(kCHI_FLIGHTS[FLI][i]);
		}
		else
		{
			chicagoArray[i].SetStartingCity(CHI);
			chicagoArray[i].SetDestinationCity(BUF);
			chicagoArray[i].SetDepartTime(kCHI_FLIGHTS[DEP][i]);
			chicagoArray[i].SetFlightTime(kCHI_FLIGHTS[FLI][i]);
		}
	}

	FlightVect.insert(FlightVect.end(), &chicagoArray[0], &chicagoArray[CHI_FLIGHTS]);
	airports.emplace(CHI, FlightVect);
	FlightVect.clear();

	/*Buffalo Times Initialization********************************/
	for (int i = 0; i < BUF_FLIGHTS; i++)
	{

		buffaloArray[i].SetStartingCity(BUF);
		buffaloArray[i].SetDestinationCity(CHI);
		buffaloArray[i].SetDepartTime(kBUF_FLIGHTS[DEP][i]);
		buffaloArray[i].SetFlightTime(kBUF_FLIGHTS[FLI][i]);
	}

	FlightVect.insert(FlightVect.end(), &buffaloArray[0], &buffaloArray[BUF_FLIGHTS]);
	airports.emplace(BUF, FlightVect);
	FlightVect.clear();


	return airports;
}