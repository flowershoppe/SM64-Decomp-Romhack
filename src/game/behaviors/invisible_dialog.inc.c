void bhv_invisible_dialog_loop(){
    u8 dialogid = GET_BPARAM1(o->oBehParams);
    u8 dist = GET_BPARAM2(o->oBehParams);
    if(o->oDistanceToMario < (dist * 100)){
        if(cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
        DIALOG_FLAG_TEXT_DEFAULT, CUTSCENE_DIALOG, dialogid)){
            obj_mark_for_deletion(o);
        }
    }
}