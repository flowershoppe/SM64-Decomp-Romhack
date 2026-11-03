void change_music_loop(void){
    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, GET_BPARAM1(o->oBehParams)));
    obj_mark_for_deletion(o);
}