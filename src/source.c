/*
 * source.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Mohamed Nabil
 */


#include"../header/template.h"

state theState;/*the state of the engine and the room*/
bool notBreaked = true; /*this to control the flow of the program in the first choice*/

int main(void)
{
	flush
	initState();
	while(true){
		/*take the first choice does he want to operate the engine or not*/
		switch(takeChoice(1))
		{
		case 1:   /*we will open the engine....*/
			OnEngine;  /*set the state of the engine = ON and print the State of the machine*/
			notBreaked = true;
			while(notBreaked){
				switch(takeChoice(2)) /*take the second choice when the engine is ON*/
				{
				case 'a':
					printf("Turning OFF...\n");
					notBreaked = false;
					break;
				case 'b':
					/*set the traffic light in theState*/
					setTrafficLight();
					break;
				case 'c':
					/*set the temperature of the room in theState*/
					setRoomTemperature();
					break;
				case 'd':
					/*set the temperature of the engine in theState*/
					setEngineTemperature();
					break;
				default:
					break;
				}
				setVehicleSpeed();
				setAC();
				setEngineTempController();
				checkSpeed();
				printState();
			}
			break;
		case 2: /*off the engine*/
			OffEngine;
			continue;
			break;
		case 3:
			printf("Quitting...\n");
			return 0;
		default:
			return 0;
		}
	}
	return 0;
}
