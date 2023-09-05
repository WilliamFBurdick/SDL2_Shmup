#pragma once
#include <SDL.h>

typedef struct Entity Entity;
typedef struct Explosion Explosion;
typedef struct Debris Debris;
typedef struct Texture Texture;

typedef struct {
	void (*logic)(void);
	void (*draw)(void);
} Delegate;

struct Texture {
	char name[MAX_NAME_LENGTH];
	SDL_Texture* texture;
	Texture* next;
};

typedef struct {
	SDL_Renderer* renderer;
	SDL_Window* window;
	Delegate delegate;
	int keyboard[MAX_KEYBOARD_KEYS];
	Texture textureHead, * textureTail;
	char inputText[MAX_LINE_LENGTH];
}App;

struct Entity {
	float x, y;
	int w, h;
	float dx, dy;
	int health;
	int reload;
	int side;
	SDL_Texture* texture;
	Entity* next;
};

struct Explosion {
	float x, y;
	float dx, dy;
	int r, g, b, a;
	Explosion* next;
};

struct Debris {
	float x, y;
	float dx, dy;
	SDL_Rect rect;
	SDL_Texture* texture;
	int life;
	Debris* next;
};

typedef struct {
	Entity fighterHead, *fighterTail;
	Entity bulletHead, *bulletTail;
	Explosion explosionHead, *explosionTail;
	Debris debrisHead, *debrisTail;
	Entity pointsHead, * pointsTail;
	int score;
} Stage;


typedef struct {
	int x, y;
	int speed;
} Star;

typedef struct {
	char name[MAX_SCORE_NAME_LENGTH];
	int recent;
	int score;
} Highscore;

typedef struct {
	Highscore highscore[NUM_HIGHSCORES];
} Highscores;