#pragma once

class Scene0011 : public Scene
{
private:
	Player*  pl;

	ObImage* background;

	ObImage* tutorial_Bg;
	ObRect*  ground;
	ObRect*  jump_ground[3];
	ObRect*  LR_ground[2];

	ObImage* gate_Normal;
	ObRect*  gate_Rect;
	ObImage* input;

	//스켈레통
	ObRect*  tong_Col;
	ObImage* tong_Idle;
	ObImage* tong_Move;

	//무기 주는애
	ObRect*	 give_WeaponCol;
	ObImage* give_Weapon;
	ObRect*  give_Rect;
	bool	 give = false;
	bool	 give2 = false;

	//Text
	ObImage* text;
	ObImage* next;

	ObImage* left;
	ObImage* right;
	ObImage* down;
	ObImage* z;
	ObImage* x;
	ObImage* c;

	float	text_Time = 0.0f;
	int		number = 0;

	bool	fadeOut;
	float	fadeIn;

	bool	textCheck = false;

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

