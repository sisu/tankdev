void* loadAI(const char* path);

void freeAI(void* AI);

void runAI(void* AI, Player* player, Gamestate* world);
