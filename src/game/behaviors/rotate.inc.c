void bhv_rotate(void){
    s16 speed = GET_BPARAM1(o->oBehParams);
    o->oFaceAngleYaw -= (speed * 50.0f);
    o->oDrawingDistance = 2000.0f;
}