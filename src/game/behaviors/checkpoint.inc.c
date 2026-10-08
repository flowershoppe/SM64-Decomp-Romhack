struct ObjectHitbox sCheckpointHitbox = {
    /* interactType:      */ 0,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 100,
};

void bhv_checkpoint_init(void){
    o->oCheckpointSpinSpeed = 500.0;
    o->oFace = o->oFaceAngleYaw;
}
void bhv_checkpoint(void){
    obj_set_hitbox(o, &sCheckpointHitbox);
    f32 dist;
    if (obj_check_if_collided_with_object(o, gMarioObject) && o->oCheckpointPlaySound == 0) {
        o->oCheckpointPlaySound = 1;
        cur_obj_play_sound_2(SOUND_GENERAL2_RIGHT_ANSWER);
        o->oCheckpointSpinSpeed = 3000.0;
        cur_obj_find_nearest_object_with_behavior(bhvAirborneWarp, &dist)->oPosX = o->oPosX;
        cur_obj_find_nearest_object_with_behavior(bhvAirborneWarp, &dist)->oPosY = o->oPosY;
        cur_obj_find_nearest_object_with_behavior(bhvAirborneWarp, &dist)->oPosZ = o->oPosZ;
        cur_obj_find_nearest_object_with_behavior(bhvAirborneWarp, &dist)->oFaceAngleYaw = o->oFace;
        gMarioState->healCounter += 4;

        s32 fileIndex = gCurrSaveFileNum - 1;
        s32 courseIndex = COURSE_NUM_TO_INDEX(gCurrCourseNum);
        save_file_set_last_location();
        save_file_save_coins();
        save_file_do_save(gCurrSaveFileNum - 1);
    }
    else if(!obj_check_if_collided_with_object(o, gMarioObject)){
        o->oCheckpointPlaySound = 0;
    }
    if(o->oCheckpointSpinSpeed > 500.0){
        o->oCheckpointSpinSpeed -= 50.0;
    }
    o->oFaceAngleYaw += o->oCheckpointSpinSpeed;
}