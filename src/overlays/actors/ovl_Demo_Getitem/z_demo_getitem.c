#include "z_demo_getitem.h"

#define FLAGS 0x00000030

#define THIS ((DemoGetitem*)thisx)

void DemoGetitem_Init(Actor* thisx, GlobalContext* globalCtx);
void DemoGetitem_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DemoGetitem_Update(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit Demo_Getitem_InitVars = {
    ACTOR_DEMO_GETITEM,
    ACTORTYPE_BG,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(DemoGetitem),
    (ActorFunc)DemoGetitem_Init,
    (ActorFunc)DemoGetitem_Destroy,
    (ActorFunc)DemoGetitem_Update,
    (ActorFunc)NULL
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_Demo_Getitem_0x80A4FA40/DemoGetitem_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Demo_Getitem_0x80A4FA40/DemoGetitem_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Demo_Getitem_0x80A4FA40/func_80A4FB10.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Demo_Getitem_0x80A4FA40/func_80A4FB68.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Demo_Getitem_0x80A4FA40/DemoGetitem_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Demo_Getitem_0x80A4FA40/func_80A4FCF0.asm")
