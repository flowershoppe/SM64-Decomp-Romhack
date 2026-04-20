void bhv_rotate(void){
    s16 speed = GET_BPARAM1(o->oBehParams);
    o->oFaceAngleYaw -= (speed * 100.0f);
}