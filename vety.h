#ifndef VETY_H
#define VETY_H

#include "guma.h"

char* VratVetu(FILE* soubor)
{
	const char* whiteSpace = ":.,;-\" \t\n";//preskakuju znaky, ktere samy o sobe nejsou veta, hlavne na zacatku souboru
	const char* konecVety = ".?!";	
	char znak = 0;
	char* veta = NULL;
	Guma* pGuma = NULL;
		
	if (soubor == NULL)
	 	{
		 	// printf("Soubor je prazdny");
			return NULL;
		};	//kontrola, ze soubor neni null
	//printf("\%s", whiteSpace);
	znak = fgetc(soubor);
	
	while ((znak != EOF) && (strchr(whiteSpace, znak))) //kontrola na konec souboru a na znaky, ktere nejsou zacatek vety
		{
			znak = fgetc(soubor);
		};
	
	int j = 0;
		
	while ((znak != EOF) && (!strchr(konecVety, znak)))	//kontrola konec vety
		{
			VlozDoGumy(&pGuma,j,znak);
			//printf("\%c", znak);
			znak = fgetc(soubor);
			j++;	
		};
											
	if (znak != EOF)
	 	{
		 	VlozDoGumy(&pGuma,j,znak);
		};
	
	if (znak == EOF)
		{
			return NULL;
		};

	veta = GumaNaRetezec(pGuma);
	SmazGumu(&pGuma);
	return veta;
};
#endif
