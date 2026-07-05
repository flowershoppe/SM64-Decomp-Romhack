void bhv_star_gate_loop(void) {
    if (GET_BPARAM1(o->oBehParams) != NULL) {
        u8 requiredStars = GET_BPARAM1(o->oBehParams);
        s16 numStars = save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);
        if(numStars >= requiredStars && o->oDistanceToMario < 500.0f){
            obj_mark_for_deletion(o);
            play_sound(SOUND_GENERAL_WALL_EXPLOSION, gGlobalSoundSource);
            spawn_mist_particles_variable(0, 0, 100.0f);
            spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
        }
    }
}