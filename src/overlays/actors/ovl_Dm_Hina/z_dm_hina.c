/*
 * File: z_dm_hina.c
 * Overlay: ovl_Dm_Hina
 * Description: Boss mask cutscene objects
 */

#include "z_dm_hina.h"
#include "objects/gameplay_keep/gameplay_keep.h"


#define FLAGS (ACTOR_FLAG_10 | ACTOR_FLAG_20)

#define THIS ((DmHina*)thisx)

void DmHina_Init(Actor* thisx, GlobalContext* globalCtx);
void DmHina_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DmHina_Update(Actor* thisx, GlobalContext* globalCtx);
void DmHina_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A1F470(DmHina* this, GlobalContext* globalCtx);
void func_80A1F56C(DmHina* this, GlobalContext* globalCtx);
void func_80A1F5AC(DmHina* this, GlobalContext* globalCtx);
void func_80A1F63C(DmHina* this, GlobalContext* globalCtx);

const ActorInit Dm_Hina_InitVars = {
    ACTOR_DM_HINA,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_BSMASK,
    sizeof(DmHina),
    (ActorFunc)DmHina_Init,
    (ActorFunc)DmHina_Destroy,
    (ActorFunc)DmHina_Update,
    (ActorFunc)DmHina_Draw,
};

void DmHina_Init(Actor* thisx, GlobalContext* globalCtx) {
    DmHina* this = THIS;

    this->isVisible = true;
    this->unk148 = 0.0f;
    this->unk_15C = 1.0f;
    this->actionFunc = func_80A1F470;

    this->actor.focus.pos.x = this->actor.world.pos.x;
    this->actor.focus.pos.y = this->blueWarpPosY = this->actor.world.pos.y;
    this->actor.focus.pos.z = this->actor.world.pos.z;
}

void DmHina_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_80A1F470(DmHina* this, GlobalContext* globalCtx) {
    Player* player = GET_PLAYER(globalCtx);

    Math_SmoothStepToF(&this->unk148, 0.6f, 0.5f, 0.05f, 0.001f);
    this->unk154 = Math_SinS(globalCtx->gameplayFrames * 0x708) * 8.0f;

    if ((player->stateFlags1 & 0x400) && (this->actor.xzDistToPlayer < 80.0f)) {
        this->isVisible = false;
        this->unk154 = 0.0f;
        this->actor.world.pos.y += 40.0f;
        this->actionFunc = func_80A1F56C;
    }
}

void func_80A1F56C(DmHina* this, GlobalContext* globalCtx) {
    if (Message_GetState(&globalCtx->msgCtx) == 2) {
        this->timer = 2;
        this->actionFunc = func_80A1F5AC;
    }
}

void func_80A1F5AC(DmHina* this, GlobalContext* globalCtx) {
    this->timer--;

    if (this->timer == 0) {
        this->isVisible = true;
        Cutscene_Start(globalCtx, &globalCtx->csCtx);
        this->csCamId = Play_CreateSubCamera(globalCtx);
        Play_CameraChangeStatus(globalCtx, CAM_ID_MAIN, 1);
        Play_CameraChangeStatus(globalCtx, this->csCamId, 7);
        this->actionFunc = func_80A1F63C;
    }
}

void func_80A1F63C(DmHina* this, GlobalContext* globalCtx) {
    this->csCamEye.x = this->actor.world.pos.x + 100.0f;
    this->csCamEye.y = this->blueWarpPosY + 260.0f;
    this->csCamEye.z = this->actor.world.pos.z + 100.0f;

    this->csCamAt.x = this->actor.world.pos.x;
    this->csCamAt.z = this->actor.world.pos.z;

    this->csCamAt.y = this->actor.world.pos.y + (this->unk154 * this->unk_15C) + (40.0f * this->unk_15C);

    Play_CameraSetAtEye(globalCtx, this->csCamId, &this->csCamAt, &this->csCamEye);
    Math_SmoothStepToF(&this->actor.world.pos.y, this->blueWarpPosY + 300.0f, 0.5f, 2.0f, 0.1f);

    if (((this->blueWarpPosY + 240.0f) < this->actor.world.pos.y) && (this->csState != 1)) {
        this->csState = 1;
        Actor_PlaySfxAtPos(&this->actor, NA_SE_OC_WHITE_OUT_INTO_KYOJIN);
    }

    Actor_PlaySfxAtPos(&this->actor, NA_SE_EV_MASK_RISING - SFX_FLAG);
}

