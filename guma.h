#ifndef GUMA_H
#define GUMA_H

#include "guma.h"

typedef struct Guma
	{
		char* pismena;
		unsigned int delka;
		unsigned int ukazovatko;
		struct Guma* dalsi; 
	} Guma;
	
Guma* VytvorGumu (int delka)
	{
		Guma* pGuma = NULL;
		//printf("\nvytvarim blok velikosti %d\n", delka);
		pGuma = malloc(sizeof(Guma));
		(*pGuma).pismena = malloc(sizeof(char)*delka);  // podle pouziti by zde bylo dobre plnit pole nulama, abych jednou nevypisovala kraviny
		(*pGuma).delka = delka;
		(*pGuma).ukazovatko = 0;
		(*pGuma).dalsi = NULL;
		return  pGuma;
	};

void SmazGumu (Guma** pGuma)
	{
		if (*pGuma == NULL)
			{
				return;
			};
		
		free((**pGuma).pismena);
		SmazGumu(&(**pGuma).dalsi);
		free(*pGuma);
		*pGuma = NULL;
	};
	
void VlozDoGumy (Guma** pGuma, int index, char pismeno)
	{
		Guma* pivot = *pGuma; 
		
		if (pivot == NULL) //pokud nemám žádnou Gumu
			{
				*pGuma = VytvorGumu((index+1)*2); // vytváøím Gumu a vracím ukazatel na Gumu, vìtší velikost než na jaké místo zapisuju
				pivot = *pGuma;  // nasatvujeme pivot na novì vytvoøenou Gumu	
			};
		
		while (index >= ((*pivot).delka))	//kontrola, do jaké èásti Gumy budu vkládat char
			{
				index = index - (*pivot).delka;
				if ((*pivot).dalsi == NULL)
					{
						pivot = (*pivot).dalsi = VytvorGumu((*pivot).delka*2);
					}
					else
						{
							pivot = (*pivot).dalsi;	
						};
			};
		
		(*pivot).ukazovatko = index;	// pri vypisu Gumy budu potrebovat vedet, kde skoncit v posledni casti
		(*pivot).pismena[index] = pismeno;
	};
	
int VypisGumu (Guma* pGuma)
	{
		Guma* pivot = pGuma;
		int i = 0;
		
		if (pivot == NULL)
			{
				//printf("Není co vypsat.");
				return 1;
			};
		
		int j = 0;
		
		while (pivot != NULL)
			{
				//printf("\njsem v bloku %d\n", j++);
				for (i = 0; i <= (*pivot).ukazovatko; i++)
					{
						printf("\%c", (*pivot).pismena[i]);
					};
				pivot = (*pivot).dalsi;
			};
	};
	
int Vrat (Guma* pGuma, int index, char* pismeno)
	{
		Guma* pivot = pGuma; 
		
		if (pivot == NULL) //pokud nemám žádnou Gumu
			{
				//printf("Není co vypsat.");
				return 1;	
			};
		
		while (index >= ((*pivot).delka))	//kontrola, do jaké èásti Gumy budu vkládat char
			{
				index = index - (*pivot).delka;
				if ((*pivot).dalsi == NULL)
					{
						return 1;
					}
					else
						{
							pivot = (*pivot).dalsi;
						};
			};
		if ((*pivot).ukazovatko < index)
			{
				return 1;
			};
			
		*pismeno = (*pivot).pismena[index];
		return 0;
	};
	
int DelkaGumy(Guma* pGuma)
	{
		int delka = 0;
		Guma* pivot = pGuma;
		
		while (pivot != NULL)
		{
			delka = delka + (*pivot).ukazovatko + 1;
			pivot = (*pivot).dalsi;
		}
		return delka;
	};

char* GumaNaRetezec (Guma* pGuma)
	{
		Guma* pivot = pGuma;
		int i = 0;
		int delka = DelkaGumy(pGuma);
		
		char* retezec = malloc(sizeof(char)*delka + 1);
		retezec[delka] = '\0';
		
		if (pivot == NULL)
			{
				return retezec;
			};
		
		int j = 0;
		
		while (pivot != NULL)
			{
				for (i = 0; i <= (*pivot).ukazovatko; i++)
					{
						retezec[j] = (*pivot).pismena[i];
						j++;
					};
				pivot = (*pivot).dalsi;
			};
		return retezec;
	};
#endif
