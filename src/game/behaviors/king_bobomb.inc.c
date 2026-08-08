// king_bobomb.inc.c

// Copy of geo_update_projectile_pos_from_parent
Gfx *geo_update_held_mario_pos(s32 callContext, UNUSED struct GraphNode *node, Mat4 mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        if (obj->prevObj != NULL) {
            obj_update_pos_from_parent_transformation(mtx, obj->prevObj);
            obj_set_gfx_pos_from_pos(obj->prevObj);
        }
    }

    return NULL;
}

s32 mario_is_far_below_object(f32 min) {
    return min < o->oPosY - gMarioObject->oPosY;
}

void bhv_bobomb_anchor_mario_loop(void) {
    common_anchor_mario_behavior(50.0f, 50.0f, INT_STATUS_MARIO_DROPPED_BY_OBJ);
}

void king_bobomb_act_inactive(void) { // act 0
    o->oHealth = 3;
    u8 starId = GET_BPARAM1(o->oBehParams);
    u8 currentLevelStarFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(gCurrCourseNum));
    if (currentLevelStarFlags & (1 << starId)) {
        obj_mark_for_deletion(o);
    } else {
    }
    o->oForwardVel = 0.0f;
    o->oVelY = 0.0f;

    if (o->oSubAction == KING_BOBOMB_SUB_ACT_INACTIVE_INIT) {
        cur_obj_become_intangible();
        gSecondCameraFocus = o;
        cur_obj_init_animation_with_sound(KING_BOBOMB_ANIM_IDLE);
        cur_obj_set_pos_to_home();
        o->oHealth = 3;

        if (o->oDistanceToMario < 4500.0f) {
            o->oSubAction++;
            seq_player_lower_volume(SEQ_PLAYER_LEVEL, 60, 40);
        }
    } else if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
        DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_024)) {
        o->oAction = KING_BOBOMB_ACT_ACTIVATE;
        o->oFlags |= OBJ_FLAG_HOLDABLE;
    }
}

void king_bobomb_act_active(void) { // act 2
    cur_obj_become_tangible();
    if(o->oDistanceToMario < 800.0f){
        //MARIO NEAR
        o->oForwardVel = 2.0f;
        cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_WALKING);
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x100);
    }
    else if(o->oDistanceToMario < 4000.0f){
        if(mario_is_far_below_object(700.0f)){
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
        }
        //THROW BOMBS 
        o->oForwardVel = 0.0f;
       cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_THROW_MARIO);
       if(cur_obj_check_anim_frame(27))
       {
            switch(o->oHealth){
                case 3:
                    spawn_object_relative(0, 0, 300, 0, o, MODEL_BOMBOOM_BOMB, bhvBomboomBomb);
                break;
                case 2:
                    spawn_object_relative(0, 100, 300, 0, o, MODEL_BOMBOOM_BOMB, bhvBomboomBomb);
                    spawn_object_relative(0, -100, 300, 0, o, MODEL_BOMBOOM_BOMB, bhvBomboomBomb);
                break;
                case 1:
                    spawn_object_relative(0, 100, 300, 0, o, MODEL_BOMBOOM_BOMB, bhvBomboomBomb);
                    spawn_object_relative(0, -100, 300, 0, o, MODEL_BOMBOOM_BOMB, bhvBomboomBomb);
                    spawn_object_relative(0, 200, 300, 0, o, MODEL_BOMBOOM_BOMB, bhvBomboomBomb);
                break;
            }
       }
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x1000);
    }
    else{
        //TOO FAR AWAY, IDLE
       cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_IDLE);
    }
    /*if (o->oPosY - o->oHomeY < -1000.0f) { // Thrown off hill
        o->oAction = KING_BOBOMB_ACT_RETURN_HOME;
        cur_obj_become_intangible();
    }*/
    if (cur_obj_check_grabbed_mario()) {
        o->oAction = KING_BOBOMB_ACT_GRABBED_MARIO;
    }
    //STOMP
    /*
    if (o->oKingBobombShouldStomp == 0) {
        if (cur_obj_check_anim_frame(15)) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
        }

        if (cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_STOMP)) {
            o->oKingBobombShouldStomp++;
        }
    }   else {
            if (o->oKingBobombShouldStomp == 1) {
                cur_obj_init_animation_and_anim_frame(KING_BOBOMB_ANIM_WALKING, 7);
                o->oKingBobombShouldStomp = 2;
            }
        }*/
}

