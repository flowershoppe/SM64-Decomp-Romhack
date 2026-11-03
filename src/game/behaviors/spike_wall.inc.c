void spike_wall_init(void){
    o->oMinSpeed = GET_BPARAM1(o->oBehParams);
    o->oMaxSpeed = GET_BPARAM2(o->oBehParams);
    o->oDirection = GET_BPARAM3(o->oBehParams);
    if(o->oDirection == 0){
        o->oForwardVel = o->oMinSpeed;
    }
    else{
        o->oVelY = o->oMinSpeed;
    }
}

void spike_wall_actions(void){
    u8 shouldStart = FALSE;
    if(o->oDirection == 0 && ABS(gMarioState->pos[1] - o->oPosY) < 750){
        shouldStart = TRUE;
    }
    if(o->oDirection != 0 && ABS(gMarioState->pos[0] - o->oPosX) < 750){
        shouldStart = TRUE;
    }
    if(o->oDistanceToMario < 4000 && shouldStart && o->oAction != 1){
        o->oAction = 1;
        cur_obj_play_sound_1(SOUND_OBJ_POUNDING_CANNON);
        o->oForwardVel = o->oMinSpeed;
        o->oVelY = o->oMinSpeed;
    }
    if(o->oAction == 1){
        bhv_spike_wall_loop();
    }
}
void bhv_spike_wall_loop(void){
    //use params for direction
    if(o->oDirection == 0){
        cur_obj_move_xz_using_fvel_and_yaw();
    }
    else{
        o->oPosY += o->oVelY;
    }

    //speed up
    if(o->oDistanceToMario > 1000){
        if(o->oForwardVel < o->oMaxSpeed){
            o->oForwardVel += 0.25;
            o->oVelY += 0.25;
        }
    }
    //slow down
    else{
        if(o->oDistanceToMario < 1000){
            if(o->oForwardVel > o->oMinSpeed){
                o->oForwardVel -= 0.25;
                o->oVelY -= 0.25;
            }
        }
    }

    //return home when mario dies or is 'behind' the wall
    if(gMarioState->health < 0x100 
        || (o->oDirection == 0 && gMarioState->pos[0] < o->oPosX - 100)
        || (o->oDirection != 0 && gMarioState->pos[1] < o->oPosY - 100)){
        vec3f_copy(&o->oPosVec, &o->oHomeVec);
        o->oAction = 0;
    }
}