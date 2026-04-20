f32 fps = 60.0f;

void bhv_circle_loop(void) {
    u8 path = GET_BPARAM1(o->oBehParams);
    f32 radius = 100 * GET_BPARAM2(o->oBehParams);
    f32 loop_time = GET_BPARAM3(o->oBehParams) / 10.0f;

    loop_time = (loop_time >= 1) ? loop_time : 5.0f; // 5s

    f32 progress = o->oTimer * 2.0f * M_PI / loop_time / fps;

    switch (path){
    case 0:
        o->oPosX = o->oHomeX + radius * sinf(progress);
        break;
    case 1:
        o->oPosZ = o->oHomeZ + radius * sinf(progress);
        break;
    case 2:
        o->oPosY = o->oHomeY + radius * sinf(progress);
        break;
    case 3:
        o->oPosX = o->oHomeX + radius * sinf(progress);
        o->oPosZ = o->oHomeZ + radius * cosf(progress);
        break;
    case 4:
        o->oPosX = o->oHomeX + radius * sinf(progress);
        o->oPosY = o->oHomeY + radius * cosf(progress);
        break;
    case 5:
        o->oPosZ = o->oHomeZ + radius * sinf(progress);
        o->oPosY = o->oHomeY + radius * cosf(progress);
        break;
    }
    o->oTimer++;
}