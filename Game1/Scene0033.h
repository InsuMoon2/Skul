#pragma once

class Scene0033 : public Scene
{
private:
	//플레이어
	Player* pl;
	//Guard*  guard;

	//Witch
	Witch*   witch;
	Vector2	 cat_dis;
	float	 distance;

	//배경
	ObImage* background;
	ObImage* tutorial_Bg;
	ObRect*  ground;

	//Guard
	ObImage* guard_Head;
	ObImage* guard_Head_Change;
	ObImage* thunder;
	
	//Gate
	ObImage* gate_Normal;
	ObRect*  gate_Rect;
	ObImage* input;

	bool	 guard_Check = false;


public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

