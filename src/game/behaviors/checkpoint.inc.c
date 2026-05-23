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
}
void bhv_checkpoint(void){
    obj_set_hitbox(o, &sCheckpointHitbox);
    f32 dist;
    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        if(o->oCheckpointPlaySound == 0){
            cur_obj_play_sound_2(SOUND_GENERAL2_RIGHT_ANSWER);
        }
        o->oCheckpointPlaySound = 1;
        o->oCheckpointSpinSpeed = 3000.0;
        cur_obj_find_nearest_object_with_behavior(bhvAirborneWarp, &dist)->oPosX = o->oPosX;
        cur_obj_find_nearest_object_with_behavior(bhvAirborneWarp, &dist)->oPosY = o->oPosY;
        cur_obj_find_nearest_object_with_behavior(bhvAirborneWarp, &dist)->oPosZ = o->oPosZ;
        gMarioState->healCounter += 4;
    }
    else{
        o->oCheckpointPlaySound = 0;
    }
    if(o->oCheckpointSpinSpeed > 500.0){
        o->oCheckpointSpinSpeed -= 50.0;
    }
    o->oFaceAngleYaw += o->oCheckpointSpinSpeed;
}