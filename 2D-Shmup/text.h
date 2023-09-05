#pragma once

#define GLYPH_HEIGHT 28
#define GLYPH_WIDTH 18

void initFonts(void);
void drawText(int x, int y, int r, int g, int b, int align, char* format, ...);