#include "z_en_encount4.h"

#define FLAGS 0x08000010

#define THIS ((EnEncount4*)thisx)

void EnEncount4_Init(Actor* thisx, GlobalContext* globalCtx);
void EnEncount4_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnEncount4_Update(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit En_Encount4_InitVars = {
    ACTOR_EN_ENCOUNT4,
    ACTORTYPE_PROP,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(EnEncount4),
    (ActorFunc)EnEncount4_Init,
    (ActorFunc)EnEncount4_Destroy,
    (ActorFunc)EnEncount4_Update,
    (ActorFunc)NULL
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_En_Encount4_0x809C3F30/EnEncount4_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Encount4_0x809C3F30/EnEncount4_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Encount4_0x809C3F30/func_809C3FD8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Encount4_0x809C3F30/func_809C4078.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Encount4_0x809C3F30/func_809C42A8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Encount4_0x809C3F30/func_809C4598.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Encount4_0x809C3F30/func_809C464C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Encount4_0x809C3F30/EnEncount4_Update.asm")
