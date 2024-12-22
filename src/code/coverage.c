#include "coverage.h"
#include "z64.h"
#include "gfxalloc.h"
#include "macros.h"

void set_coverage_flag(u8* array, s32 index) {
    u8 page = index >> 3; // divide by 8, number of bits per page
    u8 flag = index % 8; // mod by 8, number of bits per page

    array[page] |= (1 << flag);
}

#define COUNT_BITS(array) count_bits_in_bytes(array, ARRAY_COUNT(array))

u32 count_bits_in_bytes(u8* array, u32 count) {
    u32 i;
    u32 j;
    u32 ret = 0;

    for (i = 0; i < count; i++) {
        u8 byte = array[i];

        for (j = 0; j < 8; j++) {
            if (byte & 1) {
                ret++;
            }
            byte >>= 1;
        }
    }

    return ret;
}

void draw_coverage_info(GameState* gamestate) {
    GfxPrint printer;
    Gfx* gfxRef;
    Gfx* gfx;

    OPEN_DISPS(gamestate->gfxCtx);

    Gfx_SetupDL28_Opa(gamestate->gfxCtx);

    GfxPrint_Init(&printer);

    gfxRef = POLY_OPA_DISP;
    gfx = Gfx_Open(gfxRef);
    gSPDisplayList(OVERLAY_DISP++, gfx);

    GfxPrint_Open(&printer, gfx);

    GfxPrint_SetColor(&printer, 255, 255, 255, 255);

    GfxPrint_SetPos(&printer, 1, 7);
    GfxPrint_Printf(&printer, "scenes : %d/113", COUNT_BITS(gSaveContext.save.vistied_scenes));

    GfxPrint_SetPos(&printer, 1, 8);
    GfxPrint_Printf(&printer, "actors : %d/670", COUNT_BITS(gSaveContext.save.loaded_actors));

    GfxPrint_SetPos(&printer, 1, 9);
    GfxPrint_Printf(&printer, "effects: %d/38", COUNT_BITS(gSaveContext.save.loaded_effects));


    gfx = GfxPrint_Close(&printer);

    gSPEndDisplayList(gfx++);
    Gfx_Close(gfxRef, gfx);
    POLY_OPA_DISP = gfx;

    GfxPrint_Destroy(&printer);

    CLOSE_DISPS(gamestate->gfxCtx);
}

