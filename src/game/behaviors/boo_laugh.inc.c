void bhv_boo_laugh(void){
    f32 dist = GET_BPARAM1(o->oBehParams) * 10;
    if(o->oDistanceToMario < dist){
        if(o->oTimer > 60){
            play_sound(SOUND_OBJ_BOO_LAUGH_SHORT, gGlobalSoundSource);
        }
        o->oTimer = 0;
    }
}