void king_bobomb_act_grabbed_mario(void) { // act 3
    if (o->oSubAction == KING_BOBOMB_SUB_ACT_GRABBED_MARIO_GRAB) {
        o->oForwardVel = 0.0f;
        o->oKingBobombStationaryTimer = 0;
        o->oKingBobombPlayerGrabEscapeActions = 0;

        if (o->oTimer == 0) {
            cur_obj_play_sound_2(SOUND_OBJ_GRAB_MARIO);
        }

        if (cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_GRAB_MARIO)) {
            o->oSubAction++;
            cur_obj_init_animation_and_anim_frame(KING_BOBOMB_ANIM_HOLDING_MARIO, 0);
        }
    } else if (o->oSubAction == KING_BOBOMB_SUB_ACT_GRABBED_MARIO_HOLDING) {
        cur_obj_init_animation_with_sound(KING_BOBOMB_ANIM_HOLDING_MARIO);
        o->oKingBobombPlayerGrabEscapeActions += player_performed_grab_escape_action();

        print_debug_bottom_up("%d", o->oKingBobombPlayerGrabEscapeActions);

        if (o->oKingBobombPlayerGrabEscapeActions > 10) {
            o->oKingBobombHoldingMarioState = HELD_DROPPED;
            if(mario_is_far_below_object(500.0f)){
                o->oAction = KING_BOBOMB_ACT_ACTIVE;
            }
            else{
                o->oAction = KING_BOBOMB_ACT_CHASE_MARIO;
            }
            o->oKingBobombPlayerGrabEscapeCooldown = 35;
            o->oInteractStatus &= ~(INT_STATUS_GRABBED_MARIO);
        } else {
            o->oForwardVel = 3.0f;

            if (o->oKingBobombStationaryTimer > 20 && cur_obj_rotate_yaw_toward(0x0, 0x400)) {
                o->oSubAction++;
                cur_obj_init_animation_and_anim_frame(KING_BOBOMB_ANIM_THROW_MARIO, 22);
            }
        }

        o->oKingBobombStationaryTimer++;
    } else {
        cur_obj_init_animation_with_sound(KING_BOBOMB_ANIM_THROW_MARIO);

        if (cur_obj_check_anim_frame(31)) {
            o->oKingBobombHoldingMarioState = HELD_THROWN;
            cur_obj_play_sound_2(SOUND_OBJ_RELEASE_MARIO);
        } else if (cur_obj_check_if_near_animation_end()) {
            if(mario_is_far_below_object(500.0f)){
                o->oAction = KING_BOBOMB_ACT_ACTIVATE;
            }
            else{
                o->oAction = KING_BOBOMB_ACT_CHASE_MARIO;
            }
            o->oInteractStatus &= ~(INT_STATUS_GRABBED_MARIO);
        }
    }
}

void king_bobomb_act_activate(void) { // act 1
    o->oForwardVel = 0.0f;
    o->oVelY = 0.0f;
    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EVENT_BOSS), 0);
    seq_player_lower_volume(SEQ_PLAYER_LEVEL, 1, 40);
    cur_obj_init_animation_with_sound(KING_BOBOMB_ANIM_WALKING);

    o->oAction = KING_BOBOMB_ACT_ACTIVE;
}

void king_bobomb_act_hit_ground(void) { // act 6
    if (o->oSubAction == KING_BOBOMB_SUB_ACT_HIT_GROUND_HIT) {
        if (o->oTimer == 0) {
            o->oKingBobombStationaryTimer = 0;

            cur_obj_play_sound_2(SOUND_OBJ_BOWSER_WALK);
            cur_obj_play_sound_2(SOUND_OBJ2_KING_BOBOMB_DAMAGE);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            spawn_mist_particles_variable(0, 0, 100.0f);

            o->oInteractType = INTERACT_DAMAGE;

            cur_obj_become_tangible();
        }

        if (cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_HIT_GROUND)) {
            o->oKingBobombStationaryTimer++;
        }

        if (o->oKingBobombStationaryTimer > 3) {
            o->oSubAction++; // KING_BOBOMB_SUB_ACT_HIT_GROUND_STAND_UP
        }
    } else if (o->oSubAction == KING_BOBOMB_SUB_ACT_HIT_GROUND_STAND_UP) {
        if (cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_STAND_UP)) {
            o->oSubAction = 0;
            o->oInteractType = INTERACT_GRABBABLE;
            if(o->oHealth > 0){
                o->oAction = KING_BOBOMB_ACT_RETURN_HOME;
            }
            cur_obj_become_intangible();
        }
    } else {
        cur_obj_init_animation_with_sound(KING_BOBOMB_ANIM_WALKING);

        if (cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x800)) {
            o->oAction = KING_BOBOMB_ACT_ACTIVE;
        }
    }
}

