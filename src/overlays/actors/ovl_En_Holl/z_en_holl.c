#include "z_en_holl.h"

#define FLAGS 0x00000010

#define THIS ((EnHoll*)thisx)

void EnHoll_Init(Actor* thisx, GlobalContext* globalCtx);
void EnHoll_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnHoll_Update(Actor* thisx, GlobalContext* globalCtx);
void EnHoll_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit En_Holl_InitVars = {
    ACTOR_EN_HOLL,
    ACTORTYPE_DOOR,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(EnHoll),
    (ActorFunc)EnHoll_Init,
    (ActorFunc)EnHoll_Destroy,
    (ActorFunc)EnHoll_Update,
    (ActorFunc)EnHoll_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/func_80899960.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/func_808999B0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/EnHoll_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/EnHoll_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/func_80899ACC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/func_80899B88.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/func_80899F30.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/func_8089A0C0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/func_8089A238.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/func_8089A330.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/EnHoll_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Holl_0x80899960/EnHoll_Draw.asm")
