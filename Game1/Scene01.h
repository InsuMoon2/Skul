#pragma once

class Scene01 : public Scene
{
private:
	Player*			character;
	DevilCastle*	Devil;

	ObRect*			test;
	ObRect*			block[6];

public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

