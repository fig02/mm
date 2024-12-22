#ifndef COVERAGE_H
#define COVERAGE_H

#include "PR/ultratypes.h"
#include "z64save.h"
#include "z64game.h"

void set_coverage_flag(u8* array, s32 index);
void draw_coverage_info(GameState* gamestate);

#endif
