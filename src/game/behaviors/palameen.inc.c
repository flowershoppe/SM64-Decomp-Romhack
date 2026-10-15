void palameen_idle(void){
    //invisible, waiting for mario
    u8 dialogid = GET_BPARAM1(o->oBehParams);
    u8 dist = GET_BPARAM2(o->oBehParams);
    cur_obj_hide();
    if(o->oDistanceToMario < (dist * 100) && (gMarioState->pos[1] < o->oPosY + 100)) {
        o->oAction = 1;
        cur_obj_unhide();
        spawn_object_relative(0, 0, -200, 0, o, MODEL_NONE, bhvStarKeyCollectionPuffSpawner);
        cur_obj_play_sound_1(SOUND_OBJ2_BOWSER_TELEPORT);
    }
}

void palameen_talking(void){
    u8 dialogid = GET_BPARAM1(o->oBehParams);
    u8 dist = GET_BPARAM2(o->oBehParams);

    //look at mario
    f32 xToMario = gMarioObject->header.gfx.pos[0] - o->oPosX;
    f32 yToMario = gMarioObject->header.gfx.pos[1] - o->oPosY;
    f32 zToMario = gMarioObject->header.gfx.pos[2] - o->oPosZ;
    s16 vAngleToMario = atan2s(sqrtf(xToMario * xToMario + zToMario * zToMario), -yToMario);
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, vAngleToMario, 0x1000);

    cur_obj_init_animation(0);

    //start dialog
    if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
    DIALOG_FLAG_TEXT_DEFAULT, CUTSCENE_DIALOG, dialogid)){
        spawn_object_relative(0, 0, -100, 0, o, MODEL_NONE, bhvStarKeyCollectionPuffSpawner);
        spawn_object(o, MODEL_SMOKE, bhvWhitePuffSmoke);
        cur_obj_play_sound_1(SOUND_OBJ2_BOWSER_TELEPORT);
        obj_mark_for_deletion(o);    
    }

}

void palameen_actions(void){
    switch (o->oAction) { 
        case 0:
            palameen_idle();
            break;
        case 1:
            palameen_talking();
            break;
    }
}

void bhv_palameen_loop(void){
    palameen_actions();
}