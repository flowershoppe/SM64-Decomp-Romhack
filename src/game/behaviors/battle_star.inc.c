void bhv_battle_star_loop(u32 params){
    f32 dist;
    if(cur_obj_find_nearest_object_with_behavior(bhvBigBully, &dist) == NULL &&
        cur_obj_find_nearest_object_with_behavior(bhvSmallBully, &dist) == NULL){
        bhv_spawn_star_no_level_exit(params);
        obj_mark_for_deletion(o);
    }
}