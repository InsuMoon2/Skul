#pragma once

class Scene04 : public Scene
{
private:
	Player*		pl;
	Yggdrasil*  boss;

	ObRect*		ground_Col[3];
	ObImage*	ground;

	ObImage*	boss_Start;
	ObImage*	boss_anger;
	ObImage*	boss_End;

	Vector2		lastPos;

	Vector2		ball_lastPos;
	Vector2		ground_lastPos;

	Vector2		getHand;

	//Slam
	Vector2		slam_Location;
	Vector2		slam_Location_Reverse;

	Vector2		slam_Location1;
	Vector2		slam_Location_Reverse2;

	Vector2		slam_LastPos;
	Vector2		slam_LastPos_ReVerse;

	//Slam
	ObImage*	slam_Effect;
	bool		slam_effect_checking = false;
	Vector2		slam_location_Ch;

	bool		slam_Checking = false;
	bool		slam_Checking_Re = false;
	bool		slam = false;

	float		slam_finish = 0.0f;

	float		slam_InterTime = 0.0f;
	float		slam_InterTime2 = 0.0f;

	//Sweep
	bool		sweep_Checking = false;

	//Ball
	Vector2		ball_Dis;
	bool		ball_Checking = false;

	float		ballex_Time = 0.0f;
	bool		ballex_Checking = false;

	float		groggy_Cehck2 = 0.0f;

	int			tw = 20;
	int			sw = 30;

public:


public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

