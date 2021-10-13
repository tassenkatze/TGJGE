#include <TGJGE.h>


int main()
{
	TG_init("test window", 1920, 1080, true, 60);

	TG_texture *crate_tex=TG_new_texture("assets/crate.bmp", false);
	TG_object *crate[10];
	for(int i=0; i<10; i++)
	{
		crate[i]=TG_new_object(0.1,0.178,(float)i/10,0.322, 1);
		TG_use_texture_object(crate[i], crate_tex);
	}

	//animation test
	TG_texture *fire_tex=TG_new_texture("assets/flame.png", false);
	TG_object *fire_obj=TG_new_object(0.058, 0.1, 0.1, 0.5, 3);
	TG_object *fire_obj2=TG_new_object(0.058, 0.1, 0.85, 0.5, 3);
	TG_use_texture_object(fire_obj, fire_tex);
	TG_use_texture_object(fire_obj2, fire_tex);

	TG_start_animation_object(fire_obj, 1, 3, 500, true);
	TG_start_animation_object(fire_obj2, 1, 3, 500, true);

	float x=0,y=0;
	TG_object *mouse=TG_new_object(0.058, 0.1, x, y, 3);
	TG_use_texture_object(mouse, fire_tex);
	TG_start_animation_object(mouse, 1, 3, 500, true);

	while(!TG_is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		if(TG_mouse_is_left_pressed())
		{
			printf("left\n");
		}
		if(TG_mouse_is_right_pressed())
		{
			printf("right\n");
		}
		TG_mouse_position(&x, &y);
		TG_set_position_object(mouse, x, y);
		for(int i=0; i<10; i++)
		{
			TG_render_object(crate[i]);
		}
		TG_render_object(fire_obj);
		TG_render_object(fire_obj2);
		TG_render_object(mouse);
		TG_flip(0.1,0.0,0);
	}


	TG_destroy_texture(fire_tex);
	TG_destroy_texture(crate_tex);
	TG_destroy_object(fire_obj);
	TG_destroy_object(fire_obj2);
	TG_quit();
	return 0;
}