#include "draw.h"
#include "structs.h"

extern App app;

void prepareScene(void) {
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void) {
	SDL_RenderPresent(app.renderer);
}

static SDL_Texture* getTexture(char* name) {
	Texture* t;

	for (t = app.textureHead.next; t != NULL; t = t->next) {
		if (strcmp(t->name, name) == 0) {
			return t->texture;
		}
	}
	return NULL;
}

static void addTextureToCache(char* name, SDL_Texture* sdlTexture) {
	Texture* texture;

	texture = malloc(sizeof(Texture));
	memset(texture, 0, sizeof(Texture));
	app.textureTail->next = texture;
	app.textureTail = texture;

	STRNCPY(texture->name, name, MAX_NAME_LENGTH);
	texture->texture = sdlTexture;
}

SDL_Texture* loadTexture(char* fileName) {
	SDL_Texture* texture;
	texture = getTexture(fileName);
	if (texture == NULL) {
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", fileName);
		texture = IMG_LoadTexture(app.renderer, fileName);
		addTextureToCache(fileName, texture);
	}
	return texture;
}

void blit(SDL_Texture* texture, int x, int y) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void blitRect(SDL_Texture* texture, SDL_Rect* src, int x, int y) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = src->w;
	dest.h = src->h;

	SDL_RenderCopy(app.renderer, texture, src, &dest);
}