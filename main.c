//Set��d�n� textov�ho souboru podle v�t
//Vypi�te abecedn� set��d�n� v�ty, kter� se vyskytuj� v zadan�m textov�m souboru.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vety.h"
#include "strom.h"
#include "guma.h"

int main(int argc, char** argv)
{
	char* veta = NULL;
	FILE* soubor;
	char* nazevSouboru;
	Strom* pStrom = NULL;
	
	nazevSouboru = argv[1];
	soubor = fopen(nazevSouboru,"r");
	
    veta = VratVetu(soubor);
    printf("\n%s", veta);
    while (veta != NULL)
    	{
			VlozDoStromu(&pStrom,veta);
			veta = VratVetu(soubor);
			printf("\n%s", veta);
		};
    fclose(soubor);	
    VypisStrom(pStrom);
    SmazStrom(&pStrom);
	getchar();
	return 0;	
};
