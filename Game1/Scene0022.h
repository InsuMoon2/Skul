#pragma once

class Scene0022 : public Scene
{
private:
	//플레이어
	Player*	 pl;

	//Witch
	Witch*	 witch;

	//Knight
	Knight*  knight[2];
	ObImage* enemy_Icon;

	ObImage* background;
	ObImage* tutorial_Bg;
	ObRect*	 ground;

	//Cage
	ObRect*  cage_Col;
	ObImage* cage_Front;
	ObImage* cage_Behind;
	ObImage* cage_Front_Dis;
	ObImage* cage_Behind_Dis;

	int		 cage_Count = 4;
	int		 monster_count = 2;
	float	 cage_hitTime = 0.3f;

	bool	 cage_timeCheck = false;
	bool	 knight_Check = false;

	float timeDelta = 0.0f;
	
	
	Vector2	 lastPos;

	bool	 hit_Check = false;

	//Open the Door
	ObImage* gate_Normal;
	ObImage* gate_Close;
	ObRect*	 gate_Rect;
	ObRect*	 gate_Open;
	ObImage* input;

	Vector2	 cat_dis;
	float	 distance;

	//text
	ObImage* text;
	ObImage* next;
	bool	 textCheck = false;
	float	 text_Time = 0.0f;
	int		 number = 0;

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;

	void Hit();
};

