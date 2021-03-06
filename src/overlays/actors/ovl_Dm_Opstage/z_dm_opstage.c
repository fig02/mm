#include "z_dm_opstage.h"

#define FLAGS 0x00000030

#define THIS ((DmOpstage*)thisx)

void DmOpstage_Init(Actor* thisx, GlobalContext* globalCtx);
void DmOpstage_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DmOpstage_Update(Actor* thisx, GlobalContext* globalCtx);
void DmOpstage_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit Dm_Opstage_InitVars = {
    ACTOR_DM_OPSTAGE,
    ACTORTYPE_ITEMACTION,
    FLAGS,
    OBJECT_KEIKOKU_DEMO,
    sizeof(DmOpstage),
    (ActorFunc)DmOpstage_Init,
    (ActorFunc)DmOpstage_Destroy,
    (ActorFunc)DmOpstage_Update,
    (ActorFunc)DmOpstage_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_Dm_Opstage_0x80A9F950/func_80A9F950.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Dm_Opstage_0x80A9F950/DmOpstage_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Dm_Opstage_0x80A9F950/DmOpstage_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Dm_Opstage_0x80A9F950/func_80A9FA58.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Dm_Opstage_0x80A9F950/DmOpstage_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Dm_Opstage_0x80A9F950/DmOpstage_Draw.asm")
