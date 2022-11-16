/*
 * template.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Mohamed Nabil
 */

#ifndef HEADER_TEMPLATE_H_
#define HEADER_TEMPLATE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*to flush the outputs continupusly*/
#define flush setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);


/*define the datatypes*/
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned long uint64;
typedef signed short int64;
typedef unsigned long long uint128;
typedef signed long long int128;

#define loop(k,n) for(int8 q = k;q<n;q++)

/*macros*/
#define OnEngine theState.engineState=true;printf("turn on the engine\n")
#define OffEngine theState.engineState=false;printf("turn off the engine\n");

/*the used Functions*/
uint8 takeChoice(uint8);
void printState(void);
void setVehicleSpeed(void);
void setTrafficLight(void);
void setRoomTemperature(void);
void setEngineTemperature(void);
void setAC(void);
void setEngineTempController(void);
void checkSpeed(void);
void initState(void);


/*bool enum*/
typedef enum{
	false,
	true
}bool;


/*the struct of the state*/
typedef struct{
	int8 roomTemp;
	int16 engineTemp;
	uint8 trafficLight;
	uint16 vehicleSpeed;
	bool AC;
	bool engineTempController;
	bool engineState;
}state;

/*to make the state is identified by the file template.c as it declared in source.c*/
extern state theState;
#endif /* HEADER_TEMPLATE_H_ */
