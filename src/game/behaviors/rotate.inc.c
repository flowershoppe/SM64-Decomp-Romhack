void bhv_rotate(void){
    s16 speed = GET_BPARAM1(o->oBehParams);
    switch(GET_BPARAM2(o->oBehParams)){
        case 0:
            o->oFaceAngleYaw -= (speed * 50.0f);
        break;
        case 1:
            o->oFaceAnglePitch -= (speed * 50.0f);
        break;
        case 2:
            o->oFaceAngleRoll -= (speed * 50.0f);
        break;
    }
}