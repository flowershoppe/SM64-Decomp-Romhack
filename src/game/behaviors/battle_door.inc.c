void bhv_battle_door_loop(void) {
    if(cur_obj_nearest_object_with_behavior(bhvGoomba) ||
        cur_obj_nearest_object_with_behavior(bhvThwomp) ||
        cur_obj_nearest_object_with_behavior(bhvKingBobomb) ||
        cur_obj_nearest_object_with_behavior(bhvBoo) ||
        cur_obj_nearest_object_with_behavior(bhvBobomb) ||
        cur_obj_nearest_object_with_behavior(bhvSpindrift) ||
        cur_obj_nearest_object_with_behavior(bhvChuckya) ||
        cur_obj_nearest_object_with_behavior(bhvScuttlebug) ||
        cur_obj_nearest_object_with_behavior(bhvSmallBully) ||
        cur_obj_nearest_object_with_behavior(bhvBigBully))
        {}
else{
        obj_mark_for_deletion(o);
        play_sound(SOUND_GENERAL_WALL_EXPLOSION, gGlobalSoundSource);
        spawn_mist_particles_variable(0, 0, 100.0f);
        spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
        cur_obj_shake_screen(SHAKE_POS_SMALL);
    }

}
