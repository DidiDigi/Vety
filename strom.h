#ifndef STROM_H
#define STROM_H

typedef struct Strom
	{
		char* hodnota;
		struct Strom* left;
		struct Strom* right; 
	} Strom;
	
Strom* VytvorStrom(char* hodnota)
	{
		Strom* pStrom = NULL;
		
		pStrom = malloc(sizeof(Strom));
		(*pStrom).hodnota = hodnota;
		(*pStrom).left = NULL;
		(*pStrom).right = NULL;
		
		return  pStrom;
	};

void SmazStrom(Strom** pStrom)
	{
		if (*pStrom == NULL)
			{
				return;
			};
		
		free((**pStrom).hodnota);
		SmazStrom(&(**pStrom).left);
		SmazStrom(&(**pStrom).right);
		free(*pStrom);
		*pStrom = NULL;
	};
	
void VlozDoStromu (Strom** ppStrom, char* hodnota)
	{
		Strom* pivot = *ppStrom;
		Strom* novy = NULL;
		int smer = 0;
		Strom* otec = NULL; 
		
		if (pivot == NULL) //pokud nemám zadny Strom
			{
				*ppStrom = VytvorStrom(hodnota); // vytvarim prvni uzel Stromu
				return;  // nasatvujeme pivot na nove vytvoreny uzel	
			};
			
		
		while (pivot != NULL)	//kontrola, do jaké èásti Stromu budu vkládat char*
			{
				smer = strcmp(hodnota, (*pivot).hodnota);
				if (smer == 0)
					{
						return;
					};
					
				if (smer < 0)
					{
      					otec = pivot;
						pivot = (*pivot).left;
         			};
         		
				 if (smer > 0)
					{
      					otec = pivot;
						pivot = (*pivot).right;
         			};
       		};
		    // vlozeni noveho uzlu do stromu  		
        if (smer > 0)
			{
				novy = VytvorStrom(hodnota);
				(*otec).right = novy;
			};
		
		 if (smer < 0)
			{
				novy = VytvorStrom(hodnota);
				(*otec).left = novy;	
			};
		return;
	};

int VypisStrom (Strom* pStrom)
	{
		Strom* pivot = pStrom;
					
		if (pivot == NULL)
			{
				return 1;
			};
		
		if (((*pivot).left) != NULL)
			{
				VypisStrom(((*pivot).left));
			}
			else
				{
					printf("\n%s", (*pivot).hodnota);
//					printf("\n");
//					printf("*******************************\n");
				};
				
		if (((*pivot).right))
			{
				VypisStrom(((*pivot).right));
			};
	};
#endif
