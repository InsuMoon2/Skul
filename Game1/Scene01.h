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
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

