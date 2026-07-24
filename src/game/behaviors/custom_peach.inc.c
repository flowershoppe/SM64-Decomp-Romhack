void peach_act_idle(void){
    if (o->oDistanceToMario < 500.0f) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
        if(ABS(o->oFaceAngleYaw - o->oAngleToMario) > 5){
            cur_obj_init_animation(CUSTOM_PEACH_ANIM_WALKING);
        }
        else{
            cur_obj_init_animation(CUSTOM_PEACH_ANIM_LOOK_DOWN); 
        }
    }
    else{
        cur_obj_init_animation(CUSTOM_PEACH_ANIM_IDLE);
    }
    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oAction = PEACH_TURN_TO_TALK;
    }
}

void peach_act_turn_to_talk(void){
    cur_obj_init_animation(CUSTOM_PEACH_ANIM_WALKING);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);

    if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
        o->oAction = PEACH_TALK;
        cur_obj_play_sound_2(SOUND_PEACH_MARIO);
    }    
}

void peach_act_talk(void){
    cur_obj_init_animation(CUSTOM_PEACH_ANIM_TALKING);
    if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_SPEAK) {
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o->oBehParams2ndByte)) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);

            o->oInteractStatus = INT_STATUS_NONE;
            o->oAction = PEACH_IDLE;
            cur_obj_init_animation(CUSTOM_PEACH_ANIM_IDLE);
        }
    }
}

void peach_actions(void){
    switch (o->oAction) {
        case PEACH_IDLE:
            peach_act_idle();
            break;

        case PEACH_TURN_TO_TALK:
            peach_act_turn_to_talk();
            break;

        case PEACH_TALK:
            peach_act_talk();
            break;
    }
}

void bhv_custom_peach_loop(void){    
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
    peach_actions();

    //curr_obj_random_blink(&o->oBobombBuddyBlinkTimer);

    o->oInteractStatus = INT_STATUS_NONE;
}
