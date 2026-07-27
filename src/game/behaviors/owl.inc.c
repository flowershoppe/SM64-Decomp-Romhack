void owl_act_idle(void){
    if (o->oDistanceToMario < 500.0f) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
        if(ABS(o->oFaceAngleYaw - o->oAngleToMario) > 0x100){
            cur_obj_init_animation(OWL_ANIM_WALKING);
        }
        else{
            cur_obj_init_animation(OWL_ANIM_IDLE); 
        }
    }
    else{
        cur_obj_init_animation(OWL_ANIM_IDLE);
    }
    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oAction = OWL_TURN_TO_TALK;
    }
}

void owl_act_turn_to_talk(void){
    cur_obj_init_animation(OWL_ANIM_WALKING);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);

    if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
        o->oAction = OWL_TALK;
    }    
}

void owl_act_talk(void){
    cur_obj_init_animation(OWL_ANIM_TALKING);
    if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT) == MARIO_DIALOG_STATUS_SPEAK) {
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o->oBehParams2ndByte)) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);

            o->oInteractStatus = INT_STATUS_NONE;
            o->oAction = OWL_IDLE;
            cur_obj_init_animation(OWL_ANIM_IDLE);
            if(gCurrLevelNum == LEVEL_BOB){
                f32 dist;
                cur_obj_find_nearest_object_with_behavior(bhvWarp, &dist)->oPosX = o->oPosX;
                cur_obj_find_nearest_object_with_behavior(bhvWarp, &dist)->oPosY = o->oPosY;
                cur_obj_find_nearest_object_with_behavior(bhvWarp, &dist)->oPosZ = o->oPosZ;
            }
        }
    }
}

void owl_actions(void){
    switch (o->oAction) {
        case OWL_IDLE:
           owl_act_idle();
            break;

        case OWL_TURN_TO_TALK:
           owl_act_turn_to_talk();
            break;

        case OWL_TALK:
           owl_act_talk();
            break;
    }
}

void bhv_owl_loop(void){    
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
   owl_actions();

    //curr_obj_random_blink(&o->oBobombBuddyBlinkTimer);

    o->oInteractStatus = INT_STATUS_NONE;
}
