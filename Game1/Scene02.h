#pragma once

class Scene02 : public Scene
{
private:
	Player*		pl;

	ObImage*	bg;
	ObImage*	gate_Wall;
	ObImage*	gate_Normal;
	ObImage*	input;

	ObRect*		gate_Rect;
	ObRect*		rectGround;

public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