void func_80A1F75C(DmHina* this, GlobalContext* globalCtx) {
    s32 i;
    s16 light1Color;

    switch (this->csState) {
        case 0:
            this->lightOrbAlpha = 0;
            this->scale = 0.0f;
            break;

        case 1:
            Math_SmoothStepToF(&this->scale, 1.0f, 0.4f, 0.05f, 0.001f);
            this->lightOrbAlpha = this->scale * 255.0f;

            this->unk150 = Math_SinS(globalCtx->state.frames * 0x1F40);
            
            for (i = 0; i < 3; i++) {
                light1Color = this->scale * -255.0f;
                globalCtx->envCtx.lightSettings.diffuseColor1[i] = light1Color;
                globalCtx->envCtx.lightSettings.fogColor[i] = light1Color;
                globalCtx->envCtx.lightSettings.ambientColor[i] = light1Color;
            }

            globalCtx->envCtx.lightSettings.fogNear = this->scale * -500.0f;

            if (globalCtx->envCtx.lightSettings.fogNear < -0x12C) {
                globalCtx->roomCtx.currRoom.segment = 0;
            }

            break;
    }
}

void DmHina_Update(Actor* thisx, GlobalContext* globalCtx) {
    DmHina* this = THIS;

    this->actionFunc(this, globalCtx);
    func_80A1F75C(this, globalCtx);
}


void func_80A1F9AC(DmHina* this, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    if (this->csState != 0) {
        f32 scale; 

        OPEN_DISPS(gfxCtx);

        func_8012C2DC(globalCtx->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, ((u8)(this->scale * 100.0f) + 155), this->lightOrbAlpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, ((u8)(this->unk150 * 100.0f) + 50), 0);
        gSPDisplayList(POLY_XLU_DISP++, gLightOrb1DL);

        Matrix_InsertTranslation(this->actor.world.pos.x, this->actor.world.pos.y + (this->unk154 * this->unk_15C) + (40.0f * this->unk_15C), this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_NormalizeXYZ(&globalCtx->billboardMtxF);
        scale = this->scale * 20.0f;
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        Matrix_InsertZRotation_f(Rand_ZeroFloat(6.2831855f), MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, gLightOrbVtxDL);
        
        CLOSE_DISPS(gfxCtx);
    }

}

void DmHina_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DmHina* this = THIS;
    f32 scale;

    if (this->isVisible) {
        Matrix_InsertTranslation(this->actor.world.pos.x, this->actor.world.pos.y + (this->unk154 * this->unk_15C) + (40.0f * this->unk_15C), this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_InsertRotation(0, globalCtx->gameplayFrames * 0x3E8, 0, MTXMODE_APPLY);
        scale = this->unk148 * (1.0f - this->scale) * this->unk_15C;
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);

        switch (this->actor.params) {
            case 0:
                GetItem_Draw(globalCtx, GID_REMAINS_ODOWLA);
                break;

            case 1:
                GetItem_Draw(globalCtx, GID_REMAINS_GOHT);
                break;

            case 2:
                GetItem_Draw(globalCtx, GID_REMAINS_GYORG);
                break;

            case 3:
                GetItem_Draw(globalCtx, GID_REMAINS_TWINMOLD);
                break;
        }

        func_80A1F9AC(this, globalCtx);
    }
}
