/*
 * template.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Mohamed Nabil
 */

#include"../header/template.h"
uint8 takeChoice(uint8 stage)
{
	uint8 choice;
	switch(stage)
	{
	case 1:
		printf("What do you want?\n  [1]Turn on the vehicle engine\n  [2]Turn off the vehicle engine\n  [3]Quit the system\n");
		do{
			scanf("%d",&choice);
		}while(choice!=1&&choice!=2&&choice!=3);
		break;
	case 2:
		printf("choose one choice\n");
		printf("  [a]Turn off the engine\n");
		printf("  [b]Set the traffic light color\n");
		printf("  [c]Set the room temperature (Temperature Sensor)\n");
		printf("  [d]Set the engine temperature (Engine Temperature Sensor)\n");
		do{
			scanf(" %c",&choice);
		}while(choice!='a'&&choice!='b'&&choice!='c'&&choice!='d');
		break;
	}
	return choice;
}


void setVehicleSpeed(void)
{
	switch(theState.trafficLight)
	{
	case 'G':
		theState.vehicleSpeed = 100;
		break;
	case 'O':
		theState.vehicleSpeed = 30;
		break;
	case 'R':
		theState.vehicleSpeed = 0;
		break;
	default:
		break;
	}
}


void setTrafficLight(void)
{
	printf("enter the current light\n");
	scanf(" %c",&theState.trafficLight);
}
void setRoomTemperature(void)
{
	printf("enter the room temperature\n");
	scanf("%d",&theState.roomTemp);
}
void setEngineTemperature(void)
{
	printf("enter the engine temperature\n");
	scanf("%d",&theState.engineTemp);
}


void setAC(void)
{
	if(theState.roomTemp<10||theState.roomTemp>30)
	{
		theState.AC = true;
		theState.roomTemp=20;
	}
	else
	{
		theState.AC = false;
	}
}

void setEngineTempController(void)
{
	if(theState.engineTemp>150||theState.engineTemp<100)
	{
		theState.engineTempController=true;
		theState.engineTemp=125;
	}
	else
	{
		theState.engineTempController=false;
	}
}

void checkSpeed(void)
{
	if(theState.vehicleSpeed==30)
	{
		theState.AC=true;
		theState.engineTempController=true;
		theState.roomTemp=theState.roomTemp*(5.0/4)+1;
		theState.engineTemp=theState.engineTemp*(5.0/4)+1;
	}
}

void printState(void)
{
	printf("################################################\n");
	printf("####################the State:##################\n");
	printf("################################################\n");
	printf("#[1] AC:                                 ");puts(theState.AC?"ON":"OFF");
	printf("#[2] Engine State:                       ");puts(theState.engineState?"ON":"OFF");
	printf("#[3] vehicle Speed:                      %d\n",theState.vehicleSpeed);
	printf("#[4] room temperature:                   %d\n",theState.roomTemp);
	printf("#[5] engine temperature controller state:");puts(theState.engineTempController?"ON":"OFF");
	printf("#[6] engine temperature:                 %d\n",theState.engineTemp);
	printf("################################################\n");
}
void initState(void)
{
	theState.AC=false;
	theState.engineState=false;
	theState.engineTemp=0;
	theState.engineTempController=false;
	theState.roomTemp=0;
	theState.trafficLight=0;
	theState.vehicleSpeed=0;
}
