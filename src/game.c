#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int areaW, areaH;
char* tiles;

void loadMap(const char* file)
{
	FILE* f = fopen(file, "r");
	fscanf(f, "%d%d", &areaW, &areaH);
	tiles = malloc(areaW*areaH);
	for(int i=0; i<areaH; ++i) {
		// TODO: fix overflow
		fscanf(f, "%s", tiles+i*areaW);
		for(int j=0; j<areaW; ++j)
			tiles[areaW*i+j] = tiles[areaW*i+j]=='#';
	}
	fclose(f);
}

void updatePhysics()
{
}
