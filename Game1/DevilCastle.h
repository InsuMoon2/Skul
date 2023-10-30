#pragma once
class DevilCastle
{
private:
	ObImage*	devil_Castle;
	ObImage*	witch;
	ObImage*	fox;
	ObImage*	ogre;

	int a = 5;
	int b;

public:

public:
	DevilCastle();
	~DevilCastle();

	void Update();
	void Render();

	void Invisible()
	{
		witch->visible = false;
		fox->visible = false;
		ogre->visible = false;
	}
};