void king_bobomb_act_death(void) { // act 7
    cur_obj_init_animation_with_sound(KING_BOBOMB_ANIM_HIT_GROUND);
    if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
        DIALOG_FLAG_TEXT_DEFAULT, CUTSCENE_DIALOG, o->oKingBobombDialog)) {
        create_sound_spawner(SOUND_OBJ_KING_WHOMP_DEATH);

        cur_obj_hide();
        cur_obj_become_intangible();

        spawn_mist_particles_variable(0, 0, 200.0f);
        spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
        cur_obj_shake_screen(SHAKE_POS_SMALL);

        spawn_default_star(o->oHomeX, o->oHomeY + 300.0f, o->oHomeZ);

        stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_BOSS));
        obj_mark_for_deletion(o);
    }
}

void king_bobomb_act_stop_music(void) { // act 8
    if (o->oTimer == 60) {
        stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_BOSS));
    }
}

void king_bobomb_act_been_thrown(void) { // act 4
    if (o->oHomeY - o->oPosY > 500.0f) { // not thrown off hill
        if (o->oMoveFlags & OBJ_MOVE_LANDED) {
            o->oHealth--;
            switch(o->oHealth){
                case 2:
                    o->oKingBobombDialog = DIALOG_026;
                    break;
                case 1:
                    o->oKingBobombDialog = DIALOG_027;
                    break;
                case 0:
                    o->oKingBobombDialog = DIALOG_028;
                    break;
            }
            o->oForwardVel = 0.0f;
            o->oVelY = 0.0f;

            cur_obj_play_sound_2(SOUND_OBJ_BOWSER_WALK);

            o->oAction = o->oHealth ? KING_BOBOMB_ACT_HIT_GROUND : KING_BOBOMB_ACT_DEATH;
        }
    } else if (o->oSubAction == KING_BOBOMB_SUB_ACT_THROWN_FALL) {
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
            o->oForwardVel = 0.0f;
            o->oVelY = 0.0f;

            o->oSubAction++; // KING_BOBOMB_SUB_ACT_THROWN_STAND_UP
        } else if (o->oMoveFlags & OBJ_MOVE_LANDED) {
            cur_obj_play_sound_2(SOUND_ACTION_BOUNCE_OFF_OBJECT);
        }
    } else {
        if (cur_obj_init_animation_and_check_if_near_end(10)) {
            //NOT FAR ENOUGH
            if (o->oHomeY - o->oPosY < 100.0f){
                o->oKingBobombDialog = DIALOG_025;                
            }
            o->oAction = KING_BOBOMB_ACT_RETURN_HOME; // Go back to top of hill
        }

        o->oSubAction++; // KING_BOBOMB_SUB_ACT_THROWN_END
    }
}

