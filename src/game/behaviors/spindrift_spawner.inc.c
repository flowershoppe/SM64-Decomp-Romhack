void bhv_spindrift_spawner_loop(void) {
    f32 dist;
    if(dist_between_objects(o, cur_obj_find_nearest_object_with_behavior(bhvSpindrift, &dist)) >= 1000){
        spawn_object(o, MODEL_SPINDRIFT, bhvSpindrift);
    }
}