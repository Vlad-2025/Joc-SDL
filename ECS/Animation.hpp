#pragma once

struct Animation {

	int index;	// indice cadru din animatie
	int frames;	// nr cadre ale animatiei
	int speed;

	Animation() {
		index	= 0;
		frames	= 0;
		speed	= 0;
	}
	Animation(int i, int f, int s) {

		index	= i;
		frames	= f;
		speed	= s;
	}
};