void king_bobomb_act_return_home(void) { // act 5
    switch (o->oSubAction) {
        case KING_BOBOMB_SUB_ACT_RETURN_HOME_JUMP:
            if (o->oTimer == 0) {
                cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
            }

            o->oKingBobombIsJumping = TRUE;

            cur_obj_init_animation_and_extend_if_at_end(KING_BOBOMB_ANIM_JUMP);
            o->oMoveAngleYaw = cur_obj_angle_to_home();

            if (o->oPosY < o->oHomeY) {
                o->oVelY = 100.0f;
            } else {
                arc_to_goal_pos(&o->oHomeX, &o->oPosVec, 100.0f, -4.0f);
                o->oSubAction++; // KING_BOBOMB_SUB_ACT_RETURN_HOME_LANDING
            }
            break;

        case KING_BOBOMB_SUB_ACT_RETURN_HOME_LANDING:
            cur_obj_init_animation_and_extend_if_at_end(KING_BOBOMB_ANIM_JUMP);

            if (o->oVelY < 0 && o->oPosY < o->oHomeY) {
                o->oPosY = o->oHomeY;
                o->oVelY = 0;
                o->oForwardVel = 0;
                o->oGravity = -4.0f;

                o->oKingBobombIsJumping = FALSE;

                cur_obj_init_animation_with_sound(KING_BOBOMB_ANIM_T_POSE);
                cur_obj_play_sound_2(SOUND_OBJ_BOWSER_WALK);
                cur_obj_shake_screen(SHAKE_POS_SMALL);

                o->oSubAction++; // KING_BOBOMB_SUB_ACT_RETURN_HOME_LANDING_END
            }
            break;

        case KING_BOBOMB_SUB_ACT_RETURN_HOME_LANDING_END:
            if (cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_T_POSE)) {
                o->oSubAction++; // KING_BOBOMB_SUB_ACT_RETURN_HOME_WAIT_FOR_DIALOG
            }
            break;

        case KING_BOBOMB_SUB_ACT_RETURN_HOME_WAIT_FOR_DIALOG:
            if (o->oDistanceToMario > 5000.0f) {
                o->oAction = KING_BOBOMB_ACT_INACTIVE;
                stop_background_music(SEQUENCE_ARGS(4, SEQ_EVENT_BOSS));
            }
            
            else {
                o->oSubAction++; // KING_BOBOMB_SUB_ACT_RETURN_HOME_DIALOG
            }
            break;

        case KING_BOBOMB_SUB_ACT_RETURN_HOME_DIALOG:
            if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
                DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, o->oKingBobombDialog)) {
                if(o->oKingBobombDialog == DIALOG_025){
                    o->oAction = KING_BOBOMB_ACT_ACTIVE;                    
                }
                else{
                    o->oAction = KING_BOBOMB_ACT_CHASE_MARIO;
                }
                cur_obj_become_tangible();
            }
            break;
    }
}

void king_bobomb_act_chase_mario(void){ // act 9
    cur_obj_become_tangible();
    if (cur_obj_check_grabbed_mario()) {
        o->oAction = KING_BOBOMB_ACT_GRABBED_MARIO;
    }
    if(mario_is_far_below_object(500.0f)){    
        o->oAction = KING_BOBOMB_ACT_ACTIVE;
    }
    else{
        cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x900);
        cur_obj_init_animation_and_check_if_near_end(KING_BOBOMB_ANIM_WALKING);
        o->oForwardVel = 20.0f;
    }
}

ObjActionFunc sKingBobombActions[] = {
    king_bobomb_act_inactive,
    king_bobomb_act_activate,
    king_bobomb_act_active,
    king_bobomb_act_grabbed_mario,
    king_bobomb_act_been_thrown,
    king_bobomb_act_return_home,
    king_bobomb_act_hit_ground,
    king_bobomb_act_death,
    king_bobomb_act_stop_music,
    king_bobomb_act_chase_mario
};

struct SoundState sKingBobombSoundStates[] = {
    { 0, 0, 0, NO_SOUND },
    { 1, 1, 20, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 1, 15, -1, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 0, 0, 0, NO_SOUND },
    { 1, 33, -1, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO },
    { 0, 0, 0, NO_SOUND },
    { 1, 1, 15, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO },
};

void king_bobomb_move(void) {
    cur_obj_update_floor_and_walls();

    if (!o->oKingBobombIsJumping) {
        cur_obj_move_standard(-78);
    } else {
        cur_obj_move_using_fvel_and_gravity();
    }

    cur_obj_call_action_function(sKingBobombActions);
    exec_anim_sound_state(sKingBobombSoundStates);

    if (o->oDistanceToMario < 5000.0f) { //! oDrawingDistance?
        cur_obj_enable_rendering();
    } else {
        cur_obj_disable_rendering();
    }
}

void bhv_king_bobomb_loop(void) {
    o->oInteractionSubtype |= INT_SUBTYPE_GRABS_MARIO;

    switch (o->oHeldState) {
        case HELD_FREE:
            king_bobomb_move();
            break;
        case HELD_HELD:
            cur_obj_unrender_set_action_and_anim(6, 1);
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            cur_obj_get_thrown_or_placed(20.0f, 50.0f, 4);
            cur_obj_become_intangible();
            o->oPosY += 20.0f;
            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;
    curr_obj_random_blink(&o->oKingBobombBlinkTimer);
}
