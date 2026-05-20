void bhv_king_whomp_star_loop(void){
    f32 dist;
    if(cur_obj_find_nearest_object_with_behavior(bhvWhompKingBoss, &dist) == NULL){
        spawn_default_star(o->oPosX, o->oPosY, o->oPosZ);
        obj_mark_for_deletion(o);
    }
}